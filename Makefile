.PHONY: all
all:
	gcc -c ContactList.c
	gcc -c CheckContactList.c
	gcc -o ContactList.exe ContactList.o CheckContactList.o

.PHONY: test
test:
	gcc -Dadditional_test -c ContactList.c
	gcc -Dadditional_test -c CheckContactList.c
	gcc -o ContactList.exe ContactList.o CheckContactList.o