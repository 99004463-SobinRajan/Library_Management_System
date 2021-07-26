#ifndef __USER_H__
#define __USER_H__

#include<iostream>
#include<ctime>

/**
 * @brief 
 * 
 */
class user
{
private:
    int u_id;
    std::string u_name;
    std::string u_role;
    std::string u_address;
public:
    user(std::string name, int id, std::string role, std::string address);
    void setId(const int id);
    int getId() const;
    void setName(const std::string id);
    std::string getName() const;
    void setRole(const std::string role);
    std::string getRole() const;
    void setAddress(const std::string address);
    std::string getAddress() const;

    // virtual void issueBook() = 0;
    // virtual void returnBook() = 0;
    
    ~user();
};

/**
 * @brief 
 * 
 */
class student: public user
{
private:
    int s_total_books_issued;
    int s_fine_due;
    int s_last_issued_book_id;
    std::string s_date;
    std::string s_status; 
public:
    student(std::string name, int id, std::string role, std::string address);
    void setTotalBookIssued(const int total_book_issued);
    int getTotalBooksIssued() const;
    void setFineDue(const int fine_due);
    int getFineDue() const;
    void setLastIssuedBookId(const int last_issued_book_id);
    int getLastIssuedBookId() const;
    void setDate(const std::string date);
    std::string getDate() const;
    void setStatus(const std::string status);
    std::string getStatus() const;

    // void issueBook();
    // void returnBook();
    ~student();
};

class librarian: public user
{
private:
    std::string l_username;
    std::string l_password;
public:
    librarian(std::string name, int id, std::string role, std::string address);
    void setUsername(const std::string username);
    std::string getUsername() const;
    void setPassword(const std::string password);
    std::string getPassword() const;

    // void issueBook();
    // void returnBook();
    // void changeFine();
    ~librarian();
};

#endif