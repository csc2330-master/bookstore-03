//
// Created by arias on 11/25/2019.
//

#ifndef BOOKSTORE_01_LIBRARY_H
#define BOOKSTORE_01_LIBRARY_H

#include "book.h"
#include <string>
using std::string;


class Library {
    struct Node{
      Book* data;
      Node* next;
    };
    Node* _head;
    size_t _size;
    Library(const Library&);
public:
    Library();
    ~Library();
    size_t GetCount()const;
    bool AddBook(const Book&);
    bool AddBook(const string&, double);
    int FindBook(const string&)const;

    // Methods from ADT in Class:
    size_t GetSize();
    bool Insert(const Book&, size_t);
    bool Insert(const string&, double, size_t);
    int IndexOf(const Book&)const;
    Book* Get(size_t)const;



};


#endif //BOOKSTORE_01_LIBRARY_H
