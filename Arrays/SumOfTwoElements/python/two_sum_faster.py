#!/usr/bin/env python3
"""
Given an array of numbers, find two numbers
from the array which when added equals the target.
"""

def two_sum(arr, target):
    """Function takes in two args, the input array
    and the target.
        T: O(n) - We loop through the array once
        S: O(n) - We use an extra data structure to store the target-curr
    :param arr: Input array
    :param target: Target
    :return: list of two numbers, else empty arr
    """
    n = len(arr)
    res = []
    if n == 0 or n == 1:
        return res
    sum_dict = {}
    for i in range(n):
        curr_diff = target-arr[i]
        sum_dict[curr_diff] = i
        if arr[i] in sum_dict and sum_dict[arr[i]]!=i:
            res += [arr[i], curr_diff]
            break
    return res


if __name__ == "__main__":
    #arr = [3, 1, 5, 6, 7, 4]
    arr = [0, 1, 0, 2, 7, 3]
    #arr = [-1, 1, 6, 0, 3, 3]
    #arr = [3, 1, 5, 6, 7, 4]
    #arr = [-1, -2, -1, -5, 0, 4]
    #arr = [0, 1]
    #arr = [-1, -2]
    #arr = []
    target = 5
    #target = 0
    print(two_sum(arr, target))
