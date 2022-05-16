EXE := sort_visualizer

CXX := g++
CXXFLAGS := -g -Wall -Wextra -fPIC -std=c++2a -I include/
LDLIBS := -lSDL2main -lSDL2
LDFLAGS := -g

SRC := $(shell find . -name "*.cpp")
HEADERS := $(shell find ./include -name "*.hpp")
OBJS := $(patsubst %.cpp, %.o, $(SRC))

.PHONY: all clean run

all: run

$(EXE): $(OBJS)
	$(CXX)  $(LDFLAGS) $(LDLIBS) $(OBJS) -o $(EXE)

depend: .depend

.depend: $(SRC) $(HEADERS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

include .depend

clean:
	rm -f $(OBJS)

dist-clean: clean
	rm -f *~ .depend

run: $(EXE)
	./$(EXE)
