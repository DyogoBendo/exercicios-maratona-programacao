n = int(input())

languages = []
for i in range(n):
    word = input()
    last = word[-5:]
    if(last == 'mnida'):
        languages.append('KOREAN')
    elif(last[-4:] == 'masu' or last[-4:] == 'desu'):
        languages.append('JAPANESE')
    else:
        languages.append('FILIPINO')

for i in languages:
    print(i)