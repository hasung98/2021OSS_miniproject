CC = gcc
CFLAGS = -W -Wall
TARGET = product_main
DTARGET = product_main_debug
OBJECTS = product_main.c product.o manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o
	rm product_main product_main_debug
