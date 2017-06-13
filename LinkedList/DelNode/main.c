/*
 * A C program to delete node from a linked list
 * 
 * Steps:
 * 1) Find the previous node
 * 2) Change the previous node's next pointer.
 * 3) Free the memory of the to be deleted node.
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
 * insert
 * @brief : First we insert nodes to form a tree
 * @**head : reference to the head node
 * @data : the data
 */
void insert(struct Node ** head, int data)
{
	/* create a new node and insert it to the linked list 
	 */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* assign data to new_node -> data
	 */ 
	new_node -> data = data;

	/* while inserting, the new_node -> next should point to exiting node
	 */ 
	new_node -> next = *head;

	/* make the new_node the head
	 */ 
	*head = new_node;
}

/**
 *
 */
void delete(struct Node ** head, int data)
{
	struct Node * curr_node = *head;
	struct Node * temp = *head;

	/* if the head is NULL, handle it
	 */
	if(curr_node == NULL)
	{
		return;
	}
	/* else if the curr node itself is to be deleted, 
	 * delete it
	 */ 
	else if(curr_node != NULL && curr_node -> data == data)
	{
		*head = curr_node -> next;
		free(curr_node);
		return;
	}

	while(curr_node -> next != NULL)
	{
		if(curr_node -> next -> data == data)
		{
			temp = curr_node -> next;
			curr_node -> next = curr_node -> next -> next;
			free(temp);
			return;
		}
		curr_node = curr_node -> next;
	}

	return;
}

void printList(struct Node* head)
{
	while(head != NULL)
	{
		printf("%d -> ", head -> data);
		head = head -> next;
	}
	printf("NULL\n");
}

// driver function
int main()
{
	struct Node* head = NULL;
	
	delete(&head, NULL);
	//insert(&head, 1);
	//insert(&head, 4);
	//insert(&head, 6);

	//delete(&head, 4);

	/* display the new list
	 */
	printList(head);

	return 0;
}
