/*
 * A C program to create a basic binary tree. 
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

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data)
{
	/* create a new node
	 */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* initialize the new node
	 */
	new_node -> data = data;

	new_node -> right = NULL;

	new_node -> left = NULL;

	return new_node;
}

// driver function
int main()
{
	// initialize a root node
	struct Node* root = NULL;

	root = createNode(1);

	root -> left = createNode(2);

	root -> right = createNode(3);

	root -> left -> left = createNode(4);
	
	/*
	 * 			  1
	 *        /       \
	 *       2          3
	 *     /   \       /  \
	 *    4    NULL  NULL  NULL
	 *   /  \
	 * NULL NULL
	 */ 

	return 0;
}
