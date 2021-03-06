#include"library.h"
#include"user.h"
#include"iostream"
#include<fstream>
#include<string>
#include<mqueue.h>
#include<sstream>

Library::Library(/* args */)
{
    
}

void Library::initialize_List(){
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

void Library::initialize_StudentList(){
    int id, total_books_issued, fine_due, last_issued_book_id;
    std::string name, role, address, date, status;
    std::fstream fptr;
    fptr.open("student.csv",std::ios::in);
    std::string temp="";
    std::string word = "";
    getline(fptr,temp);
    getline(fptr,temp);
    while(fptr){
        std::stringstream s(temp);
        getline(s,word,',');
        std:: stringstream s1;
        s1<<word;
        s1>>id;
        getline(s,word,',');
        name = word;
        getline(s,word,',');
        role = word; 
        getline(s,word,',');
        address = word; 
        getline(s,word,',');
        std:: stringstream s2;
        s2<<word;
        s2>>total_books_issued;
        getline(s,word,',');
        std:: stringstream s3;
        s3<<word;
        s3>>fine_due;      
        getline(s,word,',');
        std:: stringstream s4;
        s4<<word;
        s4>>last_issued_book_id;
        getline(s,word,',');
        date = word;
        getline(s,word,',');
        status = word;
        students.push_back(student(name, id, role, address));
        students.back().setTotalBookIssued(total_books_issued);
        students.back().setFineDue(fine_due);
        students.back().setLastIssuedBookId(last_issued_book_id);
        students.back().setDate(date);
        students.back().setStatus(status);
        getline(fptr,temp);
    }
    fptr.close();
}

void Library::initialize_LibrarianList(){
    int id;
    std::string name, role, address, username, password;
    std::fstream fptr;
    fptr.open("librarian.csv", std::ios::in);
    std::string temp="";
    std::string word="";
    getline(fptr, temp);
    getline(fptr, temp);
    while(fptr){
        std::stringstream ss(temp);
        getline(ss, word, ',');
        std::stringstream s1;
        s1 << word;
        s1 >> id;

        getline(ss, word, ',');
        name = word;

        getline(ss, word,',');
        role = word;

        getline(ss, word, ',');
        address = word;

        getline(ss, word, ',');
        username = word;

        getline(ss, word, ',');
        password = word;

        librarians.emplace_back(name, id, role, address);
        librarians.back().setUsername(username);
        librarians.back().setPassword(password);
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
        p->display();
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
	mqd_t mqissue;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqissue=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);

	if(mqissue<0)
	{
		perror("mq_open");
		exit(1);
	}
    const char *cstr = msg.c_str();
	int len=strlen(cstr);
	ret=mq_send(mqissue,cstr,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqissue);
    return true;

}

bool Library::acceptIssueBook(){

    int ret,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqissue;
	mqissue=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	if(mqissue<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256;
    u_int prio;
	nbytes=mq_receive(mqissue,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
    std::string str = buf;
    std::string delimiter = ",";
    std::string sid = str.substr(0, str.find(delimiter));
    std::string bid = str.substr(str.find(delimiter)+1, str.size());
    int n_sid = std::stoi(sid);
    int n_bid = std::stoi(bid);
    std::cout<<"sid "<<sid<<std::endl;
    std::cout<<"bid "<<bid<<std::endl;
    student *stu = getStudentById(n_sid);
    Book *book = findBookByID(n_bid);

    stu->setLastIssuedBookId(book->GetId());

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::stringstream date;
    date<<now->tm_mday<<'/'<<(now->tm_mon + 1)<<'/'<<(now->tm_year + 1900);
    std::string datee = date.str();
    stu->setDate(datee);
    stu->setFineDue(0);
    stu->setStatus("issued");
	mq_close(mqissue);
    std::cout<<"Book Issued"<<std::endl;
    return true;

}

bool Library::orderReturn(int stu_id){

    std::string msg = std::to_string(stu_id);

    int ret;
	mqd_t mqreturn;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqreturn=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);

	if(mqreturn<0)
	{
		perror("mq_open");
		exit(1);
	}
    const char *cstr = msg.c_str();
	int len=strlen(cstr);
	ret=mq_send(mqreturn,cstr,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqreturn);
    return true;

}

bool Library::acceptReturn(){
    
    int ret,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqreturn;
	mqreturn=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	if(mqreturn<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256;
    u_int prio;
	nbytes=mq_receive(mqreturn,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
    std::string str = buf;
    int n_sid = std::stoi(str);
    student *stu = getStudentById(n_sid);
    const char *cstr = stu->getDate().c_str();
    int totalFine = this->calculateFine(cstr);
    stu->setFineDue(totalFine);
    stu->setDate("00/00/0000");
    stu->setStatus("idle");
    mq_close(mqreturn);
    return true;
}

int Library::calculateFine(const char* date){

    int dd, mm, yy;
    struct tm when = {0};
    sscanf(date, "%d/%d/%d", &dd, &mm, &yy);

    when.tm_year = yy-1900;
    when.tm_mon = mm-1;
    when.tm_mday = dd;

    time_t converted;
    converted = mktime(&when);

    time_t t= std::time(0);  
    tm* now = localtime(&t);
    int total=0;
    double diffSecss = difftime(t, converted);
    total = int((diffSecss/86400)-7)*5;
    if(total>=0){
        return total;
    }
    else{
        return 0;
    }
    

}
int Library::finePay(int s_id, int payment){
    student *stu = getStudentById(s_id);
    int fine = stu->getFineDue();
    int remainingFine = fine-payment;
    stu->setFineDue(remainingFine);
    return fine;

}


Library::~Library()
{
    //for library class
    std::fstream fdes;
    fdes.open("library.csv", std::ios::out);
    fdes<<"ID,Title,Author,Publisher,Price,Pages"<<std::endl;
    std::list<Book> ::iterator iter;
    for( iter = books.begin(); iter != books.end(); iter ++ ){
        fdes<< iter->GetId()<<","<<iter->GetTitle()<<","<<iter->GetAuthor()<<","<<iter->GetPublisher()
        <<","<<iter->GetPrice()<<","<<iter->GetPages()<<std::endl;
    }

    //for student class
    std::fstream fdes2;
    fdes2.open("student.csv", std::ios::out);
    fdes2<< "ID,Name,Role,Address,Total_Books_Issues,Fine_Due,Last_Issued_Book_ID,Date,Status"<<std::endl;
    std::list<student> ::iterator iter2;
    for(iter2 = students.begin(); iter2 != students.end(); iter2 ++ ){
        fdes2<< iter2->getId()<<","<< iter2->getName()<<","<< iter2->getRole()<<","<< iter2->getAddress()<<","<< iter2->getTotalBooksIssued()<<","<< iter2->getFineDue()<<","<< iter2->getLastIssuedBookId()<<","<< iter2->getDate()<<","<< iter2->getStatus()<<std::endl;
    }

    //for librarian class
    std::fstream fdes3;
    fdes3.open("librarian.csv", std::ios::out);
    fdes3<< "ID,Name,Role,Address,Username,Password"<<std::endl;
    std::list<librarian> ::iterator iter3;
    for( iter3 = librarians.begin(); iter3 != librarians.end(); iter3 ++ ){
        fdes3<< iter3->getId()<<","<< iter3->getName()<<","<< iter3->getRole()<<","<< iter3->getAddress()<<","<< iter3->getUsername()<<","<< iter3->getPassword()<<std::endl;
    }
    fdes.close();
    fdes2.close();
    fdes3.close();
}
