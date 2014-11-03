CFLAGS = -O4 -Wall -pedantic -std=c99
TARGET = GameofLife
SOURCES = FileIO.c arrayFunctions.c printErr.c $(TARGET).c
CC = gcc


all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	$(TARGET)
