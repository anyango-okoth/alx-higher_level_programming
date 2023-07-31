def safe_print_list(my_list=[], x=0):
    """Print x elements of a list.

    Args:
        my_list (list): The list to print elements from.
        x (int): The number of elements of my_list to print.

    Returns:
        The number of elements printed.
    """
    elements_to_print = my_list[:x]
    print("".join(map(str, elements_to_print)))
    return len(elements_to_print)

