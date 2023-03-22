days = int(input())

y = days / 365
remainder_y = days % 365
m = remainder_y / 30
remainder_m = remainder_y % 30
d = remainder_m % 30

print(int(y), int(m), int(d))