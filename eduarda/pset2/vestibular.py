quantity = int(input())
gabarito = list(input())
respostas = list(input())

acertos = 0
for i in range(quantity):
    if(gabarito[i] == respostas[i]):
        acertos +=1

print(acertos)