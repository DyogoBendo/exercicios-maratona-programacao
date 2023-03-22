while True:
    n = int(input())
    if n == 0:
        break
    
    x = 0
    y = 1
    t = 0
    for i in range (n, 0, -1):
        t= x + y
        x = y
        y = t
    print(t)