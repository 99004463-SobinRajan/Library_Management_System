#include"user.h"

user::user(std::string name, int id, std::string role, std::string address): u_id(id), u_name(name), u_role(role), u_address(address)
{
    
}

void user::setId(const int id){
    u_id = id;
}

int user::getId() const{
    return u_id;
}

void user::setName(const std::string name){
    u_name = name;
}

std::string user::getName() const{
    return u_name;
}

void user::setRole(const std::string role){
    u_role = role;
}

std::string user::getRole() const{
    return u_role;
}

void user::setAddress(const std::string address){
    u_address = address;
}

std::string user::getAddress() const{
    return u_address;
}

user::~user()
{
}





student::student(std::string name, int id, std::string role, std::string address): user(name, id, role, address), s_total_books_issued(0), s_fine_due(0), s_last_issued_book_id(0), s_status("idle"), s_date("00/00/0000")
{
}

void student::setTotalBookIssued(const int total_book_issued){
    s_total_books_issued = total_book_issued;
}

int student::getTotalBooksIssued() const{
    return s_total_books_issued;
}

void student::setFineDue(const int fine_due){
    s_fine_due = fine_due;
}

int student::getFineDue() const{
    return s_fine_due;
}

void student::setLastIssuedBookId(const int last_book_issued_id){
    s_last_issued_book_id = last_book_issued_id;
}

int student::getLastIssuedBookId() const{
    return s_last_issued_book_id;
}

void student::setStatus(const std::string status){
    s_status = status;
}

std::string student::getStatus() const{
    return s_status;
}

void student::setDate(const std::string date){
    s_date = date;
}


// void student::issueBook(){
    
// }

// void student::returnBook(){
    
// }

student::~student()
{
}




librarian::librarian(std::string name, int id, std::string role, std::string address): user(name, id, role, address), l_username(name), l_password("password")
{

}

void librarian::setUsername(const std::string username){
    l_username = username;
}

std::string librarian::getUsername() const{
    return l_username;
}

void librarian::setPassword(const std::string password){
    l_password = password;
}

std::string librarian::getPassword() const{
    return l_password;
}

// void librarian::issueBook(){
    
// }

// void librarian::returnBook(){
    
// }

librarian::~librarian()
{
}