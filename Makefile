EXE := sort_visualizer

CXX := g++
CXXFLAGS := -g -Wall -I include/
LDLIBS := -lSDL2
LDFLAGS := -g
SRC := $(shell find . -name "*.cpp")
HEADERS := $(shell find ./include -name "*.hpp")
OBJS := $(patsubst %.cpp, %.o, $(SRC))

.PHONY: all clean run

all: run

$(EXE): $(OBJS)
	$(CXX)  $(LDFLAGS) -I include/ $(LDLIBS) $(OBJS) -o $(EXE)

depend: .depend

.depend: $(SRC) $(HEADERS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

include .depend

clean:
	rm -f $(OBJS)

dist-clean: clean
	rm -f *~ .depend

run: $(EXE) clean
	./$(EXE)
