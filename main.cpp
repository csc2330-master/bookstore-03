#include "library.h"
#include "book.h"

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

unsigned int menu();


int main() {
    unsigned int option;
    Library library;
    while ( (option = menu()) != 3){
        if (option == 1){
            // Add Book
            bool flag;
            string name;
            double price;
            cout << "Name: ";
            cin >> name;
            cout << "Price: ";
            cin >> price;
            flag = library.AddBook(name, price);
            if (!flag){
                cerr << "The Library is full" << endl;
            }else{
                cout << "Book added Correctly" << endl;
            }
        }else if (option == 2){
            // list Books
            for (int i = 0; i < library.GetCount(); ++i) {
                cout << library.Get(i)->ToString() << endl;
            }
        }else {
            // Get out
            cerr << "Danger Will Robinson, something is wrong!" << endl;
        }
    }
    return 0;
}

unsigned int menu(){
    unsigned int option;
    while (true){
        cout << "Library Operations" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. List Books" << endl;
        cout << "3. Exit" << endl;
        cin >> option;
        if (cin.fail()){
            cin.clear();
            cin.ignore(255, '\n');
            cerr << "Invalid input please do it again" << endl << endl;
            continue;
        }
        if (option == 0 || option > 3){
            cerr << "Invalid menu option, please input 1, 2 or 3" << endl << endl;
            continue;
        }
        break;

    }
    return option;
}
