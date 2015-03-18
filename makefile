################################################
# Makefile - H4414 #
# Projet Lutin #
################################################

# d�finition des cibles particuli�res
.PHONY: clean, mrproper
# d�sactivation des r�gles implicites
.SUFFIXES:

EXE=Lutin
LIBPATH=-L /usr/lib/boost/lib
LIBS=$(LIBPATH) -lboost_regex
ECHO=@echo
RM=rm
CLEANFLAGS=-f
EDL=g++
LDFLAGS=
CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic
prefix=.
srcdir= $(prefix)/src
SRC= main.cpp $(wildcard $(srcdir)/*.cpp) $(wildcard $(srcdir)/Symboles/*.cpp)
OBJ= $(SRC:.cpp=.o)

all : $(EXE)

Lutin : $(OBJ)
		$(ECHO) Editions des liens :
		$(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

%.o : %.cpp
		$(ECHO) Compilation de $@
		$(CXX) -c $< -o $@ $(CXXFLAGS)

clean :
		$(ECHO) Nettoyage de la cible
		$(RM) $(CLEANFLAGS) *.o core
		$(RM) $(CLEANFLAGS) $(OBJ)

mrproper: clean
	rm -rf $(EXE).exe $(EXE)
