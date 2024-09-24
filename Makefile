CC = gcc
CFLAGS = -Wall -g

# Define the executable name
TARGET = explode

# Define object files
OBJECTS = main.o lab1.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c lab1.h
    $(CC) $(CFLAGS) -c main.c

lab1.o: lab1.c lab1.h
    $(CC) $(CFLAGS) -c lab1.c

clean:
    rm -f *.o $(TARGET)
