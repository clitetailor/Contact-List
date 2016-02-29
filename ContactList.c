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
	Node *currentNode = a=>head;
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

void initializeContactList(ContactList **a)
{
	initializeLinkList(a);
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