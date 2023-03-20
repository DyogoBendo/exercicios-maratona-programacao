size = int(input())
answer = []
for _ in range(size):
    # eu podia ter feito somente "input()[-1]"
    phrase = input().split('_')[-1][-1]
    if phrase == 'o':
        answer.append('FILIPINO')
    elif phrase == 'u':
        answer.append('JAPANESE')
    elif phrase == 'a':
        answer.append('KOREAN')

for language in answer:
    print(language)
