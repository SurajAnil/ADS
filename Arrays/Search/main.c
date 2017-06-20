/*
 * A C program that performs a linear search on an unsorted array. 
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
 * search function
 */
int search(int A[], int n, int key)
{
	int a_size = n;
	//int k = (int)*key;
	/* iterate through the array till you find the key
	 */ 
	while(--a_size >= 0)
		if(key == A[a_size]) return 1;
	return -1;
}

// driver function
int main(int argc, char* argv[])
{
	/* 
	 * do a sanity check
	 */ 
	if(argc != 2)
		return;
	int A[] = {1, 5, 3 , 7, 0, 2};
	int n = sizeof(A)/sizeof(A[0]) + 1;
	int key = (int)atoi(argv[1]);
	printf("This is our input key: %d\n");
	getchar();

	/*
	 * linearly searches for the key and returns back:
	 * 		1 : success
	 * 	   -1 : failure
	 */ 
	search(A, n, key) > 0 ? printf("Key found\n") : printf("Sorry! Key not found, try again..\n");
	
	return 0;
}
