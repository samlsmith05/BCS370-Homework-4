//****************************************************
// File: Main.cpp
//
// Purpose: Show and utilize all the functions in all the classes
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "BookCollection.h"
#include "BookList.h"
#include "BookQueue.h"
#include "BookStack.h"
using namespace std;

//****************************************************
// Function: main()
//
// Purpose: entry point for the program
//
// Update Information
// ------------------
//
//****************************************************

int main() {
	Book book1 = Book();			//calls the default constructor
	Book book2 = Book("ABC123", "The Hunger Games", 19.95);		//calls the constructor that takes all member variables
	Book book3 = Book("XYZ789", "To Kill A Mockingbird", 23.75);//calls the constructor that takes all member variables
	Book book4 = Book("JKL456", "Introduction to C++", 163.98); //calls the constructor that takes all member variables
	Book book5 = Book();			//calls the default constructor
	Book book6 = Book(book4);		//calls the copy constructor
	Book book7 = book2;				//calls operator=

	book1.SetIsbn("321EFG");		//calls SetIsbn
	book1.SetPrice(9.99);			//calls SetPrice
	book1.SetTitle("Easy Poems");	//calls SetTitle

	book5.SetIsbn("QRS987");
	book5.SetTitle("Divergent");
	book5.SetPrice(15.99);

	cout << "Operator== test success: " << endl;
	if (book6 == book4) {									//calls operator==
		cout << "They are the same book.\n";
	}
	else {
		cout << "They are NOT the same book.\n";
	}

	cout << "Operator== test fail: " << endl;
	if (book3 == book4) {									//calls operator==
		cout << "They are the same book.\n";
	}
	else {
		cout << "They are NOT the same book.\n";
	}
	cout << "------------------------------------------------------------" << endl;
	cout << "Stack tests: " << endl;
	Book book8;
	 
	BookStack bs = BookStack();								//calls default constructor
	cout << bs;												//calls operator<<

	bs.Push(book1);											//calls Push()
	bs.Push(book2);											//calls Push()
	cout << "After pushes: \n" << bs;						//calls operator<<
	cout << "The size of the stack is: " << bs.Size() << endl;	//calls Size()
	cout << "The max size of the stack is: " << bs.MaxStorage() << endl; //calls MaxStorage()

	bs.Push(book3);											//calls Push()	
	bs.Push(book4);											//calls Push()
	bs.Push(book5);											//calls Push()
	if (bs.Push(book6) == true) {							//calls Push()
		cout << "Push success since the stack is NOT full" << endl;
	}
	else {
		cout << "Push failed since the stack is already full" << endl;
	}
	cout << bs;												//calls operator<<
	
	BookStack bs2 = BookStack(bs);							//calls copy constructor
	cout << "Copy constructed stack: \n" << bs2;			//calls operator<<
	
	bs.Pop();												//calls Pop()
	if (bs.Pop() == true) {									//calls Pop()	
		cout << "Pop is true and it was removed." << endl;
	}
	else {
		cout << "Pop is false since the stack is empty already." << endl;
	}
	cout << "After 2 pops:\n" << bs;						//calls operator<<


	if (bs.Top(book8) == true) {							//calls Top()
		cout << "Top worked and the top book is: \n" << book8 << endl;
	}
	else {
		cout << "Top failed." << endl;
	}


	BookStack bs3 = BookStack(4);									//calls BookStack(int)
	cout << "The size of the stack bs3 is: " << bs3.Size() << endl;	//calls Size()
	cout << "The max size of the stack bs3 is: " << bs3.MaxStorage() << endl; //calls MaxStorage()

	bs3 = bs;														//calls operator=
	cout << "Operator= stack: \n" << bs3;							//calls operator<<

	cout << "The size of the stack before clear is: " << bs3.Size() << endl;	//calls Size()
	bs3.Clear();											//calls Clear()
	cout << "The size of the stack after being cleared is: " << bs3.Size() << endl;	//calls Size()
	

	cout << "------------------------------------------------------------" << endl;
	cout << "Queue tests: " << endl;
	Book book9;

	BookQueue bq = BookQueue();								//calls default constructor
	cout << bq;												//calls operator<<

	bq.Enqueue(book1);										//calls Enqueue()
	bq.Enqueue(book2);										//calls Enqueue()
	bq.Enqueue(book3);										//calls Enqueue()
	bq.Enqueue(book4);										//calls Enqueue()

	cout << "After enqueues: \n" << bq;						//calls operator<<
	cout << "The size of the queue is: " << bq.Size() << endl;	//calls Size()

	BookQueue bq2 = BookQueue(bq);							//calls copy constructor
	cout << "Copy constructed queue: \n" << bq2;			//calls operator<<

	cout << "The size of the queue before dequeue is: " << bq.Size() << endl;	//calls Size()
	if (bq.Dequeue(book9) == true) {							//calls Dequeue()
		cout << "Dequeue worked and removed: \n" << book9 << endl;
	}
	else {
		cout << "Dequeue failed." << endl;
	}
	cout << "The size of the queue after dequeue is: " << bq.Size() << endl;	//calls Size()

	cout << "After dequeue: \n" << bq;						//calls operator<<

	BookQueue bq3 = bq;										//calls operator=
	cout << "Operator= queue: \n" << bq3;

	cout << "The size of the queue before clear is: " << bq2.Size() << endl;	//calls Size()
	bq2.Clear();											//calls Clear()
	cout << "The size of the queue after being cleared is: " << bq2.Size() << endl;	//calls Size()

	cout << endl;
	return 0;
}