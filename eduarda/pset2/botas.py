
n = int(input())

b = []
s = set()
p = 0
for i in range(n):
    boots = input()
    s.add(boots.split()[0])
    b.append(boots)

for size in s:
    p += min(b.count(f'{size} E'), b.count(f'{size} D'))

print(p)


    