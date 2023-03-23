consonants = 'bcdfghjklmnpqrstvwxyz'

word = input()
laugh = ''.join([char for char in word if char not in consonants])

if(laugh!= laugh[::-1]):
    print('N')
else:
    print('S')