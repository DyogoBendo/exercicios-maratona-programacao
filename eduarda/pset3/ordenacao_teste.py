
#bubble sort
n = int(input())
seq = list(map(int, input().split()))

seq.sort()


for i in seq:
    print(i, end =' ')