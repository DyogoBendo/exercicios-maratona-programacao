def max_beauty(str, ltr, k, n):
    start = max_len = window_len = changes = 0
    for end in range(n):
        if str[end] == ltr:
            changes+=1
        while(changes > k):
            if str[start-1] == ltr:
                changes -= 1
            start+=1
        window_len = end - (start - 1)
        max_len = max(max_len, window_len)
    return max_len


n, k = map(int, input().split())
s = input()

result = max(max_beauty(s, 'a', k, n),max_beauty(s, 'b', k, n))

print(result)



