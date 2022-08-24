with open('C:/Users/Basit/backend-projects/DSA/IEEE-Extreme-Practice/unilag_practice_round/fibonacci/input.txt', 'r') as fp:
    lines = fp.readlines()


def get_fibonacci_term(n):
    if (n == 1) or (n == 2):
        return n
    else:
        return get_fibonacci_term(n-1) + get_fibonacci_term(n-2)


current_line = 0
while current_line < len(lines):
    if current_line == 0:
        number_of_testcases = int(lines[current_line].strip())
    else:
        case = int(lines[current_line].strip())
        humans_population = get_fibonacci_term(case)
        survivors = humans_population % 10
        print(survivors)
    current_line += 1
