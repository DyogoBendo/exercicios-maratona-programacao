strength, n = map(int, input().split())

result = 'YES'
dragon_strength = []
power_up = {}
for _ in range(n):
    s, p = map(int, input().split())
    dragon_strength.append(s)
    power_up[s] = p

dragon_strength.sort()


for i in range(n):
    value = dragon_strength[i]
    if(strength > value):
        strength += power_up[value]
    else:
        result = 'NO'

print(result)