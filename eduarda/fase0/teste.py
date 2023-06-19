from collections import deque

def press_buttons(initial_state):
    # Dicionário que mapeia as teclas às suas vizinhas
    neighbors = {
        1: [2, 5],
        2: [1, 3, 5],
        3: [2, 4, 5, 6],
        4: [3, 6],
        5: [1, 2, 3, 7],
        6: [3, 4, 7, 8],
        7: [5, 6, 9],
        8: [6, 9],
        9: [7, 8, 10],
        10: [9]
    }

    # Verifica se todas as luzes estão acesas
    def all_lights_on(state):
        return all(state)

    # Transforma a lista de estado em uma string para ser usada como chave no dicionário de visitados
    def state_to_string(state):
        return ''.join(str(bit) for bit in state)

    # Inicialização do BFS
    queue = deque([(initial_state, [])])  # fila de estados e sequências
    visited = set()  # conjunto de estados visitados

    while queue:
        state, sequence = queue.popleft()  # obtém o estado e a sequência atual da fila

        if all_lights_on(state):
            # Se todas as luzes estão acesas, retorna a sequência
            return len(sequence), ' '.join(str(button) for button in sequence)

        state_str = state_to_string(state)
        if state_str in visited:
            # Se o estado já foi visitado, pula para o próximo estado na fila
            continue

        visited.add(state_str)

        for button, state_bit in enumerate(state, start=1):
            # Para cada tecla, verifica se ela precisa ser pressionada
            if state_bit == 1:
                new_state = state[:]  # copia o estado atual
                for neighbor in neighbors[button]:
                    # Inverte o estado das teclas vizinhas
                    new_state[neighbor - 1] = 1 - new_state[neighbor - 1]
                queue.append((new_state, sequence + [button]))  # adiciona o novo estado à fila

    # Se não foi possível acender todas as luzes, retorna -1
    return -1


# Entrada de exemplo: 1 0 0 0 1 1 0 0 0 1
initial_state = list(map(int, input().split()))

# Chama a função press_buttons e imprime o resultado
min_sequence_length, lexicographically_min_sequence = press_buttons(initial_state)
print(min_sequence_length)
if min_sequence_length != -1:
    print(lexicographically_min_sequence)