#include <gtest/gtest.h>
#include"book.h"
#include"library.h"

TEST(addBook, BookAdded) { 
    Library l1;
    l1.addBook(6, "Witcher:Blood of Elves", "Andrzej Sapkowski", "SuperNowa", 299, 223);
    Book *ptr= l1.findBookByID(6);

    ASSERT_EQ(6, ptr->GetId());
    ASSERT_EQ("Andrzej Sapkowski", ptr->GetAuthor());
    ASSERT_EQ("SuperNowa", ptr->GetPublisher());
    ASSERT_EQ(299, ptr->GetPrice());
    ASSERT_EQ(223, ptr->GetPages());
    l1.removeBookByID(6);
}
 
TEST(removeBook, BookDeleted) {
    Library l1;
    l1.removeBookByID(1);
    ASSERT_EQ(NULL, l1.findBookByID(1));
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
}

TEST(findBook, BookFound) {
    Library l1;
    Book *ptr=l1.findBookByID(1);
    ASSERT_EQ(1, ptr->GetId());
}

TEST(findAllBookByAuthor, BookFound) {
    Library l1;
    std::list<Book> temp=l1.fiandAllBookByAuthor("George RR Mrtin");
    ASSERT_EQ(2, temp.size());
}

TEST(findAllBookByAuthor, BookNotFound) {
    Library l1;
    std::list<Book> temp=l1.fiandAllBookByAuthor("Chetan Bhagat");
    ASSERT_EQ(1, temp.size());
}

TEST(averageBookPrice, AvgBookPrice) {
    Library l1;
    double avg=l1.findAveragePrice();
    ASSERT_EQ(1089.6, avg);
}

TEST(maxBookPages, BookWithMaxPages) {
    Library l1;
    Book ptr=l1.findBookWithMaxPages();
    ASSERT_EQ(948, ptr.GetPages());
}

TEST(minBookPages, BookWithMinPrice) {
    Library l1;
    Book ptr=l1.findBookWithMinPrice();
    ASSERT_EQ(599, ptr.GetPrice());
}

//error
TEST(averageBookPriceByPublisher, AvgBookPriceByPublisher) {
    Library l1;
    std::cout<<l1.books.size()<<std::endl;
    double avg=l1.findAveragePriceByPublisher("Wiley");
    ASSERT_EQ(1999, avg);
}

TEST(minBookPriceByPublisher, MinBookPriceByPublisher) {
    Library l1;
    Book ptr=l1.findMinOfPublisher("Harper Voyager");
    ASSERT_EQ(599, ptr.GetPrice());
}

TEST(countBookAtRange, OneBookFound) {
    Library l1;
    int count=l1.countBookAtRange(0, 600);
    ASSERT_EQ(1, count);
}

TEST(countBookLessThan, TwoBookFound) {
    Library l1;
    int count=l1.countBookLessThan(700);
    ASSERT_EQ(3, count);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}