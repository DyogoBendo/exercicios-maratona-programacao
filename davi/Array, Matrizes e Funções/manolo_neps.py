size = int(input())
farm = []
colheita = 0
for _ in range(size):
    farm.append(list(map(int, input().split())))

operations = int(input())
for _ in range(operations):
    primeira_linha, primeira_coluna, linha_final, coluna_final = map(int, input().split())
    for linha in range(primeira_linha-1, linha_final):
        for coluna in range(primeira_coluna-1, coluna_final):
            colheita += farm[linha][coluna]
            farm[linha][coluna] = 0

print(colheita)
