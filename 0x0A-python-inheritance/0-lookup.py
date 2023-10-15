#!/usr/bin/python3

"""Defines a function for looking up object attributes and methods."""

def lookup(obj):
    """
    Returns a list of available attributes and methods of an object.

    :param obj: The object to inspect.
    :return: A list of attribute and method names.
    """
    return dir(obj)

