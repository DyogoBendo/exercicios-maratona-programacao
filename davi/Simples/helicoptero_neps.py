def main():
    heli, policial, fugitivo, direcao = map(int, input().split())
    distancia_pol = policial - fugitivo
    distancia_heli = heli - fugitivo
    if direcao == -1:
        distancia_pol = distancia_pol*-1
        distancia_heli = distancia_heli*-1
    if distancia_pol < 0:
        distancia_pol = distancia_pol + 16
    if distancia_heli < 0:
        distancia_heli = distancia_heli + 16
    if distancia_heli < distancia_pol:
        print('S')
    else:
        print('N')


if __name__ == "__main__":
    main()
