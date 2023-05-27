if __name__ == "__main__":
    n, m = map(int, input().split())

    vertices = [[] for _ in range(n)]    
    for _ in range(m):
        i, j = map(int, input().split())
        i -= 1
        j -= 1        
        vertices[i].append(j)
        vertices[j].append(i)
   
    painted = [False for _ in range(n)]
    groups = 0

    for i in range(n):
        if painted[i] == False:
            groups += 1
            pilha = [i]
            painted[i] = True
            while len(pilha) > 0:
                a = pilha.pop()
                painted[a] = True

                amigos = vertices[a]
               
                for ai in amigos:
                    if painted[ai] == False:
                        pilha.append(ai)
       
    print(groups)