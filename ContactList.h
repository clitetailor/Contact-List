#ifndef _H_CONTACTLIST
#define _H_CONTACTLIST

#define MAX_STRING_SIZE 32

// LinkList definition

struct node
{
	struct node *next;
	void * data;
};
typedef struct node Node;

void initializeNode(Node ** hNode);
void deleteNode(Node *hNode);

void connectNode(Node *nodeA, Node *nodeB);

bool setString(Node *hNode, char * str);
char * getString(Node *hNode);



struct linklist
{
	struct node *head;
	struct node *tail;
};
typedef struct linklist LinkList;

void initializeLinkList(LinkList ** hList);
void deleteLinkList(LinkList *lLIst);

void appendNode(LinkList *lList, Node *node);
void removeNode(LinkList *lList, int i);

Node * getNode(LinkList *lList, int i);



// ContactList definition

typedef LinkList ContactList;

void initializeContactList(ContactList ** hList);
void deleteContactList(ContactList * cList);

void addContact(ContactList ** cList, char * Name);
void removeContact(ContactList ** cList, int i);
void renameContactInContactList(ContactList ** cList, int i);

void chooseContact(ContactList * cList, int i);

void printContactList(ContactList * cList);

struct contact
{
	char * Name;
	LinkList * Emails;
	LinkList * HomeAddresses;
	LinkList * HomePhoneNumbers;
	LinkList * OfficePhoneNumbers;
};
typedef struct contact Contact;

void initialize(Contact ** hContact);
void delete(Contact *hContact);

void print(Contact *hContact);

void renameContact(Contact *hContact);
void addEmail(Contact *hContact, char * email);
void removeEmail(Contact *hContact, int i);
void addAdresses(Contact *hContact, char * address);
void removeAdresses(Contact *hContact, int i);
void addHomePhoneNumber(Contact *hContact, char * homephonenumber);
void removeHomePhoneNumber(Contact *hContact, int i);
void addOfficePhoneNumber(Contact *hContact, char * officephonenumber);
void removeOfficePhoneNumber(Contact *hContact, int i);



#endif