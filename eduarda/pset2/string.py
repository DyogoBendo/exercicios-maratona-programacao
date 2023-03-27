n, k = map(int, input().split())
string = input()

lista = []
current = ''
for letter in string:
    if letter != current:
        current = letter
        lista.append(1)
    else:
        lista[-1] += 1

print(lista)
