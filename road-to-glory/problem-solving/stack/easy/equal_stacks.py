#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalStacks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h1
#  2. INTEGER_ARRAY h2
#  3. INTEGER_ARRAY h3
#

def equalStacks(h1, h2, h3):
    h1_sum, h2_sum, h3_sum = sum(h1), sum(h2), sum(h3)
    min_height = min(h1_sum, h2_sum, h3_sum)
    
    while not (h1_sum == h2_sum == h3_sum):
        while h1_sum > min_height:
            h1_sum -= h1[0]
            del h1[0]
        if h1_sum < min_height:
            min_height = h1_sum
            
        while h2_sum > min_height:
            h2_sum -= h2[0]
            del h2[0]
        if h2_sum < min_height:
            min_height = h2_sum
            
        while h3_sum > min_height:
            h3_sum -= h3[0]
            del h3[0]
        if h3_sum < min_height:
            min_height = h3_sum
    
    return min_height
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n1 = int(first_multiple_input[0])

    n2 = int(first_multiple_input[1])

    n3 = int(first_multiple_input[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    fptr.write(str(result) + '\n')

    fptr.close()
  
# https://www.hackerrank.com/challenges/equal-stacks/problem?isFullScreen=true