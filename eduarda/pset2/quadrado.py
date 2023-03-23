n = int(input())

quadrado = []
for i in range(n):
    linha = input()
    values = linha.split()
    values_int = [int(value) for value in values]
    quadrado.append(values_int)

soma = sum(quadrado[0])

isQuadrado = True
for row in quadrado:
    if sum(row) != soma:
        isQuadrado = False
        break

for j in range(n):
    soma_coluna = 0
    for i in range(n):
        soma_coluna += quadrado[i][j]
    if soma_coluna != soma:
        isQuadrado = False
        break

diagonal_principal = sum(quadrado[i][i] for i in range(n))
diagonal_secundaria = sum(quadrado[i][n-i-1] for i in range(n))
if diagonal_principal != soma or diagonal_secundaria != soma:
    isQuadrado = False

# Imprime o resultado
if isQuadrado:
    print(soma)
else:
    print(-1)


