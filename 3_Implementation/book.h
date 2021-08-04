#ifndef __BOOK_H__
#define __BOOK_H__

#include"iostream"

class Book {
    private:
        int m_id;
        std::string m_title;
        std::string m_author;
        std::string m_publisher;
        int m_price;
        int m_pages;

    public:
        Book();
        Book(int id, std::string title, std::string author,std::string publisher, int price, int pages);
        Book(const Book& ref);
        int GetId() const;
        void SetId(int id);
        std::string GetTitle() const ;
        void SetTitle(std::string title);
        int GetPages() const;
        void SetPages(int pages);
        int GetPrice() const; 
        void SetPrice(int price);
        std::string GetAuthor() const;
        void SetAuthor(std::string author);
        std::string GetPublisher() const;
        void SetPublisher(std::string publisher);
        friend void operator<<(std::ostream& os, const Book& ref);
        void display();

};

#endif