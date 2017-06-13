/*
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.
 *
 * For example, given following linked lists :
 *
 *   5 -> 8 -> 20 
 *   4 -> 11 -> 15
 * 
 * The merged list should be :
 *
 * 4 -> 5 -> 8 -> 11 -> 15 -> 20
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
 * copieg or substantial portions of the Software.
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
#include <limits.h>

using namespace std;

struct Node {
	int data;
	Node * next;
	//Node(int x) : data(x), next(NULL) {}
};

Node * mergelists(Node * root1, Node * root2)
{
	Node * fList = new Node; fList -> data = 0; fList -> next = NULL;
	Node * resList = fList; 
	while(root1 != NULL && root2 != NULL) 
	{
		if(root1 -> data < root2 -> data)
		{
			fList -> next = root1;
			root1 = root1 -> next;
		}
		else
		{
			fList -> next = root2;
			root2 = root2 -> next;
		}
		fList = fList -> next;
	}
	fList-> next = root1? root1 : root2;
	return resList -> next;  
}

// driver function
int main()
{
	// declaration and initialization
	Node * m1 = new Node; Node * m2 = new Node; Node * m3 = new Node;
	Node * n1 = new Node; Node * n2 = new Node; Node * n3 = new Node;

	m1 -> next = m2; m2 -> next = m3;
	n1 -> next = n2; n2 -> next = n3;

	m1 -> data = 1; m2 -> data = 3; m3 -> data = 5;
	n1 -> data = 2; n2 -> data = 4; n3 -> data = 6;

	Node * sol = mergelists(m1, n1);

	// display results
	while(sol)
	{
		printf("%d -> ", sol -> data);
		sol = sol -> next;
	}
	// add a line space
	printf("NULL\n");
	return 0;
}
