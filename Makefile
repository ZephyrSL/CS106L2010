EXECUTABLE := test
SOURCE := $(wildcard *.c) $(wildcard *.cpp)
HDRS = $(wildcard *.h)
OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
DEPS := $(patsubst %.o,%.d,$(OBJS))
MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))
MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.c,$(MISSING_DEPS)) \
                                   $(patsubst %.d,%.cpp,$(MISSING_DEPS)))
CC := g++
CFLAGS := -g -Wall -O3
CXXFLAGS := $(CFLAGS)
CPPFLAGS += -MD
RM-F := rm -f

.PHONY : everything deps objs clean veryclean rebuild

everything : $(EXECUTABLE)

deps : $(DEPS)

objs : $(OBJS)

clean :
	@$(RM-F) *.o
	@$(RM-F) *.d

veryclean: clean
	@$(RM-F) $(EXECUTABLE)

rebuild: veryclean everything

ifneq ($(MISSING_DEPS),)
$(MISSING_DEPS) :
	@$(RM-F) $(patsubst %.d,%.o,$@)
endif

-include $(DEPS)

$(EXECUTABLE) : $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) 
# $(addprefix -l,$(LIBS))

