EXE := sort_visualizer

CXX := g++
CXXFLAGS := -g -Wall
LDLIBS := -lSDL2
LDFLAGS := -g
SRC := $(shell find . -name "*.cpp")
OBJS := $(patsubst %.cpp, %.o, $(SRC))

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX)  $(LDFLAGS) -I include/ $(LDLIBS) $(OBJS) -o $(EXE)

depend: .depend

.depend: $(SRC)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(OBJS) $(EXE)

dist-clean: clean
	rm -f *~ .depend

include .depend