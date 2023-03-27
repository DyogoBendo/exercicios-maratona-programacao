numeros = input()
numeros_list = numeros.split(' ')

maior = 0

for num in numeros_list:
    if(float(num) > maior):
        maior = float(num)

print(int(maior))