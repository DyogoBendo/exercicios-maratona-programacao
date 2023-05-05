from bisect import bisect_right

n = int(input())
minimum = []
maximum = []
hasAscent = [0 for _ in range(n)]
total = 0

for i in range(n):
    linha = list(map(int,input().split()))
    linha.pop(0)
    smallest = linha[0]
    biggest = smallest
    for element in linha:
        if element <= smallest:
            smallest = element
        else:
            hasAscent[i] = 1
            biggest = 99999999999999
            smallest = -1
        biggest = max(biggest, element)
    minimum.append(smallest)
    maximum.append(biggest)
maximum.sort()
for i in range(n):
    total += n - bisect_right(maximum, minimum[i])
print(total)
