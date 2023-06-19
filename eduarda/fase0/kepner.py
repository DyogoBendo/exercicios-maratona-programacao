import math

def backtrack_sum_of_four_powers(n):
    def backtrack(curr_sum, num_quarts, start):
        if curr_sum == n and num_quarts == 4:
            return True
        if curr_sum > n or num_quarts > 4:
            return False

        for i in range(start, int(math.pow(n, 1/4)) + 1):
            if backtrack(curr_sum + math.pow(i, 4), num_quarts + 1, i):
                return True

        return False

    return backtrack(0, 0, 0)

# Exemplo de uso
number = 2107360834
result = backtrack_sum_of_four_powers(number)

if result:
    print(f"O número {number} pode ser expresso como a soma de quatro quartas potências.")
else:
    print(f"O número {number} não pode ser expresso como a soma de quatro quartas potências.")