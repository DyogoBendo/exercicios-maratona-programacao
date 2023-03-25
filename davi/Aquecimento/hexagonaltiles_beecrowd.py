inputs = [int(input())]
while inputs[-1] != 0:
    inputs.append(int(input()))
else:
    inputs.pop()
max_n = max(inputs)
fib = [0, 1]
for _ in range(max_n):
    fib.append(fib[-1] + fib[-2])
for n in inputs: print(fib[n+1])
