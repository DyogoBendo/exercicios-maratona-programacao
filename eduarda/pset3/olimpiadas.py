countries, modalities = map(int, input().split())

countries_list = [int(value) for value in range(countries)]
medals = {}

for i in range(modalities):
    values = input().split()
    for value in values:
        if value in countries_list:
            medals[value] += 1
