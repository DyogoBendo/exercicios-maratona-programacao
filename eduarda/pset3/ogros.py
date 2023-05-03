def binary_search(limits, valor):
    left, right = 0, len(limits) - 1
    while(left < right):
        mid = (left + right) // 2
        if(limits[mid] == valor):
            return mid
        elif(limits[mid] > valor):
            right = mid
        else:
            left = mid + 1
    return right

if __name__ == "__main__":
    n, m = map(int, input().split())
    limits = list(map(int, input().split()))
    points = list(map(int, input().split()))
    ogres = list(map(int, input().split()))

    result = []
    for ogre in ogres:
        value = binary_search(limits, ogre)
        if(ogre >= limits[value]):
            point = points[value+1]
            result.append(point)
        else:
            point = points[value]
            result.append(point)

    print(" ".join(list(map(str,result))))

    
