countries, modalities = map(int, input().split())

scores = {}
for i in range(countries):
    scores[i+1] = [0, 0, 0]

for i in range(modalities):
    o, p, b = map(int, input().split())
    scores[o][0] += 1
    scores[p][1] += 1
    scores[b][2] += 1

sorted_scores = sorted(scores.items(), key=lambda x: (-x[1][0], -x[1][1], -x[1][2], x[0]))

for i in range(countries):
    print(sorted_scores[i][0], end=" ")
    

