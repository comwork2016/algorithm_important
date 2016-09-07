main:main.o MD5.o
	g++ -o $@ $^

main.o:main.cpp
	g++ -o $@ -c $^

MD5.o:MD5.cpp
	g++ -o $@ -c $^

.PHONY:clean

clean:
	-rm -f *.o main
