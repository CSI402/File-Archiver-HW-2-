CC =gcc
CFLAGS =-Wall
OBJECTS =  main.c functions1.c functions2.c functions3.c

archiver: $(OBJECTS)
        $(CC) $(CFLAGS) $(OBJECTS) -o archiver

main.o: main.c
        $(CC) $(CFLAGS) -c main.c

%.o: %.c
        $(CC) $(CFLAGS) -c $<

///////erase this comment when you use this code but just an fyi that there needs to be a blank line at the end of your makefile
