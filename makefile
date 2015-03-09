CC=g++
CFLAGS=-std=c++0x
LDFLAGS=
LIBPATH=
LIBS=
INCPATH =
PATHEXEC=./
EXEC=Test
TARGET=$(addprefix $(PATHEXEC), $(EXEC))

SRC=test.cpp
OBJ=$(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)

	$(CC) -o $@ $^ $(LDFLAGS) $(LIBPATH) $(LIBS)

%.o: %.cpp %.h

	$(CC) -o $@ -c $< $(CFLAGS) $(INCPATH)

run: $(TARGET)

	./$(TARGET)

clean:	

	@rm -rf *.o
