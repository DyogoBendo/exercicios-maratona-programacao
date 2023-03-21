from collections import Counter
capacity = int(input())*2
needed = Counter()
result = 'YES'
for _ in range(4):
    for n in input().replace('.', ''):
        needed[n] = needed.get(n, 0) + 1
for n in needed.values():
    if n > capacity:
        result = 'NO'
print(result)
