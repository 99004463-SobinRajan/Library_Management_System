
#include"book.h"


Book::Book(){
}

Book::Book(int id, std::string title, std::string author, std::string publisher, int price, int pages): m_id(id), m_title(title), m_publisher(publisher), m_author(author), m_price(price), m_pages(pages){ 
}

Book::Book(const Book& ref):m_id(ref.m_id), m_title(ref.m_title), m_author(ref.m_author), m_price(ref.m_price), m_pages(ref.m_pages){
}

int Book::GetId() const {
    return m_id;
}

void Book::SetId(int id) {
    m_id = id;
}
    
std::string Book::GetTitle() const {
    return m_title;
}

void Book::SetTitle(std::string title) {
    m_title = title;
}

int Book::GetPages() const {
    return m_pages;
}

void Book::SetPages(int pages) {
    m_pages = pages;
}
   
int Book::GetPrice() const {
    return m_price;
}

void Book::SetPrice(int price) {
    m_price = price;
}

std::string Book::GetAuthor() const {
    return m_author;
}

void Book::SetAuthor(std::string author) {
    m_author = author;
}

std::string Book::GetPublisher() const{
    return m_publisher;
}
void Book::SetPublisher(std::string publisher){
    m_publisher=publisher;
}

void Book::diplay(){
    std::cout<<m_id<<std::endl;
    std::cout<<m_title<<std::endl;
    std::cout<<m_author<<std::endl;
    std::cout<<m_publisher<<std::endl;
    std::cout<<m_price<<std::endl;
    std::cout<<m_pages<<std::endl;
    std::cout<<"--------xxxxxxx---------"<<std::endl;

}

void operator<<(std::ostream& os, const Book& ref){
    os<<ref.GetId()<<std::endl;
    os<<ref.GetTitle()<<std::endl;
    os<<ref.GetPublisher()<<std::endl;
    os<<ref.GetAuthor()<<std::endl;
    os<<ref.GetPrice()<<std::endl;
    os<<ref.GetPages()<<std::endl;
    os<<"--------xxxxxxx---------"<<std::endl;
}
