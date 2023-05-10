from collections import Counter

n = int(input())

values = []
for _ in range(n):
    value = int(input())
    values.append(value)

new_values = Counter(values)

most_common = new_values(1)[0][0]

print(most_common)