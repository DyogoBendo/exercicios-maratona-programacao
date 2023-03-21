risada = input()
normal = []
for letter in risada:
    if letter in ['a', 'e', 'i', 'o', 'u']:
        normal.append(letter)
inverso = normal[::-1]

if normal == inverso:
    print('S')
else:
    print('N')
