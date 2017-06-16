/*
 * A C program to swap two nodes within a linked list 
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

void swapNodes(struct Node** head, int a, int b)
{
	struct Node* curr_a = *head;
	struct Node* curr_b = *head;

	struct Node* prev_a = NULL;
	struct Node* prev_b = NULL;

	struct Node* temp_a = NULL;
	struct Node* temp_b = NULL;

	struct Node* temp = NULL;

	/* iterate and find a
	 */
	while(curr_a -> next != NULL)
	{
		if(curr_a -> next -> data == a)
		{
			prev_a = curr_a;
			temp_a = curr_a -> next;
			break;
		}
		curr_a = curr_a -> next;
	}

	if(temp_a == NULL )
	{
		return;
	}
	
	while(curr_b -> next != NULL)
	{
		if(curr_b -> next -> data == b)
		{
			prev_b = curr_b;
			temp_b = curr_b -> next;
			break;
		}
		curr_b = curr_b -> next;
	}

	if(temp_b == NULL)
	{
		return;
	}
	
	prev_a -> next = temp_b;
	prev_b -> next = temp_a;
	
	temp = temp_a -> next;
	temp_a -> next = temp_b -> next;
	temp_b -> next = temp;

}

void insertList(struct Node** head, int data)
{
	struct Node* new_node = (struct Node*)malloc (sizeof(struct Node));

	new_node -> data = data;

	new_node -> next = *head;

	*head = new_node;
}


void printList(struct Node* head)
{
	struct Node* curr_node = head;

	while(curr_node != NULL)
	{
		printf("%d -> ", curr_node -> data);
		curr_node = curr_node -> next;
	}
	printf("NULL\n");
}


// driver function
int main()
{
	struct Node* head = NULL;

	insertList(&head, 9);
	insertList(&head, 8);
	insertList(&head, 6);
	insertList(&head, 4);
	insertList(&head, 1);

	swapNodes(&head, 4, 8);

	printList(head);

	return 0;
}
