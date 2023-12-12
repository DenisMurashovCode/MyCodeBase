
import cmath
import math


def fft(input):
    n = len(input)

    if n <= 1:
        return input

    even = fft(input[::2])
    odd = fft(input[1::2])

    output = [0] * n
    for k in range(n // 2):
        t = cmath.exp(-2j * cmath.pi * k / n) * odd[k]
        output[k] = even[k] + t
        output[k + n // 2] = even[k] - t

    return output


def ifft(input):
    N = len(input)
    if N <= 1:
        return input
    even = ifft(input[0::2])
    odd = ifft(input[1::2])
    T = [0] * N
    for k in range(N // 2):
        factor = cmath.exp(2j * cmath.pi * k / N)
        T[k] = even[k] + factor * odd[k]
        T[k + N // 2] = even[k] - factor * odd[k]
    return T

input = [1, 2, 3, 4, 5]
result = fft(input)
result1 = ifft(result)

print(result)
print(result1)




