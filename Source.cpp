//Write a function that counts the number of times a given int occurs in a Linked List
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
	int data;
	struct Node *next;
};

void printList(struct Node *head_ref)
{
	while (head_ref != NULL)
	{
		printf(" %d ", head_ref->data);
		head_ref = head_ref->next;
	}
}

Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
		return head_ref;
	}
}

Node* append(struct Node *head_ref, int new_data)
{
	struct Node *temp = head_ref;
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nSTack Overflow");
	else
	{
		new_node->data = new_data;

		if (temp != NULL)
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->next = NULL;
		}
		else
		{
			new_node->next = head_ref;
			head_ref = new_node;
		}
		return head_ref;
	}
}

Node* createLoop(struct Node *head_ref, int value)
{
	struct Node *temp = head_ref, *temp2 = head_ref;
	while (temp->data != value)
		temp = temp->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	return head_ref;
}
bool detectCycle(struct Node *head_ref)
{
	struct Node *slow = head_ref, *fast = head_ref;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}

	return false;
}
void main()
{
	struct Node *head = NULL, *head2 = NULL;
	head = append(head, 4);
	head = append(head, 5);
	head = append(head, 2);
	head = append(head, 7);
	head = push(head, 1);
	head = push(head, 8);
								//	while(1)  - for checking Stack overflow condition
								//	head = append(head, 8);
	printList(head);
	head = createLoop(head, 5);
	if (detectCycle(head))
		printf("\nLoop detected");
	else
		printf("\nLoop not detected");
	_getch();
}