n = int(input())
claw_lengths = list(map(int, input().split()))
 
alive = [1] * n
for i in range(n-1, -1, -1):
    start = max(0, i - claw_lengths[i])
    end = i - 1
    for j in range(start, end+1):
        alive[j] = 0
 
count = sum(alive)
print(count)

#preciso consertar pq ta dando timeout