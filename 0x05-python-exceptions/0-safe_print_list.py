#!/usr/bin/python3
def count_elements(my_list):
    count = 0
    for _ in my_list:
        count += 1
    return count

def safe_print_list(my_list=[], x=0):
    try:
        count = count_elements(my_list)
        num_to_print = min(count, x)
        for i in range(num_to_print):
            print(my_list[i], end=" ")
    except TypeError:
        pass
    finally:
        print()  # Print a new line after printing the elements
    return num_to_print
