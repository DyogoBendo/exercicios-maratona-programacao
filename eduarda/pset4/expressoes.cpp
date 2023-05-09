#save the last expression
#the next expression should be one that'll close itself


n = int(input())

arr = []
for _ in range(n):
    string = input()
    arr.append(string)

expressions = []
for i in arr:
    expressions = i.split()
    