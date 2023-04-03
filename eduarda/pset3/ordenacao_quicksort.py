def quicksort(arr):
    if(len(arr)) <= 1:
        return arr
    
    first = arr[0]
    last = arr[-1]
    mid = arr[len(arr)//2]
    pivot = sorted([first, mid, last])[1]

    larger = []
    smaller = []
    equal = []

    for i in arr:
        if i < pivot:
            smaller.append(i)
        elif i > pivot: 
            larger.append(i)
        else:
            equal.append(i)
    
    return quicksort(smaller) + equal + quicksort(larger)


if __name__ == "__main__":
    n = int(input())
    lista = list(map(int, input().split()))

    lista = quicksort(lista)

    for i in lista:
        print(i, end = ' ')
