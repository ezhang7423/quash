main: 
	g++ -o driver driver.cpp -g && ./driver "insert 10, insert 3, insert 5, delete 10, lookup 10, insert 10, insert 10, delete 10, lookup 10, print, delete 10"

debug:
	g++ -o driver driver.cpp -g && valgrind ./driver "insert 10"
	