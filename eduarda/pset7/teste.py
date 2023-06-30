from collections import deque

def bfs(graph, start, end):
    queue = deque([(start, [])])
    visited = set()

    while queue:
        node, path = queue.popleft()

        if node == end:
            return path

        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                queue.append((neighbor, path + [neighbor]))

    return None

def paint_castles(N, M, roads, orders):
    # Criar o grafo a partir das estradas
    graph = {i: [] for i in range(1, N + 1)}
    for road in roads:
        u, v = road
        graph[u].append(v)
        graph[v].append(u)

    # Inicializar os castelos com a cor zero
    colors = [0] * N

    # Aplicar as ordens de pintura em sequência
    for order in orders:
        p, q, c = order
        path = bfs(graph, p, q)

        if path:
            for castle in path:
                colors[castle - 1] = c

    return colors

# Ler a entrada
N, M = map(int, input().split())
roads = [list(map(int, input().split())) for _ in range(N - 1)]
orders = [list(map(int, input().split())) for _ in range(M)]

# Chamar a função para pintar os castelos
result = paint_castles(N, M, roads, orders)

# Imprimir o resultado
print(*result)