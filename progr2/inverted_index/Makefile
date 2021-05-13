OBJ = src/*.cpp
CXXFLAGS = -Wall -Iinclude

compile: depend inverted-index clean
inverted-index: $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS)

-include deps

.PHONY: depend clean cleanall
depend:
	g++ -MM -Iinclude src/*.cpp > deps
clean:
	rm -f *.o src/*.o
cleanall: clean
	rm -f inverted-index deps