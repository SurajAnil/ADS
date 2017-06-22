/*
 * A C program to determine the height of a binary tree. 
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
#include <math.h>

int max(int a, int b) 
{ 
	return a > b ? a : b; 
}

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

/**
 * insertNode @main : insert a node
 *
 */
struct Node* insertNode(int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = data;
}


/*
 * get height of tree
 */
int getHeight(struct Node* root)
{
	if(root == NULL)
		return 0;
	
	return 1 + max(getHeight(root -> left), getHeight(root -> right));
}


/* pre-order print  
 */
void printTree(struct Node* root)
{
	if(root == NULL)
		return;
	printf("%d ", root -> data);
	printTree(root -> left);
	printTree(root -> right);
}
// driver function
int main()
{
	struct Node* root = insertNode(5);

	root -> left = insertNode(4);

	root -> right = insertNode(6);
	
	/* display the tree
	 */ 
	//printTree(root);
	
	printf("The tree has a height of %d\n", getHeight(root));


	return 0;
}
