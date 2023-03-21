results = []
while True:
    n, b = map(int, input().split())
    if n == 0 and b == 0:
        break
    bolas = list(map(int, input().split()))
    nums = set(a for a in range(n+1))
    possibilidades = set()
    for _ in range(len(bolas)):
        for i in range(len(bolas)):
            possibilidades.add(abs(bolas[-1]-bolas[i]))
        bolas.pop()
    if possibilidades == nums:
        results.append('Y')
    else:
        results.append('N')

for result in results:
    print(result)
