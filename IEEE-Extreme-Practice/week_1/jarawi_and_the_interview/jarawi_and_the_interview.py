count = 0
subsequence_strings  = []
with open('C:/Users/Basit/backend-projects/DSA/IEEE-Extreme-Practice/week_1/jarawi_and_the_interview/input.txt', 'r') as fp:
    for line in fp:
        if count == 0:
            count += 1
            given_string = line.strip()
        elif count == 1:
            count += 1
            num_of_queries = int(line.strip())
        else:
            subsequence_strings.append(line.strip())

subsequence_strings.reverse()
solutions = []
for query in range(num_of_queries):
    pointer = 0
    current_subsequence = subsequence_strings[query - 1]
    # print('cs1', current_subsequence)
    test_string = given_string
    # print('ts', test_string)
    subsequence_length = len(current_subsequence)
    prev_index = 0
    for char in current_subsequence:
        # print('ch', char)
        current_char = current_subsequence[pointer]
        if (current_char in test_string):
            if (given_string.index(current_char) >= prev_index) or (test_string.index(current_char) >= prev_index):
                current_subsequence = current_subsequence[:pointer] + current_subsequence[pointer + 1:]
                pointer -= 1
                prev_index = test_string.index(current_char)
                test_string = test_string[:prev_index] + test_string[prev_index + 1:]
                # print(current_subsequence)
                if not current_subsequence:
                    solutions.append(subsequence_length)
            else:
                solutions.append(1)
        else:
            current_subsequence = current_subsequence[1:]
            subsequence_length = len(current_subsequence)
            pointer = 0
            if len(current_subsequence) == 1:
                solutions.append(1)
        pointer += 1
        
        
for sol in solutions:
    print(sol)