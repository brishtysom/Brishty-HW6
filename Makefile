#Makefile

CXX= g++
CXXFLAGS=
CPPFLAGS= -Wall -I/scratch/perkins/include
LDFLAGS= -L/scratch/perkins/lib
LDLIBS= -lcdk -lcurses

EXECFILE= binary
OBJS= example1.o

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~

$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
