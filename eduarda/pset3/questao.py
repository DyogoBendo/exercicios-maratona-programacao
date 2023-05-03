
def solving_function(list, n):
    new_list = [value for value in list if value > n]
    count = len(new_list)
    return count

n = int(input())
sequence = []
count = 0
for i in range(n):
    values = input().split()
    [sequence.append(int(value)) for value in values]

for value in sequence:
    temp = sequence
    temp.remove(value)
    count += solving_function(temp, value)


print(count)

