main: 
	g++ -o driver driver.cpp -g && ./driver "insert 10, insert 10, insert 1, insert 12, insert 3, print"

debug:
	g++ -o driver driver.cpp -g && valgrind ./driver "insert 10"
	