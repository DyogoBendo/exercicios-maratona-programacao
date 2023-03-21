size = int(input())
matrix = []
lines = []
columns = []
biggest = 0
for _ in range(size):
    new = list(map(int, input().split()))
    lines.append(sum(new))
    matrix.append(new)

for column in range(size):
    value = 0
    for n in range(size):
        value += matrix[n][column]
    columns.append(value)

for i in range(size):
    for j in range(size):
        temp = lines[i] + columns[j] - matrix[i][j]*2
        if temp > biggest:
            biggest = temp
print(biggest)
