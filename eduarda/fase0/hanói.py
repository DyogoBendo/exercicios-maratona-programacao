from collections import deque

def initialize_game():
    # Define a configuração inicial do jogo (C1) e a configuração final (C2)
    C1 = [[2], [1], []]
    C2 = [[1], [2], []]
    return C1, C2

def generate_next_configurations(current_config):
    # Gera todas as configurações possíveis a partir do nó atual
    next_configurations = []
    for i in range(3):
        for j in range(3):
            if i != j:
                if len(current_config[i]) > 0:
                    next_config = [list(tower) for tower in current_config]
                    disk = next_config[i].pop()
                    next_config[j].append(disk)
                    next_configurations.append(next_config)
    return next_configurations

def bfs(C1, C2):
    queue = deque()
    queue.append(C1)

    visited = set()
    visited.add(tuple(map(tuple, C1)))

    min_moves = {}
    min_moves[tuple(map(tuple, C1))] = 0

    while queue:
        current_config = queue.popleft()
        
        if current_config == C2:
            return min_moves[tuple(map(tuple, current_config))]
        
        next_configurations = generate_next_configurations(current_config)
        for next_config in next_configurations:
            if tuple(map(tuple, next_config)) not in visited:
                visited.add(tuple(map(tuple, next_config)))
                queue.append(next_config)
                min_moves[tuple(map(tuple, next_config))] = min_moves[tuple(map(tuple, current_config))] + 1
    
    return -1

# Testando a implementação
C1, C2 = initialize_game()
min_moves = bfs(C1, C2)
if min_moves == -1:
    print("Não é possível chegar à configuração final.")
else:
    print(f"Número mínimo de movimentos para chegar a C2: {min_moves}")