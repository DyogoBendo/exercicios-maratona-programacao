n = int(input())

square = []
for i in range(n):
    linha = input()
    values = linha.split()
    values_int = [int(value) for value in values]
    square.append(values_int)

sum = 0
c = int(input())
for i in range(c):
    xi, yi, xf, yf = map(int, input().split())

    for i in range(xi-1, xf):
        for j in range(yi-1, yf):
            sum += square[i][j]
            square[i][j] = 0

print(sum)



