n = int(input())

claw_lengths = list(map(int, input().split()))
count = 0
temp = 0

for i in range(n-1, -1, -1):
    if temp <= claw_lengths[i]:
        count += claw_lengths[i] - temp
        temp = claw_lengths[i]
    else:
        temp = temp - 1

print(n - count)