/*
 * A C program to rotate an array. 
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
 * shift by one position
 */ 
void shift(int A[], int n)
{
	int temp = A[0];

	for(int i = 1; i < n; i++)
	{
		A[i - 1] = A[i];
	}
	A[n - 1] = temp;
}


/*
 * rotate the array by k positions
 */
void rotate(int A[], int n, int k)
{
	for(int i = 1; i <= k; i++)
	{
		shift(A, n);
	}
}

// driver function
int main()
{
	int A[] = {1, 3, 5, 7};
	int n = sizeof(A)/sizeof(int);

	// number of positions to move by
	int k = 1;
	rotate(A, n, k);
	
	for(int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
