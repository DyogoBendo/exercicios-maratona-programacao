n = input()


def lucky_number(num):
    for digit in num:
        if digit not in ['4', '7']:
            return False
    return True


sub_n = n.count('4') + n.count('7')
if lucky_number(str(sub_n)):
    print('YES')
else:
    print('NO')
