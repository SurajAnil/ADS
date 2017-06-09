/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
 * TIP: C users, please malloc the result into a new array and return the result.
 *
 * Copyright (c) 2017 Suraj Bennur
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
#include <iostream>
#include <vector>

using namespace std;

/**
 * @general: Merges two sorted lists intoa single sorted list.
 * @A: list A
 * @B: list B
 */ 
vector<int> mergeLists(vector<int> &A, vector<int> &B)
{
	// sanity checks
	if(A.size() == 0 && B.size() == 0)
	{
		vector<int> r;
		return r;
	}
	else if(A.size() == 0)
		return B;
	else if(B.size() == 0)
		return A;

	int lenA = A.size(); int i = 0;
	int lenB = B.size(); int j = 0;
	int lenR = lenA + lenB;
	vector<int> res(lenR); int r = 0;

	// iterate through the lists
	// till one of them gets exhausted
	while(i < A.size() && j < B.size())
	{
		if(A[i] < B[j])
		{
			res[r] = A[i];
			i++; r++;
		}
		else
		{
			res[r] = B[j];
			j++; r++;
		}
	}
	res[r] = A[i] ? A[i] : B[j]; 
	
	for(int k = 0; k < res.size(); k++)
	{
		A[k] = res[k];
	}

	return res;
}

// driver function
int main(void)
{
	vector<int> A = {-4, 3};
	vector<int> B = {-2, -2};
	// call mergeLists function
	vector<int> sol = mergeLists(A, B);
	// display results
	for(int i = 0; i < sol.size(); i++)
		printf("%d ", sol[i]);
	printf("\n");
	return 0;
}

