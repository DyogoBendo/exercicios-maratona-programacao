#objective: find two numbers that summed equals a number n 

n = int(input())
list = list(map(int, input().split()))

i, j  = 0, len(list) - 1
size = len(list)
while(i!=j):
    if((list[i]+list[j]) > n):
        j-=1
    elif(list[i]+list[j]) < n:
        i+=1
    else:
        print('found')
        break