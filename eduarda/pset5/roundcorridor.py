import math

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

n, m, q = map(int, input().split())

for _ in range(q):
    sx, sy, ex, ey = map(int, input().split())

    if sx == ex:
        if sy == ey:
            print("NO")
        else:
            print("YES")
    else:
        if gcd(n, m) == 1 or gcd(sy, ey) == 1:
            print("YES")
        else:
            print("NO")