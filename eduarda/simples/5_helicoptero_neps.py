h, p, f, t = map(int, input().split())

while( f != h and f != p):
    f = (f + t)%16

if( f == h):
    print('S')
else:
    print('N')