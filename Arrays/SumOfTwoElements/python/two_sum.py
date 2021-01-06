#!/usr/bin/env python3
"""
Given an array of numbers, find two numbers
from the array which when added equals the target.
"""

def two_sum(arr, target):
    """Function takes in two args, the input array
    and the target.
        T: O(nlogn) -> Due to pre-sorting of the input arr
        S: O(1)
    :param arr: Input array
    :param target: Target
    :return: list of two numbers, else empty arr
    """
    n = len(arr)
    arr.sort()
    left = 0
    right = n-1
    res = []
    while left < right:
        curr_sum = arr[left]+arr[right]
        if curr_sum < target:
            left+=1
        elif curr_sum > target:
            right-=1
        else:
            res = [arr[left], arr[right]]
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
