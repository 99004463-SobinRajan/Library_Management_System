#include<iostream>
#include<ctime>
using namespace std;

class user
{
private:
    int id;
    string name;
    string role;
    string address;
public:
    user(string name, int id, string role, string address);
    int getId();
    string getName();
    string getRole();
    string getAddress();
    virtual void issueBook() = 0;
    virtual void returnBook() = 0;
    virtual int getTotalBooksIssued();
    ~user();
};

user::user(string c_name, int c_id, string c_role, string c_address): id(c_id), name(c_name), role(c_role), address(c_address) {}

int user::getId(){
    return id;
}

string user::getName(){
    return name;
}

string user::getRole(){
    return role;
}

string user::getAddress(){
    return address;
}

user::~user()
{
}

class student: public user
{
private:
    int total_books_issued;
    int fine_due;
    string last_issued_book_id;
    time_t date;
    string status; 
public:
    student(string name, int id, string role, string address);
    int getTotalBooksIssued();
    void issueBook();
    void returnBook();
    ~student();
};

student::student(string name, int id, string role, string address): user(name, id, role, address), total_books_issued(0), fine_due(0), last_issued_book_id(0), date(time(nullptr)), status("idle")
{
    cout<<"object of student"<<endl;
}

int student::getTotalBooksIssued(){
    return total_books_issued;
}

void student::issueBook(){
    cout<<"issueBook of student"<<endl;
}

void student::returnBook(){
    cout<<"issueBook of student"<<endl;
}

student::~student()
{
}

class librarian: public user
{
private:
    string username;
    string password;
public:
    librarian(string name, int id, string role, string address);
    void issueBook();
    void returnBook();
    ~librarian();
};

librarian::librarian(string name, int id, string role, string address): user(name, id, role, address), username(name), password("password")
{
    cout<<"object of librarian"<<endl;
}

void librarian::issueBook(){
    cout<<"issueBook of librarian"<<endl;
}

void librarian::returnBook(){
    cout<<"issueBook of librarian"<<endl;
}

librarian::~librarian()
{
}

int main(){
    user *st  = new student("shubham", 11710408, "student", "Raipur");
    cout<<st->getId()<<endl;
    cout<<st->getTotalBooksIssued()<<endl;
    
    user *lib = new librarian("Astha", 2635960, "Librarian", "Jalandhar");

}