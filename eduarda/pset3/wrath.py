n = int(input())

claw_lengths = list(map(int, input().split()))
claw_lengths.reverse()
count = 0
to_kill = 0

for i in claw_lengths:
    if to_kill <= 0:
        count +=1
    to_kill -= 1
    to_kill = max(to_kill, i)

print(count)
