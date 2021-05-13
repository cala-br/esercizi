OBJ = main.o fun-app.o liste.o tipo.o
CXXFLAGS = -Wall

compile: depend weblist
weblist: $(OBJ)
	g++ -o $@ $^

-include deps

.PHONY: depend clean cleanall
depend:
	g++ -MM *.cc > deps
clean:
	rm -f *.o deps
cleanall:
	rm -f web-list *.o deps