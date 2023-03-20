size = int(input())
matrix = []
results = set()
d1_magic = 0
d2_magic = 0

for n in range(size):
    entry = list(map(int, input().split()))
    d1_magic += entry[n]
    d2_magic += entry[(n + 1) * -1]
    results.add(sum(entry))
    matrix.append(entry)
results.add(d1_magic)
results.add(d2_magic)

for n in range(size):
    vertical_magic = 0
    for line in matrix:
        vertical_magic += line[n]
    results.add(vertical_magic)

if len(results) == 1:
    print(d1_magic)
else:
    print(-1)
