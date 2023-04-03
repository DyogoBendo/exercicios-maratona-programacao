
def simple_func(list):
    var = max(list[0], list[-1])
    
    list.remove(var)
    return var, list



n = int(input())
list = list(map(int, input().split()))
start = end = sereja = dima = turn = 0

while(len(list) != 0):
    if(turn%2 == 0):
        values = simple_func(list)
        sereja += values[0]
        list = values[1]
        turn +=1
    else:
        values = simple_func(list)
        dima += values[0]
        list = values[1]
        turn +=1
    
print(sereja, dima)
