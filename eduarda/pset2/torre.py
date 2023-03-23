n = int(input())

square = []
columns = []
rows = []
for i in range(n):
    values = list(map(int, input().split()))
    square.append(values)

max_sum = 0

for i in range(n):
    value = 0
    rows.append(sum(square[i]))
    for j in range(n):
        value += square[j][i]
    columns.append(value)
        
for i in range(n):
    for j in range(n):
        x = rows[i] + columns[j] - square[i][j]*2
        if(x > max_sum):
            max_sum = x

print(max_sum)