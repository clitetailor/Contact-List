#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#include "ContactList.h"

#ifndef test




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
		
		if (selection < 1 || selection > 4)
		{
			printf("\nLenh nhap vao khong thoa man!\n");
			continue;
		}
		
		manageContactListCommand(a, selection);
		
	} while (selection != 4);
	
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
	
	menu[0] = "Hien thi toan bo dia chi";
	menu[1] = "Hien thi so dia chi hien tai";
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

void displayContactList(ContactList *a);

void manageContactListCommand(ContactList *a, int command)
{
	switch(command)
	{
		case 1:
				{
					// Print all
					break;
				}
		case 2:
				{
					// Contact 
					
					int selection;
					printf("\nNhap vao dia chi ban muon chon:");
					
					fflush(stdin);
					scanf("%d", &selection);
					do
					{
						ContactMenu();
						printf("\n\nNhap vao lenh ban muon thuc hien (1-5):");
						
						fflush(stdin);
						scanf("%d", selection);
						
						manageContactListCommand(a, selection);
					} while (selection < 1 || selection > 4);
					
					break;
				}
		case 3:
				{
					// Add contact
					break;
				}
		case 4:
				{
					
					break;
				}
		case 5:
				{
					// Exit
					break;
				}
	}
};



void ContactMenu(Contact *a)
{
	int menusize = 9;
	char ** menu;
	
	printf("\nDanh sach cac lenh:\n");
	
	menu = (char **) malloc(sizeof(char *) * menusize);
	
	menu[0] = "Doi ten";
	menu[1] = "Them email";
	menu[2] = "Xoa email";
	menu[3] = "Them dia chi";
	menu[4] = "Xoa dia chi";
	menu[5] = "Them dien thoai nha";
	menu[6] = "Xoa dien thoai nha";
	menu[7] = "Them dien thoai van phong";
	menu[8] = "Xoa dien thoai van phong";
	
	int i;
	for (i = 0; i < menusize; ++i)
	{
		printf("\n\t%d, %s", i+1, menu[i]);
	}
	
	printf("\n");
}


int main(int argc, char ** argv)
{
	CommandLineInterface();
	
	return 0;
}

#endif