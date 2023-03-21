from math import factorial

i, j = map(int, input().split())
matrix = []
sets = i * j


def factorial_thing(instances):
    results = 0
    for n in range(2, instances + 1):
        results += int(factorial(instances) / (factorial(n) * factorial(instances - n)))
    return results


for _ in range(i):
    new = list(map(int, input().split()))
    white = new.count(0)
    black = new.count(1)
    if white > 1:
        sets += factorial_thing(white)
    if black > 1:
        sets += factorial_thing(black)
    matrix.append(new)

for column in range(j):
    black = 0
    white = 0
    for line in matrix:
        if line[column] == 0:
            white += 1
        else:
            black += 1
    if white > 1:
        sets += factorial_thing(white)
    if black > 1:
        sets += factorial_thing(black)

print(int(sets))
