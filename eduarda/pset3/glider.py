def max_size(sequence, n, h):
    max_length = sequence[0][1] - sequence[0][0]
    answer = max_length
    height = last = 0

    for i in range(1, n):
        height += sequence[i][0] - sequence[i - 1][1]
        while(height >= h):
            height -= sequence[last + 1][0] - sequence[last][1]
            max_length -= sequence[last][1] - sequence[last][0]
            last += 1 
        max_length += sequence[i][1] - sequence[i][0]
        if answer < max_length:
            answer = max_length
    return answer + h

n, y = map(int, input().split())

sequence = []
for i in range(n):
    a, b = map(int, input().split())
    sequence.append((a, b))

x = max_size(sequence, n, y)
print(x)


    


        

    

 
