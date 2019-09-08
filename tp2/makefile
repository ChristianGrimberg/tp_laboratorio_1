OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
UPDIR = ../../
CFLAGS = -c
WFLAGS = -Wall

Employee: $(OBJDIR)main.o
	$(CC) $(WFLAGS) $(OBJDIR)main.o -o $(EXEDIR)tp2
$(OBJDIR)main.o: main.c
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)main.c