main: 
	g++ -o driver driver.cpp -g && ./driver "insert 10, insert -50, insert 76, lookup 12, insert 12, lookup 12, insert 12, lookup 12, print, deleteMin, \
delete -50, print, delete 10, print, deleteMin, print, delete 12, deleteMin, print, deleteMin"

debug:
	g++ -o driver driver.cpp -g && valgrind ./driver "insert 10"
	