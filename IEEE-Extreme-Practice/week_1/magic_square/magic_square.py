count = 0
square = []
with open('input.txt') as fp:
    while True:
        file_line = fp.readline()
        if not file_line:
            break
        if count == 0:
            count += 1
            no_of_rows = int(file_line)
        else:
            square.append(list(file_line.strip().split(' ')))

def sum_main_diagonal(square):
    diagonal_sum = 0
    for index, line in enumerate(square):
        diagonal_sum += int(line[index])

    return diagonal_sum

DIAGONAL_SUM = sum_main_diagonal(square)
LINES_WITH_DIFF_SUMS = []

def check_rows_sum(square):
    line_sum = 0
    for index, line in enumerate(square):
        line_sum += sum(line)
    if line_sum != DIAGONAL_SUM:
        LINES_WITH_DIFF_SUMS.append(index + 1)
        
def check_columns_sum(square):
    line_sum = 0
    for line in square:
        line_sum += line[0]
    if line_sum != DIAGONAL_SUM:
        LINES_WITH_DIFF_SUMS.append((index + 1) * -1)

def check_antidiagonal_sum(square):
    antidiagoanal_sum = 0
    for index, line in enumerate(square):
        line_sum += int(line[len(square) - index])
    if line_sum != DIAGONAL_SUM:
        LINES_WITH_DIFF_SUMS.append(0)

check_rows_sum(square)
check_columns_sum(square)
check_antidiagonal_sum(square)
LINES_WITH_DIFF_SUMS.sort()

print(len(LINES_WITH_DIFF_SUMS), LINES_WITH_DIFF_SUMS, end="\n")