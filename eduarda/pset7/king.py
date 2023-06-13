from collections import deque

def bfs(s, t):
    moves = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
    queue = deque()
    visited = set()
    moves_dict = {}

    queue.append(s)
    visited.add(s)

    while queue:
        current = queue.popleft()

        if current == t:
            break

        for move in moves:
            next_square = chr(ord(current[0]) + move[0]) + str(int(current[1]) + move[1])

            if 'a' <= next_square[0] <= 'h' and '1' <= next_square[1] <= '8' and next_square not in visited:
                queue.append(next_square)
                visited.add(next_square)
                moves_dict[next_square] = move

    path = []
    square = t
    while square != s:
        move = moves_dict[square]
        if move[0] == 0:
            vertical = 'U' if move[1] > 0 else 'D'
            path.append(vertical)
        else:
            horizontal = 'L' if move[0] > 0 else 'R'
            diagonal = 'U' if move[1] > 0 else 'D'
            path.append(horizontal + diagonal)
        square = chr(ord(square[0]) - move[0]) + str(int(square[1]) - move[1])

    return len(path), path[::-1]

# Test example
s = 'a8'
t = 'h1'
n, moves = bfs(s, t)
print(n)
for move in moves:
    print(move)