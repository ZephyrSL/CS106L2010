SOURCES = $(wildcard *.c *.cpp)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))

test : $(OBJS)
	g++ -o test $(OBJS)

depends : $(SOURCES)
	g++ -M $(SOURCES) > depends

.PHONY : clean
clean : 
	rm -f $(OBJS) test
