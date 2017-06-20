/*
 * A C program to search through a array. 
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
#include <stdlib.h>

/*
 * recursively search through a sorted list to find a key
 *
 * HINT: Use div and conquer method
 *
 */ 
int divConqSearch(int A[], int n, int start, int end, int key)
{
	// base case
	if(start > end)
		return -1;

	int mid = (start + end) / 2;

	// base case
	if(key == A[mid])
		return mid;
	if(key > A[mid])
		divConqSearch(A, n, mid + 1, end, key);
	divConqSearch(A, n, 0, mid - 1, key);
}


/*
 * insert a key in a sorted array
 *
 * HINT: use the divide and conquer approach
 *
 */ 
void divConqInsert(int A[], int n, int key, int capacity)
{
	// cannot insert if we are full capacity
	if(n >= capacity)
		return;

	// iterate through the list on element at a time
	int i;
	for(i = n - 1; (key < A[i] && i >= 0); i--)
	{
		A[i + 1] = A[i];
	}
	A[i + 1] = key;
}

// driver function
int main()
{
	int A[10] = {1, 3, 5, 6, 7, 9};
	int n = sizeof(A)/sizeof(A[0]);
	int start = 0, end = n - 1;
	int key = 5;
	int sol = divConqSearch(A, n, start, end, key);
	sol == -1 ? printf("Sorry, key was not found!\n") : printf("They key was found and the index is: %d\n", sol);
	
	// insert
	int capacity = sizeof(A)/sizeof(A[0]);
	divConqInsert(A, 6, 4, capacity);
	
	for(int i = 0; i < n + 1; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
