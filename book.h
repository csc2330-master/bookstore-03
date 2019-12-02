//
// Created by arias on 11/25/2019.
//

#ifndef BOOKSTORE_01_BOOK_H
#define BOOKSTORE_01_BOOK_H

#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Book {
    string _name;
    double _price;
public:
    Book(const string&, double);
    Book(const Book&);
    string ToString()const;
    void Write(ostream&)const;
    bool Read(istream&);
    double GetPrice()const;
    bool Equals(const Book&)const;
};


#endif //BOOKSTORE_01_BOOK_H
