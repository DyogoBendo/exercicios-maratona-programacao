size = int(input())
fita = list(map(int, input().split()))


def analisar_distancia(lista):
    i = 0
    temp = []
    for j in lista:
        if j != 0:
            i += 1
            if i < 9:
                temp.append(i)
            else:
                temp.append(9)
        else:
            for _ in range(i):
                temp.pop()
            temp2 = []
            for x in range(i+1):
                if x < 9:
                    temp2.append(x)
                else:
                    temp2.append(9)
            temp.extend(reversed(temp2))
            i = 0
    return temp


normal = analisar_distancia(fita)
reverse = analisar_distancia(reversed(fita))
reverse.reverse()

for n in range(size):
    fita[n] = str(min(normal[n], reverse[n]))
print(' '.join(fita))
