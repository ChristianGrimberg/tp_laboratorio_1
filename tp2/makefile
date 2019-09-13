OBJDIR = obj/Debug/
EXEDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
WFLAGS = -Wall
SRC = main.c
OBJ = main.o
MENUC = menu.c
MENUH = menu.h
MENUO = menu.o
EMPLOYEEC = employee.c
EMPLOYEEH = employee.h
EMPLOYEEO = employee.o
INPC = input.c
INPH = input.h
INPO = input.o
PROJECT = tp2

$(PROJECT): $(OBJDIR)$(INPO) $(OBJDIR)$(EMPLOYEEO) $(OBJDIR)$(MENUO) $(OBJDIR)$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(EXEDIR)$@
$(OBJDIR)$(OBJ): $(MENUH) $(SRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC)
$(OBJDIR)$(MENUO): $(MENUC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(EMPLOYEEO): $(EMPLOYEEC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(INPO): $(INPC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
clean:
	$(RM) $(PROJECT).layout $(OBJDIR)*.o $(EXEDIR)$(PROJECT)
debug: $(PROJECT)
	./$(EXEDIR)$^
