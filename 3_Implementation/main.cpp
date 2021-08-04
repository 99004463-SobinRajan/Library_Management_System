#include"library.h"
#include <stdlib.h>
int main(){
    Library l1;
    l1.initialize_List();
    l1.initialize_StudentList();
    l1.initialize_LibrarianList();
    int input=0;
    std::cout<<"Welcome to Library management System"<<std::endl;
    // std::cout<<"press any key to continue"<<std::endl;

    while (true)
    {

        // std::cout << "\033[2J\033[1;1H";
        std::cout<<"Please choose from the option what you want to do "<<std::endl;
        std::cout<<"1 Find Book by Id \n"
                "2 Find Average Price \n"
                "3 Display all Book \n"
                "4 Book With Max Pages \n"
                "5 Search Book by author \n"
                "6 Book with minimum price \n"
                "7 Average Price by Publisher \n"
                "8 Count Book in a given range \n"
                "9 count book less then the given range \n"
                "10 Find minimum of publisher \n"
                "11 Librarian specific tasks \n"
                "12 Issue a book \n"
                "13 Return a book \n"
                "0 For exit \n";
        std::cin>>input;

        switch (input)
        {
        case 1:
        {
            int id;
            std::cout<<"Enter the id to search"<<std::endl;
            std::cin>>id;   
            Book *ptr=l1.findBookByID(id);
            ptr->display();
            break;
        }
        case 2:
        {
            double avg=l1.findAveragePrice();
            std::cout<<"Average price of books: "<<avg<<std::endl;
            break;
        }
        case 3:
        {
            l1.displayAll();
            break;
        }
        case 4:
        {
            Book mpage=l1.findBookWithMaxPages();
            mpage.display();
            break;
        }
        //error
        case 5:
        {
            std::string author;
            std::cout<<"Enter the author to search"<<std::endl;
            std::cin.ignore();
            std::getline(std::cin,author);
            std::list<Book> temp=l1.fiandAllBookByAuthor(author);
            std::list<Book>::iterator iter;
            for ( iter = temp.begin(); iter!=temp.end(); iter++)
            {
                iter->display();
            }
            break;
        }
        case 6:
        {
            Book ptr=l1.findBookWithMinPrice();
            ptr.display();
            break;
        }
        // error
        case 7:
        {
            std::string publisher;
            std::cout<<"Enter the publisher to search"<<std::endl;
            std::cin.ignore();
            std::getline(std::cin,publisher);
            std::cout<<l1.books.size()<<std::endl;
            double avg=l1.findAveragePriceByPublisher(publisher);
            std::cout<<"Average price of books by publisher: "<<avg<<std::endl;
            break;
        }
        case 8:
        {
            int upperLimit, lowerLimit;
            std::cout<<"Enter upper Limit"<<std::endl;
            std::cin>>upperLimit;
            std::cout<<"Enter lower Limit"<<std::endl;
            std::cin>>lowerLimit;
            int count=l1.countBookAtRange(lowerLimit, upperLimit);
            std::cout<<"Number of books in the range: "<<count<<std::endl;
            break;
        }
        case 9:
        {
            int upperLimit;
            std::cout<<"Enter upper Limit"<<std::endl;
            std::cin>>upperLimit;
            int count=l1.countBookLessThan(upperLimit);
            std::cout<<"Number of books bellow the range: "<<count<<std::endl;
            break;
        }
        // error
        case 10:
        {
            std::string publisher;
            std::cout<<"Enter the publisher to search"<<std::endl;
            std::cin.ignore();
            std::getline(std::cin,publisher);
            Book ptr=l1.findMinOfPublisher(publisher);
            ptr.display();  
            break;
        }
        case 11:
        {
            std::cout<<"Please Enter your Username"<<std::endl;
            std::string username;
            std::cin>>username;
            std::cout<<"Please Enter your Password"<<std::endl;
            std::string password;
            std::cin>>password;
            bool check = l1.authenticate(username, password);
            int input2=0;
            do
            {
                if(check)
                {
                    std::cout<<"1 Accept Issue Book \n"
                    "2 Accept Book return \n"
                    "3 Add book \n"
                    "4 Remove Book \n"
                    "5 Get student by Id \n"
                    "6 Get Librarian By username \n";
                std::cin>>input2;
                switch (input2)
                {
                case 1:
                {
                    bool isOrderAccepted = l1.acceptIssueBook();
                    if (isOrderAccepted)
                    {
                        std::cout<<"Book has been issued"<<std::endl;
                    }
                    break;
                }
                case 2:
                {
                    bool isOrderReturned = l1.acceptReturn();
                    if (isOrderReturned)
                    {
                        std::cout<<"Book has been returned"<<std::endl;
                    }
                    break;
                }
                case 3:
                {
                    int id;
                    std::string name;
                    std::string author;
                    std::string publisher;
                    int pages;
                    int price;
                    std::cout<<"Enter id, name, author, publisher, pages and price of book"<<std::endl;
                    std::cin>>id;
                    std::cin>>name;
                    std::cin>>author;
                    std::cin>>publisher;
                    std::cin>>pages;
                    std::cin>>price;
                    l1.addBook(id, name, author, publisher, price, pages);
                    std::cout<<"Book added successfully"<<std::endl;
                }
                case 4:
                {
                    int id;
                    std::cout<<"Enter id of book top return"<<std::endl;
                    std::cin>>id;
                    l1.removeBookByID(id);
                    std::cout<<"Book removed"<<std::endl;
                }
                case 5:
                {
                    int id;
                    std::cout<<"Enter id of student "<<std::endl;
                    std::cin>>id;
                    student *stu=l1.getStudentById(id);
                    std::cout<<stu->getName()<<std::endl;                    
                }
                case 6:
                {
                    std::string username;
                    std::cout<<"Enter username of student "<<std::endl;
                    std::cin>>username;
                    librarian *lib = l1.getLibrarianByUsername(username);
                    std::cout<<lib->getName()<<std::endl;
                }
                default:
                    break;
                }

                }
            } while (input2!=0);
            
            break; 
        }
        case 12:
        {
            std::cout<<"Please enter your id"<<std::endl;
            int s_id;
            std::cin>>s_id;
            std::cout<<"Please enter book id"<<std::endl;
            int b_id;
            std::cin>>b_id;
            bool isOrderPlaced=l1.orderIssueBook(s_id, b_id);
            if(isOrderPlaced){

                std::cout<<"your issue order has been placed"<<std::endl;

            }
            break;
        }
        case 13:
        {
            std::cout<<"Please enter your id"<<std::endl;
            int s_id;
            std::cin>>s_id;
            bool isBootReturn = l1.orderReturn(s_id);
            if(isBootReturn){
                std::cout<<"your return order has been placed "<<std::endl; 
            }
            break;

        }
        case 0:
        {
            std::cout<<"Thank you for visiting!!"<<std::endl;
            exit(0);
            break;
        }
        default:
            break;
        }

    }
    
}