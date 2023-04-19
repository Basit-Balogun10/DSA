#!/bin/python3

import math
import os
import random
import re
import sys
import ctypes

#
# Complete the 'dynamicArray' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY queries
#

def handle_query_1(x, y, n, arr, last_answer):
    print('HERE 1')
    index = (x ^ last_answer) % n
    print(index, arr, arr[1])
    arr[index].append(y)
    

def handle_query_2(x, y, n, arr, last_answer):
    index = (x ^ last_answer) % n
    return arr[index][y % len(arr[index])]

def dynamicArray(n, queries):
    arr = (n * ctypes.py_object)()
    for i in range(n):
        arr[i] = []
    last_answer = 0
    answers = []
    for query in queries:
        x, y = query[1], query[2]
        if query[0] == 1:
            handle_query_1(x, y, n, arr, last_answer)
        elif query[0] == 2:
            last_answer = handle_query_2(x, y, n, arr, last_answer)
            answers.append(last_answer)
            
    return answers

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    result = dynamicArray(n, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

# https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true