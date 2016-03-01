
all:
	gcc -c ContactList.c
	gcc -c CheckContactList.c
	gcc -o ContactList.exe ContactList.o CheckContactList.o