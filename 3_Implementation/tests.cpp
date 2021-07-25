#include <gtest/gtest.h>
#include"book.h"
#include"library.h"

TEST(addBook, BookAdded) { 
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    Book *ptr= l1.findBookByID(1);

    ASSERT_EQ(1, ptr->GetId());
    ASSERT_EQ("George RR Mrtin", ptr->GetAuthor());
    ASSERT_EQ("Harper Voyager", ptr->GetPublisher());
    ASSERT_EQ(599, ptr->GetPrice());
    ASSERT_EQ(801, ptr->GetPages());
}
 
TEST(removeBook, BookDeleted) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.removeBookByID(1);
    ASSERT_EQ(NULL, l1.findBookByID(1));
}

TEST(findBook, BookFound) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    Book *ptr=l1.findBookByID(1);
    ASSERT_EQ(1, ptr->GetId());
}

TEST(findAllBookByAuthor, BookFound) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    std::list<Book> temp=l1.fiandAllBookByAuthor("George RR Mrtin");
    ASSERT_EQ(1, temp.size());
}

TEST(findAllBookByAuthor, BookNotFound) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    std::list<Book> temp=l1.fiandAllBookByAuthor("Chetan Bhagat");
    ASSERT_EQ(0, temp.size());
}
//error
TEST(averageBookPrice, AvgBookPrice) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    double avg=l1.findAveragePrice();
    ASSERT_EQ(624.5, avg);
}

//error
TEST(maxBookPages, BookWithMaxPages) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    Book ptr=l1.findBookWithMaxPages();
    ASSERT_EQ(901, ptr.GetPages());
}

TEST(minBookPages, BookWithMinPrice) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    Book ptr=l1.findBookWithMinPrice();
    ASSERT_EQ(599, ptr.GetPrice());
}

//error
TEST(averageBookPriceByPublisher, AvgBookPriceByPublisher) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    double avg=l1.findAveragePriceByPublisher("Harper Voyager");
    ASSERT_EQ(624.5, avg);
}

TEST(minBookPriceByPublisher, MinBookPriceByPublisher) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    Book ptr=l1.findMinOfPublisher("Harper Voyager");
    ASSERT_EQ(599, ptr.GetPrice());
}

TEST(countBookAtRange, OneBookFound) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    int count=l1.countBookAtRange(0, 600);
    ASSERT_EQ(1, count);
}

TEST(countBookLessThan, TwoBookFound) {
    Library l1;
    l1.addBook(1, "Game of thrones", "George RR Mrtin", "Harper Voyager", 599, 801);
    l1.addBook(1, "A Clash of Kings", "George RR Mrtin", "Harper Voyager", 650, 901);
    int count=l1.countBookLessThan(700);
    ASSERT_EQ(2, count);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}