function ePE = eval_PE(th_in)

    assignin('base', 'th_in', th_in)
    ePE = evalin('base', 'eval(subs(PE, th_vec, th_in))');

end