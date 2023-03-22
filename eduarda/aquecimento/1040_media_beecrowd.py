notas = input()
notas_list = notas.split(' ')
notas_list = [float(num) for num in notas_list]
media = sum(notas_list)/4

def result(valor):
    if(valor < 5.0):
        print(f"Media: {valor:.1f}\n Aluno reprovado")
    else:
        print(f"Media: {valor:.1f}\n Aluno aprovado")


if(media > 5.0 and media < 6.9):
    print('Aluno em exame')
    nota = float(input('Nota do exame:'))
    nova_media = (media + nota)/2
    result(nova_media)
else:
    result(media)


