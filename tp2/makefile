OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
UPDIR = ../../
CC = cc
CFLAGS = -c
WFLAGS = -Wall
Employee: $(OBJDIR)main.o
	$(CC) $(WFLAGS) $(OBJDIR)main.o -o $(EXEDIR)tp2 && rm $(OBJDIR)main.o
$(OBJDIR)main.o: main.c
	cd $(OBJDIR) && $(CC) $(CFLAGS) $(UPDIR)main.c