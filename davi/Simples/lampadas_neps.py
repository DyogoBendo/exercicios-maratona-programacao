def main():
    n = int(input())
    switchs = list(map(int, input().split()))
    I2 = switchs.count(2)
    if len(switchs) % 2 == 0:
        print(0)
    else:
        print(1)
    if I2 % 2 == 0:
        print(0)
    else:
        print(1)


if __name__ == "__main__":
    main()

