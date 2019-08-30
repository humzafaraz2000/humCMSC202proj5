//Name: EReader.cpp
//Author: Humza Faraz
//Date: 4/30/19
//Section: 32
//E-mail: hfaraz1@umbc.edu
//Description: Represents an EReader
#include "EReader.h"

using namespace std;

//Name: EReader - Default Constructor
//Precondition: None
//Postcondition: Creates a new EReader
EReader::EReader(){
    
}

//Name: EReader - Overloaded Constructor
//Precondition: None
//Postcondition: Creates a new EReader and passes the book filename
EReader::EReader(string filename){
  LoadCatalog(filename);
}

//Name: ~EReader - Destructor
//Precondition: None
//Postcondition: Creates a new EReader
EReader::~EReader(){
  for (int i = 0; i < (int)m_bookCatalog.size(); i++){
    delete m_bookCatalog.at(i);
  }
}
//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file into the m_bookCatalog (as books)
void EReader::LoadCatalog(string filename){
  ifstream myfile;
  string title, author, rank;
  double price;
  myfile.open(filename);
  if (myfile.is_open()){
    while (getline(myfile, title, ',')){
      getline(myfile, author, ',');
      getline(myfile, rank, ',');
      myfile >> price;
      int rank1 = atoi(rank.c_str());
      
      Book *newBook = new Book(title, author, rank1, price);
      
      m_bookCatalog.push_back(newBook);
      
    }
    cout << "File opened" << endl;
  }
  else{
    cout << "File cannot be opened." << endl;
  }
  myfile.close();
}

//Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu
void EReader::MainMenu(){
  cout << "Welcome to UMBC E-Reader" << endl;
  //LoadCatalog();
  cout << "Catalog populated with " << m_bookCatalog.size() << " books." << endl;
  int choice = 0;
  cout << "What would you like to do?" << endl <<
    "1. Display All Books" << endl << 
    "2. Add book to Readlist" << endl <<
    "3. Display Readlist" << endl <<
    "4. Sort readlist by price" << endl <<
    "5. Exit" << endl;
  cin >> choice;
  while (choice != EXIT){
    if (choice == 1){
      DisplayBooks();
      
      cout << "What would you like to do?" << endl <<  
        "1. Display All Books" << endl << 
        "2. Add book to Readlist" << endl <<
        "3. Display Readlist" << endl <<
        "4. Sort readlist by price" << endl <<
        "5. Exit" << endl;
      cin >> choice;
    }
    else if (choice == 2){
      AddBook();
      cout << "What would you like to do?" << endl <<  
        "1. Display All Books" << endl << 
        "2. Add book to Readlist" << endl <<
        "3. Display Readlist" << endl <<
        "4. Sort readlist by price" << endl <<
        "5. Exit" << endl;
      cin >> choice;
    }
    else if (choice == 3){
      DisplayReadlist();
      cout << "What would you like to do?" << endl <<  
        "1. Display All Books" << endl << 
        "2. Add book to Readlist" << endl <<
        "3. Display Readlist" << endl <<
        "4. Sort readlist by price" << endl <<
        "5. Exit" << endl;
      cin >> choice;
    }
    else if (choice == 4){
      SortReadlist();
      cout << "What would you like to do?" << endl <<  
        "1. Display All Books" << endl << 
        "2. Add book to Readlist" << endl <<
        "3. Display Readlist" << endl <<
        "4. Sort readlist by price" << endl <<
        "5. Exit" << endl;
      cin >> choice;
    }
    else{
      cout << "Invalid. Enter 1-5 only" << endl;
    }
  }
  cout << "Thank you for using UMBC E-Reader" << endl;
}

//Name: DisplayBooks
//Precondition: Displays all 150 books
//Postcondition: Lists all books (numbered)
void EReader::DisplayBooks(){
  for (int i = 0; i < (int)m_bookCatalog.size(); i++){
    
    cout << *m_bookCatalog.at(i) << endl;
  }
}

//Name: AddBook
//Precondition: m_bookCatalog is populated
//Postcondition: Displays the current list and adds a book
//               to the m_readList
void EReader::AddBook(){
  int choice = 0;
  cout << "Choose which book you'd like to add to your read list." << endl;
  DisplayBooks();
  cout << "Enter the number ofthe book you would like to add:" << endl;
  cin >> choice;
  for (int i = 0; i < (int)m_bookCatalog.size(); i++){
    if (m_bookCatalog.at(i)->getRank() == choice){
      m_readList.Push(*m_bookCatalog.at(i), 1);
    }
  }
}
//Name: DisplayReadlist
//Precondition: None (can be empty)
//Postcondition: Displays the readlist
void EReader::DisplayReadlist(){
  m_readList.Display();
}

//Name: SortReadlist()
//Precondition: Requires Readlist
//Postcondition: Uses the overloaded < operator in Book to sort
//               the prices from high to low in the m_readList
void EReader::SortReadlist(){
  for (int j = 0; j < (int)m_readList.GetSize(); j++){
    for(int i = 1; i < (int)m_readList.GetSize(); i++){
      if (m_readList[i-1] < m_readList[i]){
        m_readList.Swap(i);
      }
    }
  }
}
