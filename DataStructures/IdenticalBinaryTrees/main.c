/*
 * A C program to recursicely check if two binary trees are identical. 
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

/* struct Node
 * left pointer
 * right pointer
 */ 
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};


/**
 * isnertNode @basic : insert nodes in a binary tree
 * @data : data
 * @return : struct Node*
 */ 
struct Node* insertNode(int data)
{
	/* create a new node
	 */ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node -> data = data;

	new_node -> left = NULL;

	new_node -> right = NULL;

	return new_node;
}

/**
 * recursively check if the two trees are identical
 */ 
int checkIdentical(struct Node* root1, struct Node* root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;

	if(root1 != NULL && root2 != NULL)
		return (
				root1 -> data == root2 -> data &&
				checkIdentical(root1 -> left, root2 -> left) &&
				checkIdentical(root1 -> right, root2 -> right));

	return 0;
}

// driver function
int main()
{
	struct Node* root1 = insertNode(1);
	struct Node* root2 = insertNode(1);

	root1 -> left = insertNode(2);
	root1 -> right = insertNode(3);
	root1 -> left -> left = insertNode(4);
	root1 -> left -> right = insertNode(5);

	root2 -> left = insertNode(2);
	root2 -> right = insertNode(3);
	root2 -> left -> left = insertNode(4);
	root2 -> left -> right = insertNode(5);
	
	/* return 	1 : identical
	 * 			0 : not identical 
	 */ 
	checkIdentical(root1, root2) < 1 ? 
		printf("The two trees are not identocal\n") : 
		printf("The two trees are identical\n");

	return 0;
}

