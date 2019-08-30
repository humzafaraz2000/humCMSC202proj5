//Name: Book.cpp
//Author: Humza Faraz
//Date: 4/30/19
//Section: 32
//E-mail: hfaraz1@umbc.edu
//Description: Represents a book

#include "Book.h"

using namespace std;

//Name: Book - Default Constructor
//Precondition: None
//Postcondition: Creates a default book
Book::Book(){
  
}

//Name: Book - Overloaded Constructor
//Precondition: Requires title, author, rank and price (in dollars)
//Postcondition: Creates a book based on passed parameters
Book::Book(string title, string author, int rank,  double price){
  m_title = title;
  m_author = author;
  m_rank = rank;
  m_price = price;
}

//Name: Mutators and Accessors
//Precondition: None
//Postcondition: Sets and Gets private member variables
string Book::getTitle()const{
  return m_title;
} // return title
string Book::getAuthor()const{
  return m_author;
} // return author
int Book::getRank()const{
  return m_rank;
} // return rank (1-150)
double Book::getPrice()const{
  return m_price;
} // return price 
void Book::setTitle(string title){
  m_title = title;
}
void Book::setAuthor(string author){
  m_author = author;
}
void Book::setRank(int rank){
  m_rank = rank;
}
void Book::setPrice(double price){
  m_price = price;
}

// Overloaded << - Prints the details of a book
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with details of a book
std::ostream& operator<<(ostream &output, Book &myBook){
  output << myBook.getRank() << ". " << myBook.getTitle() << "\t" << myBook.getAuthor() << "\t" << myBook.getPrice() << endl;
  return output;
}

// Overloaded < - compares the price of the book
// Preconditions: all variables are set valid
// Postconditions: returns true if lhs price is less than rhs price
bool operator< (Book const & lhs, Book const & rhs){
  if (lhs.m_price < rhs.m_price){
    return true;
  }
  else{
    return false;
  }
}