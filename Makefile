domletters: thecode.o
	g++ thecode.o -o domletters

thecode.o: thecode.cpp
	g++ -c thecode.cpp

clean:
	rm *.o domletters
