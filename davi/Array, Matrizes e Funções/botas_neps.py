items = int(input())
boots = []
sizes = set()
pairs = 0
for _ in range(items):
    boot = input()
    sizes.add(boot.split()[0])
    boots.append(boot)

for size in sizes:
    pairs += min(boots.count(f'{size} E'), boots.count(f'{size} D'))

print(pairs)
