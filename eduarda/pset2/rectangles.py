from math import factorial

def comb(n):
    if n < 2:
        return 0
    comb = 0
    for i in range(2, n + 1):
        x = factorial(n) // (factorial(i) * factorial(n - i))
        comb += x
    return comb


if __name__ == "__main__":
    n_rows, n_cols = map(int, input().split())

    quadrado = [list(map(int, input().split())) for _ in range(n_rows)]

    row_sums = [sum(row) for row in quadrado]
    col_sums = [sum(col) for col in zip(*quadrado)]

    variations = n_rows * n_cols

    for i in range(n_rows + n_cols):
        if i < n_rows:
            x = n_cols - row_sums[i]
            y = row_sums[i]
        else:
            j = i - n_rows
            x = n_rows - col_sums[j]
            y = col_sums[j]

        variations += comb(x)
        variations += comb(y)

    print(variations)
