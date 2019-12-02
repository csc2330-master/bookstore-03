//
// Created by arias on 11/25/2019.
//

#include "library.h"

Library::Library(const Library& library){
	_head = nullptr;
	_size = 0;
	for (Node* tmp = library._head; tmp != nullptr; tmp = tmp->next){
		Insert(*(tmp->data), _size);
	}
}
Library::Library(){
	_head = nullptr;
	_size = 0;
}
Library::~Library(){
  	// TODO
}
size_t Library::GetCount()const{
  return _size;
}
bool Library::AddBook(const Book& book){
  return Insert(book, _size);
}
bool Library::AddBook(const string& name, double price){
  return Insert(Book(name, price), _size);
}
int Library::FindBook(const string& name)const{
  return IndexOf(Book(name, 0.0));
}

// Methods from ADT in Class:
size_t Library::GetSize(){
  return _size;
}
bool Library::Insert(const Book& book, size_t position){
  if (position > _size){
		return false;
	}
	Node* neo = new Node;
	neo->data = new Book(book);
	neo->next = nullptr;
	if (_head == nullptr){
		_head = neo;
	}else if (position == 0){
		neo->next = _head;
		_head = neo;
	}else{
		Node* tmp = _head;
		for (size_t i = 0; i < position - 1; i++) {
			tmp = tmp->next;
		}
		neo->next = tmp->next;
		tmp->next = neo;
	}
	_size++;
	return true;
}
bool Library::Insert(const string& name, double price, size_t position){
  return Insert(Book(name, price), position);
}
int Library::IndexOf(const Book& book)const{
  // Bad Implementation, Why?
	for (size_t i = 0; i < _size; i++) {
		Book* currentBook = Get(i);
		if (currentBook->Equals(book)){
			return i;
		}
	}
	return -1;
}
Book* Library::Get(size_t position)const{
  if (position >= _size){
		return nullptr;
	}
	Node* tmp = _head;
	for (size_t i = 0; i < position; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}
