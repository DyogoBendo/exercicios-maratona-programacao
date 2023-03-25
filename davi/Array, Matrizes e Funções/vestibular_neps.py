def main():
    lenght = int(input())
    gabarito = input()
    respostas = input()
    points = 0

    for n in range(lenght):
        if gabarito[n] == respostas[n]:
            points += 1

    print(points)


if __name__ == "__main__":
    main()
