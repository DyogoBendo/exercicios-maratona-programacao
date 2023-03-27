from math import inf

num_squares = int(input())
row = list(map(int, input().split()))
base_squares = [i for i, square in enumerate(row) if square == 0]

current_base = 0
min_distances = []
for i in range(num_squares):
    current_distance = abs(base_squares[current_base] - i)
    next_distance = inf
    if current_base < len(base_squares) - 1:
        next_distance = abs(base_squares[current_base + 1] - i)
    if next_distance < current_distance:
        current_base += 1
        current_distance = next_distance
    min_distances.append(min(current_distance, 9))
print(" ".join(str(d) for d in min_distances))




