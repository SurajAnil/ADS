/*
 * Given a position to a node to a linked list, find the node and delete it.
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
 * insertList @brief : insert nodes at the beginning
 * @**head : reference to head
 * @data : data
 */
void insertList(struct Node** head, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node -> data = data;
	
	new_node -> next = *head;

	*head = new_node;
}

void deleteAtPos(struct Node** head, int pos)
{
	/* assign a curr_node struct
	 */
	struct Node* curr_node = *head;
	struct Node* temp = curr_node;
	struct Node* prev;
	struct Node* nxt;
	/* if we want to delete the first element
	 */
	if(pos == 0)
	{
		*head = curr_node -> next;
		free(curr_node);
		return;
	}	

	/* find the previous node
	 */
	for(int i = 0; temp != NULL && i < pos - 1; i++)
		temp = temp -> next;

	/* if the position is greater than the number of nodes
	 * return
	 */
	if(temp == NULL || temp -> next == NULL)
		return;

	/* make next point to the node after the deleted node
	 */ 
	nxt = temp -> next -> next;
	/* free the deleted node
	 */ 
	free(temp -> next);
	/* make the temp -> next node point to the nxt node
	 */ 
	temp -> next = nxt;
}

/**
 * print @brief : print the list
 * @head : head
 */
void printList(struct Node* head)
{
	struct Node* curr = head;
	while(curr != NULL)
	{	
		printf("%d -> ", curr -> data);
		curr = curr -> next;
	}

	printf("NULL\n");
}

// driver function
int main()
{
	struct Node* head = NULL;

	insertList(&head, 5);
	insertList(&head, 4);
	insertList(&head, 3);
	insertList(&head, 2);

	deleteAtPos(&head, 1);
	
	printList(head);
	
	return 0;
}
