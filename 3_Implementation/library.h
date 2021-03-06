#ifndef __LIBRARY_H__
#define __LIBRARY_H__
#include"book.h"
#include"user.h"
#include"iostream"
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include <ctime>
#include <sstream>
#include <bits/stdc++.h>
#include"list"
#include<fstream>
#include<sstream>
#include<string>


class Library
{
    
public:
    std::list<Book> books;
    std::list<student> students;
    std::list<librarian> librarians;
    Library(/* args */);
    void initialize_List();
    void initialize_StudentList();
    void initialize_LibrarianList();
    void addBook(int id, std::string title, std::string author, std::string publisher, int price, int page);
    void removeBookByID(int id);
    void displayAll();
    Book* findBookByID(int id);
    double findAveragePrice();
    Book findBookWithMaxPages();
    std::list<Book> fiandAllBookByAuthor(std::string author);
    Book findBookWithMinPrice();
    double findAveragePriceByPublisher(std::string publisher);
    int countBookAtRange(int start, int end);
    int countBookLessThan(int limit);
    Book findMinOfPublisher(std::string publisher);
    student* getStudentById(int id);
    librarian* getLibrarianByUsername(std::string username);
    bool authenticate(std::string username, std::string password);
    bool orderIssueBook(int stu_id, int b_id);
    bool acceptIssueBook();
    bool orderReturn(int stu_id);
    bool acceptReturn();
    int calculateFine(const char* date);
    int finePay(int s_id, int payment);


    ~Library();
};




#endif