/*
 * A C program to find the largest contiguous sum within an array. 
 * 
 * MIT License
 *
 * Copyright (c) 2017 Benn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */ 

#include <stdio.h>

// max function
int max(int a, int b) {return a > b ? a : b; }

int largest_sum(int A[], int n)
{
	int sum_till_here = 0;
	int max_sum_so_far = 0;

	// iterate through the array elements
	for(int i = 0; i < n; i++)
	{
		sum_till_here+= A[i];
		// if sum goes below zero, reset sum to zero
		if(sum_till_here < 0) sum_till_here = 0;
		max_sum_so_far = max(max_sum_so_far, sum_till_here);
	}
	return max_sum_so_far;
}

// driver function
int main()
{
	int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(A)/sizeof(A[0]);

	printf("The largest sum is: %d\n", largest_sum(A, n));

	return 0;
}
