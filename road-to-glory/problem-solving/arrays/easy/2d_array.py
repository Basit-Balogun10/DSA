#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_sum = 0
    for row in range(4):
        current_sum = 0
        for col in range(4):
            current_sum += arr[row][col]
            current_sum += arr[row][col + 1]
            current_sum += arr[row][col + 2]
            current_sum += arr[row + 1][col + 1]
            current_sum += arr[row + 2][col]
            current_sum += arr[row + 2][col + 1]
            current_sum += arr[row + 2][col + 2]
            print(arr[row][col], arr[row][col + 1], arr[row][col + 2], "\n ", arr[row + 1][col + 1], "\n", arr[row + 2][col], arr[row + 2][col + 1], arr[row + 2][col + 2], "\n")
            print(current_sum, "\n")
            
            if col == row == 0:
                max_sum = current_sum        
    
            if current_sum > max_sum:
                max_sum = current_sum
            current_sum = 0
            
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

# Hackerrank link: https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true