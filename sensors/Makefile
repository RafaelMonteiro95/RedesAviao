#Makefile criado por Lucas Alexandre Soares, adaptado por Rafael Augusto Monteiro

# Project name
NAME=Sensor

# Directories
INCDIR=include
# LIBDIR=lib
BLDDIR=build
SRCDIR=src
OBJDIR=$(SRCDIR)/obj

DEBUGGER=
DBGFLAGS=-v --leak-check=full --show-leak-kinds=all --read-var-info=yes --track-origins=yes

# Search for source files 
SRC += $(wildcard $(SRCDIR)/*.cpp)

# Search for header files
DEPS += $(wildcard $(INCDIR)/*.hpp)

# Generate .o object files rules
# Find filter out .c from .cpp for correct capture
_OBJCPP=$(foreach file, $(SRC), $(file:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o))
OBJCPP=$(filter-out %.c, $(_OBJCPP))
# Combine both C and C++ objects
OBJ= $(OBJCPP)

CC=g++
CFLAGS=-I./$(INCDIR) -std=c++11 -Wall

USER_LIBS=
DEFAULT_LIBS=
LIBS=$(USER_LIBS) $(DEFAULT_LIBS)


ifdef debug
	CFLAGS += -Wall -Wextra -g -D DEBUG
	DEBUGGER=valgrind $(DBGFLAGS) 
endif

all: checkdirs clean main

# Compile directives
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@echo Building $*
	@$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	@echo Building $*
	@$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	@echo Linking object files
	@$(CC) -o $(BLDDIR)/$(NAME) $^ $(CFLAGS) $(LIBS)


# Run directives
run:
	$(DEBUGGER) ./$(BLDDIR)/$(NAME) 

# Utility directives
clean:
	-rm -f $(BLDDIR)/*
	-rm -f $(NAME).zip
	-rm -f $(NAME).tar.gz
	clear
	clear

cleanobj:
	-rm -f $(OBJDIR)/*.o

list:
	clear
	ls -lhR

tar: clean cleanobj
	@echo Compressing files...
	@tar -zcvf $(NAME).tar.gz *
	@echo Done.

zip: clean cleanobj
	@echo Compressing files...
	@zip -r $(NAME).zip *
	@echo Done.

# Check for directory existence and create them if necessary
checkdirs:
	if [ ! -d $(BLDDIR)/ ]; then mkdir -p $(BLDDIR)/; fi
	if [ ! -d $(INCDIR)/ ]; then mkdir -p $(INCDIR)/; fi
	if [ ! -d $(LIBDIR)/ ]; then mkdir -p $(LIBDIR)/; fi
	if [ ! -d $(SRCDIR)/ ]; then mkdir -p $(SRCDIR)/; fi
	if [ ! -d $(OBJDIR)/ ]; then mkdir -p $(OBJDIR)/; fi
