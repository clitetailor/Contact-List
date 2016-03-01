#ifndef _H_CONTACTLIST
#define _H_CONTACTLIST

#define MAX_STRING_SIZE 32

#include <stdbool.h>


// LinkList definition

struct node
{
	struct node *next;
	void * data;
};
typedef struct node Node;

void initializeNode(Node ** hNode);
void deleteNode(Node *hNode);

void linkNode(Node *nodeA, Node *nodeB);

bool setString(Node *a, char * str);
char * getString(Node *a);



struct linklist
{
	struct node *head;
	struct node *tail;
	int size;
};
typedef struct linklist LinkList;

void initializeLinkList(LinkList ** a);
void deleteLinkList(LinkList *a);

void appendNode(LinkList *a, Node *nd);
bool removeNode(LinkList *a, int n);						// From 0

Node * getNode(LinkList *a, int n);



// ContactList definition


struct contact
{
	char Name[MAX_STRING_SIZE];
	LinkList * Email;
	LinkList * Address;
	LinkList * Phone;
};
typedef struct contact Contact;

void initializeContact(Contact ** a);
void deleteContact(Contact *a);

void setContactName(Contact *a, char * name);
void addEmail(Contact *a, char * email);
void removeEmail(Contact *a, int n);
void addAdress(Contact *a, char * address);
void removeAdress(Contact *a, int n);
void addPhone(Contact *a, char * phone);
void removePhone(Contact *a, int n);



typedef LinkList ContactList;

void initializeContactList(ContactList **a);
void deleteContactList(ContactList *a);

void printContactList(ContactList *a);

void addContact(ContactList * a, char * name);
void removeContact(ContactList * a, int i);
void renameContactInContactList(ContactList * a, int n, char * name);



// Command line interface


void CommandLineInterface();

void ContactListMenu(ContactList *a);
void manageContactListCommand(ContactList *a, int command);

void ContactMenu();
void displayContact(Contact *a);
void manageContactCommand(Contact *a, int command);



#endif