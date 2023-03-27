times = int(input())
interruptores = map(int, input().split())

a = False
b = False
for i in interruptores:
    if(i == 1):
        a = not a
    if(i == 2):
        b = not b
        a = not a
print(int(a))
print(int(b))