from queue import Queue

def menor_sequencia_teclas(painel):
    # Converte a entrada em uma lista de inteiros
    state = list(map(int, painel.split()))

    # Verifica se todas as luzes já estão acesas
    if sum(state) == 10:
        return 0, ''

    visited = set()
    q = Queue()
    q.put((state, '', 0))  # (estado atual, sequência de teclas pressionadas, tamanho da sequência)

    while not q.empty():
        current_state, sequence, size = q.get()

        # Verifica se todas as luzes estão acesas no estado atual
        if sum(current_state) == 10:
            return size, sequence

        # Tenta pressionar todas as teclas possíveis
        for key in range(1, 11):
            next_state = press_key(current_state, key)

            # Verifica se o próximo estado já foi visitado
            if tuple(next_state) not in visited:
                visited.add(tuple(next_state))
                q.put((next_state, sequence + str(key), size + 1))

    return -1, ''

def press_key(state, key):
    new_state = state.copy()
    new_state[key-1] = 1 - new_state[key-1]  # Inverte o estado da tecla pressionada

    # Verifica as teclas adjacentes e inverte o estado delas se necessário
    adjacent_keys = {
        1: [2, 5],
        2: [1, 3, 5, 6],
        3: [2, 4, 6, 7],
        4: [3, 7],
        5: [1, 2, 6, 8],
        6: [2, 3, 5, 7, 8, 9],
        7: [3, 4, 6, 9],
        8: [5, 6, 9, 10],
        9: [6, 7, 8, 10],
        10: [8, 9]
    }

    for adjacent_key in adjacent_keys[key]:
        new_state[adjacent_key-1] = 1 - new_state[adjacent_key-1]

    return new_state

# Entrada
painel = input()

# Chama a função para obter a menor sequência de teclas pressionadas
size, sequence = menor_sequencia_teclas(painel)

# Saída
print(size)
if size != -1:
    print(sequence)