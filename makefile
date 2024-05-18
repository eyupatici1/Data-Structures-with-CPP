all: compile link execute

compile:
	g++ -c -I "./include/" ./src/NumbersLinkedListNode.cpp -o ./lib/NumbersLinkedListNode.o 
	g++ -c -I "./include/" ./src/NumbersLinkedList.cpp -o ./lib/NumbersLinkedList.o
	g++ -c -I "./include/" ./src/ListsLinkedListNode.cpp -o ./lib/ListsLinkedListNode.o
	g++ -c -I "./include/" ./src/ListsLinkedList.cpp -o ./lib/ListsLinkedList.o  
	g++ -c -I "./include/" ./src/Print.cpp -o ./lib/Print.o  
	g++ -c -I "./include/" ./src/File.cpp -o ./lib/File.o
	g++ -c -I "./include/" ./src/Main.cpp -o ./lib/Main.o 

link:
	g++ ./lib/NumbersLinkedListNode.o ./lib/NumbersLinkedList.o ./lib/ListsLinkedListNode.o ./lib/ListsLinkedList.o ./lib/Print.o ./lib/File.o ./lib/Main.o -o ./bin/Program
	
execute:
	./bin/Program