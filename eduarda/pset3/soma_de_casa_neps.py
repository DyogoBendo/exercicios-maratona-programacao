n = int(input())

values = []
for i in range(n+1):
    value = int(input())
    values.append(value)

k = values[-1]
houses = values[:-1]

visited = {}
for i in range(len(houses)):
    complement = k - houses[i]
    if(complement in visited):
        vars = sorted([houses[i], complement])
        break
    visited[houses[i]] = i

for i in vars:
    print(i, end= ' ')



