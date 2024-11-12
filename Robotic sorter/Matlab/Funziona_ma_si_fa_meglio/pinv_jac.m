function pinv_j = pinv_jac(th_in)

    assignin('base', 'th_in', th_in)
    pinv_j = pinv(evalin('base', 'eval(subs(J_PE, th_vec, th_in))'));

end