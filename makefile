CC=g++
CFLAGS=-std=c++0x
LDFLAGS=
LIBPATH=-L /usr/lib/boost/lib -lboost_regex
LIBS=
INCPATH =
PATHEXEC=./
EXEC=test
TARGET=$(addprefix $(PATHEXEC), $(EXEC))

SRC=test.cpp
OBJ=$(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)

	$(CC) -o $@ $^ $(LDFLAGS) $(LIBPATH) $(LIBS)

%.o: %.cpp %.h

	$(CC) -o $@ -c $< $(CFLAGS) $(INCPATH)

#run: $(TARGET)

#	./$(TARGET)

clean:	

	@rm -rf *.o
