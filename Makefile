.PHONY: all
all:
	gcc -c ContactList.c
	gcc -c CheckContactList.c
	gcc -o ContactList.exe ContactList.o CheckContactList.o
	
test:
	gcc -Dtest -c ContactList.c
	gcc -Dtest -c CheckContactList.c
	gcc -o ContactList.exe ContactList.o CheckContactList.o