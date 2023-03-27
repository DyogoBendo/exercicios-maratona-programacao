number = input()

lucky_quantity = 0
for n in number:
    n = int(n)
    if(n == 4 or n == 7):
       lucky_quantity += 1
    

if(lucky_quantity == 4 or lucky_quantity == 7):
    print('YES')
else:
    print('NO')