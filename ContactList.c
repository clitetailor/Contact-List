#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ContactList.h"
// LinkList Node

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

bool setString(Node * a, char * str)
{
	if ( strlen(str) >= MAX_STRING_SIZE )
		return false;
	
	a->data = (char *) malloc( sizeof(char) * ( MAX_STRING_SIZE + 1 ) );
	strcpy( (char *) a->data, str);
	return true;
}

char * getString(Node *a)
{
	return (char *) a->data;
}

// LinkList

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
		do
		{
			tempNode = currentNode->next;
			deleteNode(currentNode);
			currentNode = tempNode;
		} while ( currentNode->next != NULL );
	}
	
	free(a);
}

void appendNode(LinkList *a, Node *nd)
{
	if ( a->head == NULL )
	{
		a->head = nd;
		a->tail = nd;
	}
	else
	{
		a->tail->next = nd;
		a->tail = nd;
	}
	
	a->size++;
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



// Contact

void initializeContact(Contact **a)
{
	(*a) = (Contact *) malloc( sizeof(Contact) );
	
	(*a)->Name[0] = '\0';
	
	initializeLinkList(a->Email);
	initializeLinkList(a->Address);
	initializeLinkList(a->Phone);
}

void deleteContact(Contact *a)
{
	deleteLinkList(a->Email);
	deleteLinkList(a->Address);
	deleteLinkList(a->Phone);
	
	free(a);
}

void setContactName(Contact *a, char * name)
{
	strcpy(a->Name, name);
}

void addEmail(Contact *a, char * email)
{
	Node * newNode;
	initializeNode(newNode);
	setString(newNode, email);
	
	appendNode(a->Email, newNode);
}

void removeEmail(Contact *a, int n)
{
	removeNode(a->Email, n);
}

void addAddress(Contact *a, char * address)
{
	Node * newNode;
	initializeNode(newNode);
	setString(newNode, address);
	
	appendNode(a->Address, newNode);
}

void removeAddress(Contact *a, int n)
{
	removeNode(a->Address, n);
}

void addPhone(Contact *a, char * phone)
{
	Node *newNode;
	initializeNode(newNode);
	setString(newNode, phone);
	
	appendNode(a->Phone, phone);
}

void removePhone(Contact *a, int n)
{
	removeNode(a->Phone, n);
}

void displayContact(Contact *a)
{
	
}

// Contact List

void initializeContactList(ContactList **a)
{
	initializeLinkList(a);
}

void deleteContactList(ContactList *a)
{
	deleteLinkList(a);
}

void addContact(ContactList *a, char * name)
{
	Contact * newNode;
	
	initializeNode(&newNode);
	appendNode(a, newNode);
	
	initializeContact( (ContactList**) &(newNode->data) );
	setContactName( (Contact *) newNode->data , name );
}

void removeContact(ContactList *a, int i)
{
	removeNode(a, i);
}

void renameContactInContactList(ContactList *a, int n, char * name)
{
	Node * currentNode;
	currentNode = getNode(a, n);
	
	setContactName( (Contact *) currentNode->data , name );
}





/*
 *
 * Additional Test
 *
 */
#ifdef additional_test


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