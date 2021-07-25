all:all.out
all.out:book.cpp library.cpp tests.cpp
	g++ book.cpp library.cpp tests.cpp -lgtest -lpthread -o all.out
run:all.out
	./all.out
cppcheck:book.cpp library.cpp tests.cpp -o all.out
	cppcheck g++ book.cpp library.cpp tests.cpp
valgrind:book.cpp library.cpp tests.cpp
	valgrind g++ book.cpp library.cpp tests.cpp -lgtest -lpthread -o all.out

