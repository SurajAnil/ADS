/*
 * A C program to determine the two elements that add up to the target sum. 
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
#define MAX 100000

void sumOfTwoEle(int A[], int n, int sum)
{
	/* 
	 * set the map to zero
	 */
	int map[MAX] = {0};

	int i, temp;
	for(i = 0; i < n; i++)
	{
		temp = sum - A[i];
		if(temp >= 0 && map[temp])
			printf("The two elements are: %d and %d\n", A[i], sum - A[i]);
		map[A[i]] = 1;
	}
}

// driver function
int main()
{
	int A[] = {1, 3, 5, 7};
	int n = sizeof(A)/sizeof(A[0]);
	sumOfTwoEle(A, n, 6);
	return 0;
}
