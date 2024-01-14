from math import factorial


def seq_sum(x, n):
    s = 0
    coeff = 1

    for i in range(1, n+1):
        s += coeff * (x**(2*i-1)) / factorial(2*i-1)
        coeff *= -1

    return s

print(seq_sum(2, 2))