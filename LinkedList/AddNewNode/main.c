/*
 * Program in C dealing with linked lists that do the following:
 * 1) Add a node at the front
 * 2) Add a node after a given node
 * 3) Add a node at the end
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

/** 
 * push @brief - add a node to the front
 * @**head : reference to the head node
 * @data : the value of the node
 */
void insert(struct Node** head, int data)
{
	/* create a new node and place it at the beginning 
	 */
	struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));

	/* place the data to the newly created node */
	new_head -> data = data;
	
	/* make head the second node */
	new_head -> next = *head;

	/* the new_head is now the current head */
	*head = new_head;
}

/**
 * insertAfter @brief : insert the given node after nth node
 *
 */
void insertAfter(struct Node* curr_node, int data)
{
	/* create a new node 
	 */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node -> data = data;

	/* make the new_node -> next point to the curr_node -> next;
	 */
	new_node -> next = curr_node -> next;

	/* make the curr_node point to the new_node as its next node 
	 */
	curr_node -> next = new_node;
}

/**
 * node_push_back @brief : append the node at the end
 * @**head : reference to the head of the linked list
 * @data : data
 */
void node_push_back(struct Node** head, int data)
{
	/* create a new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* curr_node = *head;

	new_node -> data = data;

	/* iterate till you reach the last node
	 */ 
	while(curr_node -> next != NULL)
		curr_node = curr_node -> next;
	
	curr_node -> next = new_node;
}
/**
 *
 */ 
void printList(struct Node* head)
{
	while(head != NULL)
	{
		printf("%d -> ", head -> data);
		head = head -> next;
	}
}

// driver function
int main()
{
	/* create an empty list
	 */ 
	struct Node* head = NULL;

	node_push_back(&head, 8);

	/* insert at the beginng 
	 */ 
	insert(&head, 5);

	/* insert at the beginning
	 */ 
	insert(&head, 2);

	/* append the given node to the end of the list
	 */ 
	node_push_back(&head, 9);
	
	/* insert the node after a given node
	 */ 
	insertAfter(head -> next, 4);
	
	/* print the linked list
	 */ 
	printList(head);

	return 0;
}
