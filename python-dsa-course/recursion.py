# # SUM OF THE DIGITS IN A POSITIVE INTEGER USING RECURSION
# def sum_digits(n):
#     assert (n > 0) and int(n) == n, "n must a positive integer"
#     if (n / 10) < 1:
#         return n
#     else:
#         return int(n % 10) + sum_digits(int(n / 10))
    
#     print(sum_digits(0))


# # ----------------------------------------
# # POWER OF A NUMBER USING RECURSION
# def power(num, index):
#     assert (num >= 0) and (index >= 0)
#     if index == 0:
#         return 1
#     if index == 1:
#         return num
#     return num * (power(num, index - 1))

# print(power(4, 0))

# # -----------------------------------------
# # GREATEST COMMON DIVISOR (GCD) OF TWO NUMBERS
# def find_GCD(num1, num2):
#     assert int(num1) == num1 and int(num2) == num2, "Both numbers must be positive integers"
#     # ???? METHOD 1 !!!!!!!!!! 
#     # if num1 % num2 == 0 or num2 % num1 == 0:
#     #     return min(num1, num2)
#     # return find_GCD(num1, (abs(num1 - num2)))
    
#     # ************* METHOD 2 ***********
#     # if num1 < 0:
#     #     num1 *= -1
#     # if num2 < 0:
#     #     num2 *= -1
#     # if num1 == 0:
#     #     return num2
#     # if num2 == 0:
#     #     return num1
#     # bigger, smaller = max(num1, num2), min(num1, num2)
#     # return find_GCD(bigger - smaller, smaller)


#     # ********RECOMMENDED SOLUTION**********
#     if num1 < 0:
#         num1 *= -1
#     if num2 < 0:
#         num2 *= -1
#     if num2 == 0:
#         return num1
#     else:
#         return find_GCD(num2, num1%num2)
    
    
# print(find_GCD(18, -48))

ml = []
def to_binary(num):
    print(num, num % 2)
    if num == 1:
        ml.append('1')
        ml.reverse()
        return ''.join(ml)
    else:
        ml.append(str(num % 2))
        return to_binary(int(num / 2))
    
print(to_binary(4))