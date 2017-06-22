/*
 * A C program to get the Nth node from a linked list
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
	struct Node* next;
};


/**
 *
 */
void insertNode(struct Node** head, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node -> data = data;

	new_node -> next = *head;

	*head = new_node;
}

/**
 *
 *
 */
int getNode(struct Node* head, int n)
{
	struct Node* temp = head;
	for(int i = 0; i < n && temp -> next != NULL; i++)
		temp = temp -> next;

	if(temp == NULL)
		return;

	return temp -> data;
}


// driver function
int main()
{
	struct Node* head = NULL;
	
	insertNode(&head, 5);
	insertNode(&head, 4);
	insertNode(&head, 3);
	insertNode(&head, 1);

	int val = getNode(head, 3);

	printf("The 3rd node is %d\n", val);
	return 0;
}
