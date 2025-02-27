# Compiler
CC = gcc

# Executable name
TARGET = slist

# Source files
SRCS = main.c proj1.c
OBJS = $(SRCS:.c=.o)

# Default rule: Compile the program
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Compile C files into object files
%.o: %.c proj1.h
	$(CC) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
