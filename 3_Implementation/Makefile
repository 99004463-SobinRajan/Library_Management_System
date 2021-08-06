all:all.out
all.out:book.cpp library.cpp user.cpp main.cpp
	g++ book.cpp library.cpp user.cpp main.cpp -lpthread -o all.out
run:all.out
	./all.out
test:book.cpp library.cpp user.cpp tests.cpp
	g++ book.cpp library.cpp user.cpp tests.cpp -lrt -lpthread
cppcheck:book.cpp library.cpp user.cpp tests.cpp
	cppcheck g++ book.cpp library.cpp user.cpp tests.cpp
valgrind:book.cpp library.cpp user.cpp tests.cpp
	valgrind g++ book.cpp library.cpp user.cpp tests.cpp -lgtest -lpthread

