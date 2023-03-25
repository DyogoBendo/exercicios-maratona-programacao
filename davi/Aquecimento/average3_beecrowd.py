scores = list(map(float, input().split()))
scores[0] = scores[0]*2
scores[1] = scores[1]*3
scores[2] = scores[2]*4
scores[3] = scores[3]*1
average = round(sum(scores)/(2+3+4+1), 1)
print(f'Media: {average}')
if average >= 7:
    print('Aluno aprovado.')
elif average < 5:
    print('Aluno reprovado.')
else:
    print('Aluno em exame.')
    new_score = float(input())
    print(f'Nota do exame: {new_score}')
    average = (average + new_score)/2
    if average < 5:
        print('Aluno reprovado.')
    else:
        print('Aluno aprovado.')
    print(f'Media final: {average}')
