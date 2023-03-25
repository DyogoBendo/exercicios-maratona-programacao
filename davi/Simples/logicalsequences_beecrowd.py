inputs = input().split()
x = int(inputs[0])
y = int(inputs[1])

numbers = []
for n in range(1, y + 1):
    numbers.append(str(n))
    if n % x == 0:
        print(' '.join(numbers))
        numbers = []
