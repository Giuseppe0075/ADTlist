main.exe:	list.o utilities.o item.o main.c
	gcc	list.o utilities.o item.o main.c -o main.exe
list.o:
	gcc	-c list.c
utilities.o:
	gcc	-c utilities.c
item.o:
	gcc	-c item.c
clean:
	del -f item.o utilities.o list.o main.exe