#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ContactList.h"
// LinkList

void initializeNode(Node ** hNode)
{
	(*hNode) = (Node *) malloc( sizeof(Node) );
	
	(*hNode)->next = NULL;
	(*hNode)->data = NULL;
};

void deleteNode(Node *hNode)
{
	free(hNode->data);
	free(hNode);
};



void linkNode(Node *nodeA, Node *nodeB)
{
	nodeA->next = nodeB;
};



bool setString(Node *hNode, char * str)
{
	if ( strlen(str) >= MAX_STRING_SIZE )
		return false;
	
	hNode->data = (char *) malloc( sizeof(char) * MAX_STRING_SIZE );
	strcpy( (char *) hNode->data, str);
	return true;
}

char * getString(Node *hNode)
{
	return (char *) hNode->data;
}




void initializeLinkList(LinkList **a)
{
	(*a) = (LinkList *) malloc(sizeof(LinkList));
	
	(*a)->head = NULL;
	(*a)->tail = NULL;
	(*a)->size = 0;
}

void deleteLinkList(LinkList *a)
{
	Node *currentNode = a->head;
	Node *tempNode = a->head;
	
	if ( a->head != NULL )
	{
		while ( currentNode->next != NULL )
		{
			tempNode = currentNode->next;
			deleteNode(currentNode);
			currentNode = tempNode;
		}
	}
	
	free(a);
}


void appendNode(LinkList *a, Node *node)
{
	if ( a->head == NULL )
	{
		initializeNode(a->head);
		a->tail = a->head;
	}
	else
	{
		initializeNode(a->tail->next);
		a->tail = a->tail->next;
	}
}

bool removeNode(LinkList *a, int n)
{
	if (n < 0 || n > a->size - 1)
	{
		return false;
	}
	
	if (n == 0)
	{
		temp = a->head->next;
		deleteNode(a->head);
		a->head = temp;
		
		if (a->size == 1)
		{
			a->tail = NULL;
		}
	}
	else if (n == a->size - 1)
	{
		Node *currentNode = a->head;
		
		int i;
		for (i = 0; i < n - 2; ++i)
		{
			currentNode = currentNode->next;
		}
		
		deleteNode(currentNode->next);
		currentNode->next = NULL;
		
		a->tail = currentNode;
	}
	else
	{
		Node *temp;
		Node *currentNode = a->head;
		
		int i;
		for (i = 1; i < n; ++i)
		{
			currentNode = currentNode->next;
		}
		
		temp = currentNode->next->next;
		deleteNode(currentNode->next);
		
		currentNode->next = temp;
	}
	
	a->size--;
	
	return true;
}


Node * getNode(LinkList *a, int n)
{
	if (n < 0 || n > a->size - 1)
	{
		return NULL;
	}
	
	if (n == 0)
	{
		return a->head;
	}
	
	Node * currentNode = a->head;
	
	int i;
	for (i = 0; i < n; ++i)
	{
		currentNode = currentNode->next;
	}
	
	return currentNode;
}





#ifdef test

int main()
{
	Node *A, *B;
	initializeNode(&A);
	initializeNode(&B);
	
	connectNode(A, B);
	
	char * str = (char *) malloc(sizeof(char) * (MAX_STRING_SIZE + 1));
	do
	{
		fflush(stdin);
		fgets(str, MAX_STRING_SIZE + 1, stdin);
		printf("\nstr:%s", str);
	} while ( !setString(A, str) );
	
	printf("%s", getString(A));
	
	free(str);
	
	deleteNode(A);
	deleteNode(B);
	
	return 0;
}

#endif