#include"library.h"
#include"user.h"
#include"iostream"
#include<fstream>
#include<string>
#include<mqueue.h>
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


double Library::findAveragePrice(){
    double sum=0;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        sum=sum+p->GetPrice();
    }
    double avg=sum/books.size();
    return avg;
}


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


double Library::findAveragePriceByPublisher(std::string publisher){
    double sum=0;
    int count = 0;
    std::list<Book> :: iterator p;
    for(p=books.begin();p!=books.end();p++){
        if (p->GetPublisher()==publisher)
        {
            sum=sum+p->GetPrice();
            count++;
        }   
    }
    
    double avg=sum/count;
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

librarian* Library::getLibrarianByUsername(std::string username){
    std::list<librarian> :: iterator p;
    for (p=librarians.begin(); p!=librarians.end(); p++)
    {
        if(p->getUsername()==username){
            return &(*p);
        }
    }
    return NULL;
    
}
student* Library::getStudentById(int id){
    std::list<student> :: iterator p;
    for(p=students.begin();p!=students.end();p++){
        if(p->getId()==id){
            return &(*p);
        }
    }
    return NULL;

} 

bool Library::authenticate(std::string username, std::string password){
    librarian *ptr = getLibrarianByUsername(username);
    if(ptr->getPassword()==password){
        return true;
    }
    else{
        return false;
    }
}

bool Library::orderIssueBook(int stu_id, int b_id){

    std::string msg = std::to_string(stu_id)+","+ std::to_string(b_id);

    int ret;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);

	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	// char str[]=msg;
    const char *cstr = msg.c_str();
	int len=strlen(cstr);
	ret=mq_send(mqid,cstr,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
    return true;



}

bool Library::acceptIssueBook(){




    int ret,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256;
    u_int prio;
	nbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	// printf("receive msg:%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
    std::string str = buf;
    std::string delimiter = ",";
    int sid = std::stoi(str.substr(0, str.find(delimiter)));
    int bid = std::stoi(str.substr(str.find(delimiter), str.size()));
    student *stu = getStudentById(sid);
    Book *book = findBookByID(bid);

    stu->setLastIssuedBookId(book->GetId());

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::stringstream date;
    date<<now->tm_mday<<'/'<<(now->tm_mon + 1)<<'/'<<(now->tm_year + 1900) <<"\n";
    std::string datee = date.str();
    stu->setDate(datee);
    stu->setFineDue(0);
	mq_close(mqid);
    std::cout<<"Book Issued"<<std::endl;
    return true;



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
    // l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    // Book *ptr= l1.findBookByID(1);
    // std::cout<< ptr->GetId()<<std::endl;
    std::cout<<"Are you student or librarian? \nPress 1 for student and press 2 for Librarian"<<std::endl;
    int input;
    std::cin>>input;
    if (input==1)
    {
        std::cout<<"Please enter your id"<<std::endl;
        int s_id;
        std::cin>>s_id;
        std::cout<<"Please enter book id"<<std::endl;
        int b_id;
        std::cin>>b_id;
        bool isOrderPlaced=l1.orderIssueBook(s_id, b_id);
        if(isOrderPlaced){
            std::cout<<"your order placed"<<std::endl;
        }
    }
    else if (input==2)
    {   
        std::cout<<"Please Enter your Username"<<std::endl;
        std::string username;
        std::cin>>username;
        std::cout<<"Please Enter your Password"<<std::endl;
        std::string password;
        std::cin>>password;
        bool check = l1.authenticate(username, password);
        if(check){
            bool isOrderAccepted = l1.acceptIssueBook();
        }
        
    }

}
