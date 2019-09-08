OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
UPDIR = ../../
CC = cc
CFLAGS = -c
WFLAGS = -Wall

#if defined (__unix__) || defined (__APPLE__) || defined (__MACH__)
Employee: $(OBJDIR)main.o
	$(CC) $(WFLAGS) $(OBJDIR)main.o -o $(EXEDIR)tp2 \
	&& rm $(OBJDIR)main.o
$(OBJDIR)main.o: main.c
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)main.c
#endif