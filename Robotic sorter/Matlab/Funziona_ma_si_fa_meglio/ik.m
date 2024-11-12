function [th1, th2, th3, th4] = ik(pos3D, th_e)

    L1 = 1;
    L2 = 1;
    L3 = 1;
    L4 = 1;

% Sposto tutto su un piano: calcolo th1

    alfa = atan2(pos3D(2), pos3D(1));
    th1 = alfa;

% Ruoto pos3D per ottenere le cordinate nel piano

    pos2D = [sqrt(pos3D(1)^2+pos3D(2)^2); pos3D(3)];

% Ottieni coordinate del penultimo giunto dall'orientazione dell'ultimo

    q1 = pos2D(1) - L4*sin(th_e);
    q2 = pos2D(2) - L4*cos(th_e) - L1;

% Ora è uno Scara

    th3 = acos((-L2^2-L3^2+q1^2+q2^2)/(2*L2*L3));
    th2 = -atan2(q2, q1) + acos((L3*sin(th3)/sqrt(q1^2+q2^2)));

% Calcola ultimo angolo

    th4 = th_e - th2 - th3;

    th_vec = [th1, th2, th3, th4];
    th_vec = th_vec * 180/pi;

% Converti agli angoli dei motori
    th_vec = [30, 90, 100, 100] + [th_vec(1), -th_vec(2:4)];

    th_vec = rem(th_vec+360, 360);
    th_vec = th_vec.*(th_vec<=180)+(th_vec-360).*(th_vec>180);
    th1 = th_vec(1);
    th2 = th_vec(2);
    th3 = th_vec(3);
    th4 = th_vec(4);

end