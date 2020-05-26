function z = xlogx(x)
    z = ones(size(x));
    for i = 1:size(x)
        z(i) = x(i)*log(x(i));
    end
end