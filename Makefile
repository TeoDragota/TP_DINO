TARGET = dino
SRCS = main.c dinozaur.c obstacole.c

INCLUDES = -Iraylib/src
LIBDIRS  = -Lraylib/build/raylib
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

CC = gcc

all:
	$(CC) $(SRCS) -o $(TARGET) $(INCLUDES) $(LIBDIRS) $(LIBS)

clean:
	rm -f $(TARGET)
