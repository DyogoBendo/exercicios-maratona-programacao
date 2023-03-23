fingers = int(input())*2

value = [0 for i in range(0, 9)]
result = 'YES'
for i in range(4):
    for j in input().replace('.', ''):
        value[int(j) - 1] += 1
       
for i in value:
    if(i > fingers):
        result = 'NO'
        break

print(result)
