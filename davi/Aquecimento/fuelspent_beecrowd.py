consumption = 12
time = int(input())
speed = int(input())
distance = speed*time
spent = round(distance/consumption, 3)

print(format(spent, '.3f'))
