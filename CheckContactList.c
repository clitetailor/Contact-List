#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#include "ContactList.h"

#ifndef additional_test

void CommandLineInterface()
{
	ContactList * a;
	
	initializeContactList(&a);
	
	int selection;
	do
	{
		ContactListMenu(a);
		printf("\n\nNhap vao lenh ban muon thuc hien (1-5):");
		
		fflush(stdin);
		scanf("%d", &selection);
		
		if (selection < 1 || selection > 5)
		{
			printf("\nLenh nhap vao khong thoa man!\n");
			continue;
		}
		
		manageContactListCommand(a, selection);
		
	} while (selection != 5);
	
	printf("\nChuong trinh dang thoat! ");
					Sleep(250);
					printf(".");
					Sleep(250);
					printf(".");
					Sleep(250);
					printf(".");
}

void ContactListMenu(ContactList *a)
{
	int menusize = 5;
	char ** menu;
	
	printf("\nTrong so dia chi co %d dia chi\n", a->size);
	
	printf("\nDanh sach cac lenh:\n");
	
	menu = (char **) malloc(sizeof(char *) * menusize);
	
	menu[0] = "Hien thi so dia chi";
	menu[1] = "Chon dia chi";
	menu[2] = "Them dia chi";
	menu[3] = "Xoa dia chi";
	menu[4] = "Thoat khoi chuong trinh";
	
	int i;
	for (i = 0; i < menusize; ++i)
	{
		printf("\n\t%d, %s", i+1, menu[i]);
	}
	
	printf("\n");
}

void manageContactListCommand(ContactList *a, int command)
{
	switch(command)
	{
		case 1:
				{
					// Print all
					int i;
					Node * currentNode;
					
					printf("\nSo dia chi:\n");
					currentNode = a->head;
					
					for (i = 0; i < a->size; ++i)
					{
						printf("\n\t%d, %s", i+1, getString(currentNode));
					}
					
					printf("\n");
					printContactList();
					break;
				}
		case 2:
				{
					// Select Contact 
					
					int selection;
					printf("\nNhap vao dia chi ban muon chon:");
					
					fflush(stdin);
					scanf("%d", &selection);
					
					Node * selectedNode;
					selectedNode = getNode(a, selection - 1);
					
					do
					{
						ContactMenu();
						printf("\n\nNhap vao lenh ban muon thuc hien (1-8):");
						
						fflush(stdin);
						scanf("%d", &selection);
						
						manageContactCommand( (Contact *) selectedNode->data, selection);
						
						if (selection < 1 || selected > 8)
						{
							printf("\nLenh nhap vao khong hop le!\n");
						}
					} while (selection != 8);
					
					break;
				}
		case 3:
				{
					// Add contact
					char name[MAX_STRING_SIZE + 1];
					printf("\nNhap vao ten dia chi:");
					
					do
					{
						fflush(stdin);
						fgets(name, MAX_STRING_SIZE + 1, stdin);
						
						if ( strlen(name) > MAX_STRING_SIZE )
						{
							printf("\nDo dai vuot qua %d. Yeu cau nhap lai!", MAX_STRING_SIZE);
						}
						
					} while ( strlen(name) > MAX_STRING_SIZE );
					
					addContact(a, name);
					
					break;
				}
		case 4:
				{
					// Remove contact
					int i;
					printf("\nNhap vao dia chi ban muon xoa:");
					scanf("%d", &i);
					
					removeContact(a, i);
					break;
				}
		case 5:
				{
					// Exit
					break;
				}
	}
};



void ContactMenu()
{
	int menusize = 8;
	char ** menu;
	
	printf("\nDanh sach cac lenh:\n");
	
	menu = (char **) malloc(sizeof(char *) * menusize);
	
	menu[0] = "Doi ten";
	menu[1] = "Them email";
	menu[2] = "Xoa email";
	menu[3] = "Them dia chi";
	menu[4] = "Xoa dia chi";
	menu[5] = "Them so dien thoai";
	menu[6] = "Xoa so dien thoai";
	menu[7] = "Thoat"
	
	int i;
	for (i = 0; i < menusize; ++i)
	{
		printf("\n\t%d, %s", i+1, menu[i]);
	}
	
	free(menu)
	
	printf("\n");
}

void manageContactCommand(Contact *a, int command)
{
	switch (command)
	{
		case 1:
				{
					
				},
		case 2:
				{
					
				},
		case 3:
				{
					
				},
		case 4:
				{
					
				},
		case 5:
				{
					
				},
		case 6:
				{
					
				},
		case 7:
				{
					
				},
		case 8:
				{
					
				}
	}
}

// main()


int main(int argc, char ** argv)
{
	CommandLineInterface();
	
	return 0;
}

#endif