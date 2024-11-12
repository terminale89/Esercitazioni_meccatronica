function Rs = DH_to_Rot_mat(DH)

    % DH_line = [d th r al]
    n_joints = size(DH, 1);
    Rs = cell(n_joints, 1);
    current_R = eye(4);

    for i = 1:n_joints
        DH_line = DH{i};
        d = DH_line(1);
        th = DH_line(2);
        r = DH_line(3);
        al = DH_line(4);
        Rot_mat = [
                cos(th), -sin(th)*cos(al), sin(th)*sin(al), r*cos(th);
                sin(th), cos(th)*cos(al), -cos(th)*sin(al), r*sin(th);
                0, sin(al), cos(al), d;
                0, 0, 0, 1
            ];
        current_R = current_R * Rot_mat;
        Rs{i} = current_R;
    end

end