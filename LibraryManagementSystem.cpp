#include <bits/stdc++.h>
using namespace std;
class Book
{
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
  Book(string sTitle, string sAuthor, string sISBN, bool sAvailable)  //Parameterizeed Constructor
    {
        title = sTitle;
        author = sAuthor;
        isbn = sISBN;
        available = sAvailable;
    }
    // void setTitle(string sTitle)
    // {
    //     title = sTitle;
    // }
    // void setAuthor(string sAuthor)
    // {
    //      author = sAuthor;
    // }
    // void setISBN(string sISBN)
    // {
    //       isbn = sISBN;
    // }
    // void setAvailable(bool sAvailable)
    // {
    //     available = sAvailable;
    // }
  
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getISBN()
    {
        return isbn;
    }
    bool getAvailable()
    {
        return available;   
    }
};
void addNewBook(vector<Book> &books) {
    string ltitle;
    string lauthor;
    string lisbn;
    bool lavailable;
    cout << "Enter ISBN :";
    cin >> lisbn;

    // Check if book already present
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == lisbn) {
            cout << "Book Already Present..." << endl;
            return;
        }
    }

    cout << "Proceed....." << endl;
    cout << "Enter Name of Book:";
    cin >> ltitle;
    cout << "Enter Name of Author :";
    cin >> lauthor;
    cout << "Enter ISBN of book :";
    cin >> lisbn;
    cout << "Is Now Available? ";
    cin >> lavailable;

    Book newBook(ltitle, lauthor, lisbn, lavailable);
    books.push_back(newBook);
    cout << ltitle << " Book successfully added!!!"<<endl;
}

void removeBook(vector<Book> &books) {
    string isbn1;
    cout << "Enter ISBN of book to delete: ";
    cin >> isbn1;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == isbn1) {
            books.erase(books.begin() + i);
            cout <<books[i].getTitle()<< " Book Deleted Successfully!!!" << endl;
            return; // Return after deleting the book
        }
    }
    cout << "Book Not Found!!!" << endl;
}
void searchBook(vector<Book> &books){
    string namebook;
    cout << "Enter the name of book you want to search:";
    cin >> namebook;
    for (int i = 0; i < books.size();i++){
        if(books[i].getTitle()==namebook){
            cout << "Book is Available at rack no: " << i + 1;
            return;
        }}
    
        cout << "Book Not Available!!!SORRY";
        
    }

int main()
{
    vector<Book> books;
    books.push_back(Book("HarryPotter", "J.K.Rowling", "#00fff", true));
    char choice;
   
    do{
        system("cls");
         int op;
        cout << "---------------------------------"<<endl;
        cout << "Welcome to Library Management System"<<endl;
        cout << "---------------------------------"<<endl;
        cout << "Menu :" << endl;
        cout << "1. Add Book"<<endl;
        cout << "2.Remove Book"<<endl;
        cout << "3.Search for Book"<<endl;
        cout << "4.Exit"<<endl;
        cout << endl;
        cout << "Enter Your Choice:";
        cin >> op;
        switch(op){
            case 1:
                addNewBook(books);
                break;
            case 2:
                removeBook(books);
                break;
            case 3:
                searchBook(books);
                break;
            case 4:
                exit(1);
            default:
                cout << "Invalid Number" << endl;
        }
        cout << "Do you want to continue[Yes/No]:";
        cin >> choice;
    } while (choice=='y' || choice=='Y');

}
