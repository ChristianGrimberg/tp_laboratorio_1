PROJECT = tp2
OBJDIR = obj/Debug/
DEBUGDIR = bin/Debug/
prefix = /usr/bin
UPDIR = ../../
CFLAGS = -c
RMFLAGS = -rf
WFLAGS = -Wall
SRC = main.c
OBJ = main.o
ARRAYEMPLOYEESC = arrayEmployees.c
ARRAYEMPLOYEESH = arrayEmployees.h
ARRAYEMPLOYEESO = arrayEmployees.o
MENUC = menu.c
MENUH = menu.h
MENUO = menu.o
INPC = inputs.c
INPH = inputs.h
INPO = inputs.o
ARRC = arrays.c
ARRH = arrays.h
ARRO = arrays.o
STRC = structs.c
STRH = structs.h
STRO = structs.o

debug: $(PROJECT)
	./$(DEBUGDIR)$^
$(PROJECT): $(OBJDIR)$(STRO) $(OBJDIR)$(ARRO) $(OBJDIR)$(INPO) $(OBJDIR)$(MENUO) $(OBJDIR)$(ARRAYEMPLOYEESO) $(OBJDIR)$(OBJ)
	$(CC) $(WFLAGS) $^ -o $(DEBUGDIR)$@
$(OBJDIR)$(OBJ): $(ARRAYEMPLOYEESH) $(SRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$(SRC)
$(OBJDIR)$(ARRAYEMPLOYEESO): $(ARRAYEMPLOYEESC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(MENUO): $(MENUC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(INPO): $(INPC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(ARRO): $(ARRC)
	cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
$(OBJDIR)$(STRO): $(STRC)
	mkdir -p $(OBJDIR) \
	&& mkdir -p $(DEBUGDIR) \
	&& cd $(OBJDIR) \
	&& $(CC) $(CFLAGS) $(UPDIR)$^
clean:
	$(RM) $(PROJECT).layout $(PROJECT).depend *.gch \
	&& $(RM) $(RMFLAGS) bin/ obj/
