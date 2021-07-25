#include"library.h"
#include"iostream"
#include<fstream>
#include<string>
#include<sstream>

Library::Library(/* args */)
{
    int id;
    std::string title;
    std::string author;
    std::string publisher;
    int price;
    int page;
    std::fstream fptr;
    std::string temp;
    fptr.open("library.csv", std::ios::in);
    std::string word="";
    int index = 0;
        
        getline(fptr,temp);
        getline(fptr,temp);
    while(fptr){
        std::stringstream s(temp);
        getline(s, word, ',');
        std::stringstream s1;
        s1 << word;
        s1 >> id;
        getline(s, word, ',');
        title = word;
        getline(s, word, ',');
        author = word;
        getline(s, word, ',');
        publisher = word;
        getline(s, word, ',');
        std::stringstream s2;
        s2 << word;
        s2 >> price;
        getline(s, word, ',');
        std::stringstream s3;
        s3 << word;
        s3 >> page;
        books.emplace_back(id, title, author, publisher, price, page);
        getline(fptr, temp);
    }
    fptr.close();
}

void Library::addBook(int id, std::string title, std::string author, std::string publisher, int price, int page){
    books.emplace_back(id, title, author, publisher, price, page);
}

void Library::removeBookByID(int id){
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if(p->GetId()==id){
            books.erase(p);
            break;
        }
    } 
}

void Library::displayAll(){
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        p->diplay();
    }
}

Book* Library::findBookByID(int id){
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if(p->GetId()==id){
            return &(*p);
        }
    }
    return NULL;
}

//error
double Library::findAveragePrice(){
    double sum=0;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        sum=sum+p->GetPrice();
    }
    double avg=sum/books.size();
    return avg;
}

//error
Book Library::findBookWithMaxPages(){
    int max=INT_MIN;
    // int id=0;
    std::list<Book> :: iterator p;
    std::list<Book>::iterator maxiter;
    for(p=books.begin();p!=books.end();p++){
        if(p->GetPages()>=max){
            max=p->GetPages();
            maxiter=p;
        }
    }
    return *maxiter;
}

std::list<Book> Library::fiandAllBookByAuthor(std::string author){
    std::list<Book> templist;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if(p->GetAuthor()==author){
            templist.push_back(*p);
        }
    }
    return templist;
}

Book Library::findBookWithMinPrice(){
    int min=INT_MAX;
    std::list<Book> :: iterator p;
    std::list<Book>::iterator miniter;
    for(p=books.begin();p!=books.end();p++){
        if(p->GetPrice()<min){
            min=p->GetPrice();
            miniter=p;
        }
    }
    return *miniter;
}

//error
double Library::findAveragePriceByPublisher(std::string publisher){
    double sum=0;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if (p->GetPublisher()==publisher)
        {
            sum=sum+p->GetPrice();
        }   
    }
    double avg=sum/books.size();
    return avg;
}

int Library::countBookAtRange(int start, int end){
    int count=0;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if (p->GetPrice()>=start && p->GetPrice()<=end)
        {
            count++;
        }   
    }
    return count;
}

int Library::countBookLessThan(int limit){
    int count=0;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if (p->GetPrice()<=limit)
        {
            count++;
        }   
    }
    return count;
}

Book Library::findMinOfPublisher(std::string publisher){
    int min=INT_MAX;
    int id=0;
    std::list<Book> :: iterator p;
    std::list<Book> :: iterator miniter;
    for(p=books.begin();p!=books.end();p++){
        if(p->GetPublisher()==publisher){
            if(p->GetPrice()<min){
                min=p->GetPrice();
                miniter=p;
            }
        }
    }

    return *miniter;
}

Library::~Library()
{
    std::fstream fdes;
    fdes.open("library.csv", std::ios::out);
    fdes<<"ID,Title,Author,Publisher,Price,Pages"<<std::endl;
    std::list<Book> ::iterator iter;
    for( iter = books.begin(); iter != books.end(); iter ++ ){
        fdes<< iter->GetId()<<","<<iter->GetTitle()<<","<<iter->GetAuthor()<<","<<iter->GetPublisher()
        <<","<<iter->GetPrice()<<","<<iter->GetPages()<<std::endl;
    }
}

int main(){
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    // Book *ptr= l1.findBookByID(1);
    // std::cout<< ptr->GetId()<<std::endl;
}
