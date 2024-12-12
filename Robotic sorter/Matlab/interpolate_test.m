function [Target, EndTorsion, EndClosure, TargetAngle] = interpolate_test(points, time)

    % Ogni punto è una riga, con il tempo alla fine (matrice nx9)
    time_column = size(points, 2);
    n_rows = size(points, 1);
    if (time_column < 7)
        exp_points1 = [points zeros(n_rows, 7-time_column)];
    else
        exp_points1 = points;
    end
    if (n_rows == 1)
        exp_points2 = [exp_points1; (exp_points1+[0 0 0 0 0 0 1])];
    else
        exp_points2 = exp_points1;
    end
    time_instants = exp_points2(:, 7);
    points_at_time = exp_points2(:, 1:6);
    if (time <= time_instants(1, 1))
        point_q = points_at_time(1, :);
    elseif (time >= time_instants(length(time_instants)))
        point_q = points_at_time(length(time_instants), :);
    else
        point_q = interp1(time_instants, points_at_time, time);
    end
    Target = reshape(point_q(1:3), [3, 1]);
    TargetAngle = point_q(4);
    EndTorsion = point_q(5);
    EndClosure = point_q(6);