### find and replace temp with your name of library
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d) 

INSTALL_DIR = /usr/local/bin

OUTPUTFILE = final.o



CXXFLAGS= -O0  -g -Wall -fno-inline -std=c++14  # Flags option used for compiling C++ files
LDFLAGS = 
# Compiler Options
CC       = g++ # compiler used for compiling C files 
CXX      = g++ # compiler used for compiling C++ files

$(OUTPUTFILE): $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^  $(LDFLAGS)

# Generate dependencies of .cpp files 
-include $(dep)
%.d: %.cpp
	$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@
	

#######################
### VALGRIND SECTION
#######################
DEBUGFILE = debug
DEBUGFLAGS =  --tool=memcheck --leak-check=yes --log-file=$(DEBUGFILE)

.PHONY: valg_all
valg_all:	valg valg_show_print

.PHONY: valg
valg:
	valgrind $(DEBUGFLAGS) ./$(OUTPUTFILE)

.PHONY: valg_show_print
valg_show_print:
	cat $(DEBUGFILE)

#######################
## CLEANING THINGS UP
#######################
.PHONY: cleanall 
cleanall: clean cleandep

.PHONY: clean
clean:
	rm -f $(obj) $(OUTPUTFILE)
.PHONY: cleandep
cleandep:
	rm -f $(dep)
	

#######################
## Debugging
#######################
.PHONY: gdb
gdb: 
	gdb ./$(OUTPUTFILE)


#######################
## RUNNING OUTPUT FILE
#######################
.PHONY: run
run:
	./$(OUTPUTFILE)


#######################
## INSTALL OUTPUT FILE
#######################
.PHONY: install
install:
	sudo cp $(OUTPUTFILE) $(INSTALL_DIR) 
	
