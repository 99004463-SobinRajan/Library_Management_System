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


class Library
{
    
public:
    std::list<Book> books;
    std::list<student> students;
    std::list<librarian> librarians;
    Library(/* args */);
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


    ~Library();
};




#endif