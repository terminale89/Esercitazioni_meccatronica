delta = pi / 2;
x = (4 * sin ( (0*pi) + delta)) + 8;     % Cordinata X figura di  Lissajous
y = (4 * sin(2*(0*pi))) + 8;             % Cordinata Y figura di  Lissajous
a = 10;
c = sqrt(x^2 + y^2);                    % Modulo vettore posizione
gamma = atan (y / x);                   % Angolo tra vettore posizione e asse X
alpha = acos (c / (2 * a));             % Teorema delle proiezioni
servo1 = ((alpha + gamma) / pi);        % Calcolo angolo servo braccio
servo2 = ((pi - 2 * alpha) / pi);       % Calcolo angolo servo avambraccio
dc_1 = ((servo1) * 0.1)+0.025;          % Calcolo duty cycle servo braccio
dc_2 = ((servo2) * 0.1)+0.025;          % Calcolo duty cycle servo avambraccio
% Test modello
xa = - 10 * sin (pi * (servo1 - 0.5));
ya = 10 * cos (pi * (servo1 - 0.5));
xb = 10 * sin (pi * (servo2 + servo1 - 0.5));
yb = -10 * cos (pi * (servo2 + servo1 - 0.5));
xtest = xa + xb
ytest = ya + yb