#include <iostream>

using namespace std;

struct Book{
  string isbn;
  string genre;
  int numpages;
  string author;
  string title;
  bool checkedOut;
};
typedef struct Book Book;

struct Library{
  int numbooks;
  int capacity = 100;
  Book books[100];
};
typedef struct Library Library;

Library initializeLibrary();
void displayBook(Book book);
void displayMenu();
void registerMenu(Library myLibrary);
Library addBookToLib(Library myLibrary);
void searchBook(Library myLibrary);
Library checkout(Library myLibrary);
Library bookReturn(Library myLibrary);

int main() {
  Library myLibrary = initializeLibrary();
  cout << "  --------- Library Managment System ---------" << endl << endl;
  registerMenu(myLibrary);
  cout << "Goodbye!" << endl;
  return 0;
}

Library bookReturn(Library myLibrary)
{
  string returnTitle;
  cout << " what is the title? ";
  getline(cin, returnTitle);
  for(int i=0;i<myLibrary.numbooks;i++)
  {
    if(!myLibrary.books[i].title.compare(returnTitle))
    {
      myLibrary.books[i].checkedOut = false;
      cout << " your book has been returned" << endl;
      return myLibrary;
    }
  }
  cout << "Unable to find title" << endl;
  return myLibrary;
}

Library checkout(Library myLibrary)
{
  string checkOutTitle;
  cout << " what is the title? ";
  getline(cin, checkOutTitle);
  for(int i=0;i<myLibrary.numbooks;i++)
  {
    if(!myLibrary.books[i].title.compare(checkOutTitle))
    {
      if (!myLibrary.books[i].checkedOut)
      {
        myLibrary.books[i].checkedOut = true;
        cout << "this book has been checked out" << endl;
      }
      else
      {
        cout << "sorry, this was already checked out" << endl;
      }
      return myLibrary;
    }
  }
  cout << "Unable to find title" << endl;
  return myLibrary;
}

void searchBook(Library myLibrary)
{
  string searchedTitle;
  cout << " what is the title? ";
  getline(cin, searchedTitle);
  for(int i=0;i<myLibrary.numbooks;i++)
  {
    if(!myLibrary.books[i].title.compare(searchedTitle))
    {
      displayBook(myLibrary.books[i]);
    }
  }
}

Library addBookToLib(Library myLibrary)
{
  Book b;
  cout << " what is the author? ";
  getline(cin, b.author);
  cout << " what is the title? ";
  getline(cin, b.title);
  cout << " what is the genre? ";
  getline(cin, b.genre);
  cout << " what is the number of pages? ";
  string temp;
  getline(cin, temp);
  b.numpages = stoi(temp);
  cout << " what is the ISBN? ";
  getline(cin, b.isbn);
  b.checkedOut = false;
  myLibrary.books[myLibrary.numbooks] = b;
  myLibrary.numbooks++;
  return myLibrary;
}

void displayMenu() {
  cout << "Main menu:" << endl;
  cout << "option 1: add book" << endl;
  cout << "option 2: checkout book" << endl;
  cout << "option 3: search" << endl;
  cout << "option 4: return" << endl;
  cout << "option 5: exit" << endl;
}

void displayBook(Book book) {
  cout << "\t" << "Title:  " << book.title << endl;
  cout << "\t" << "Author: " << book.author << endl;
  cout << "\t" << "ISBN:   " << book.isbn << endl;
}

Library initializeLibrary() {
  Library lib;
  lib.numbooks = 2;
  Book book1;
  book1.isbn = "1234";
  book1.genre = "Fantasy";
  book1.numpages = 123;
  book1.author = "A";
  book1.title = "Hello";
  book1.checkedOut = false;
  lib.books[0] = book1;
  Book book2;
  book2.isbn = "4567";
  book2.genre = "Mystery";
  book2.numpages = 124;
  book2.author = "B";
  book2.title = "Hlo";
  book2.checkedOut = false;
  lib.books[1] = book2;
  return lib;
}

void registerMenu(Library myLibrary)
{
  int choice;
  string option;
  while (true)
  {
    displayMenu();
    cout << "choose option: ";
    getline(cin, option);
    choice = stoi(option);
    if (choice == 1)
    {
      myLibrary = addBookToLib(myLibrary);
    }
    else if (choice == 2)
    {
      myLibrary = checkout(myLibrary);
    }
    else if (choice == 3)
    {
      searchBook(myLibrary);
    }
    else if (choice == 4)
    {
      myLibrary = bookReturn(myLibrary);
    }
    else
    {
      return;
    }
  }
}
