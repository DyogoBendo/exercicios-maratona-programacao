n, k = map(int, input().split())
integers = list(map(int, input().split()))

subset = set()
count = 0
for i in integers:
    if i in subset:
        count += 1
    else:
        x = i * k
        subset.add(x)

print(len(integers) - count)