SOURCEDIR=src
INSTALLDIR=obj
INCLUDESDIR=.

CPP_FILES=$(wildcard $(SOURCEDIR)/*.cpp)
OBJ_FILES=$(addprefix $(INSTALLDIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

CC_FLAGS=-std=c++14 -I $(INCLUDESDIR)/ -g
CC_FLAGS+=-Wall

main: $(OBJ_FILES)
	clang++ $(CC_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	clang++ $(CC_FLAGS) -c -o $@ $<

clean:
	rm $(wildcard $(INSTALLDIR)/*.o)
