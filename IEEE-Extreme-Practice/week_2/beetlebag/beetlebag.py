current_number_of_gadgets = 0
testcases = {}
with open('C:/Users/Basit/backend-projects/DSA/IEEE-Extreme-Practice/week_2/beetlebag/input.txt', 'r') as fp:
    lines = fp.readlines()

count = 1
current_index = 0
while current_index < len(lines):
    # print(current_index)
    if current_index == 0:
        number_of_testcases = int(lines[current_index].strip())
        current_index += 1
    else:
        testcases[count] = {}
        current_testcase = testcases[count]
        testcase = lines[current_index].strip().split()
        current_index += 1
        capacity, gadgets_available = int(testcase[0]), int(testcase[1])
        gadgets_dict = {}
        for gadgets in range(gadgets_available):
            gadget = lines[current_index].strip().split()
            current_index += 1
            gadget_weight, gadget_fighting_power = int(gadget[0]), int(gadget[1])
            gadgets_dict[gadget_fighting_power] = gadget_weight
            
        gadgets_dict = dict(sorted(gadgets_dict.items(), reverse=True))
        powers_list, weights_list = list(gadgets_dict.keys()), list(gadgets_dict.values())
        max_power, current_capacity = 0, 0
        
        for pos, power in enumerate(powers_list):
            if (current_capacity + weights_list[pos]) <= capacity:
                max_power += power
                current_capacity += weights_list[pos]
                
        print(max_power)
        count += 1
        
        
number_of_testcases = int(input())

for num in range(number_of_testcases):
    testcase = input().strip().split(' ')
    capacity, gadgets_available = int(testcase[0]), int(testcase[1])
    gadgets_dict = {}
    for gadgets in range(gadgets_available):
        gadget = input().strip().split()
        current_index += 1
        gadget_weight, gadget_fighting_power = int(gadget[0]), int(gadget[1])
        gadgets_dict[gadget_fighting_power] = gadget_weight
        
    gadgets_dict = dict(sorted(gadgets_dict.items(), reverse=True))
    powers_list, weights_list = list(gadgets_dict.keys()), list(gadgets_dict.values())
    max_power, current_capacity = 0, 0
    
    for pos, power in enumerate(powers_list):
        if (current_capacity + weights_list[pos]) <= capacity:
            max_power += power
            current_capacity += weights_list[pos]
            
    print(max_power)