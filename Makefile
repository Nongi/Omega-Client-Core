CC=g++
EDL=g++
RM=rm
BUILDDIR=build/
SRCDIR=
CCFLAGS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
RMFLAGS=
EXE=omega.a
LIBS=
EFFACE=clean
OBJ=$(BUILDDIR)animation.o $(BUILDDIR)bddInternalHandler.o $(BUILDDIR)elementMap.o $(BUILDDIR)GestionnaireDB.o $(BUILDDIR)mapHandler.o $(BUILDDIR)mapSyst.o $(BUILDDIR)musicHandler.o $(BUILDDIR)noyau.o $(BUILDDIR)soundHandler.o $(BUILDDIR)spriteHandler.o $(BUILDDIR)sqlite3.o


$(EXE) : $(OBJ) $(BUILDDIR)main.o
	$(EDL) -o $(EXE) $(OBJ) $(LIBS) $(BUILDDIR)main.o $(LDFLAGS)

$(BUILDDIR)%.o : $(SRCDIR)%.cpp $(SRCDIR)%.hpp
	$(CC) -c $< -o $@ $(CCFLAGS)

$(BUILDDIR)%.o : $(SRCDIR)%.cpp $(SRCDIR)%.h
	$(CC) -c $< -o $@ $(CCFLAGS)

$(BUILDDIR)%.o : $(SRCDIR)%.c $(SRCDIR)%.h
	gcc -c $< -o $@ $(CCFLAGS)

$(BUILDDIR)main.o : $(SRCDIR)main.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(EFFACE) :
	$(RM) $(RMFLAGS) $(BUILDDIR)*.o $(EXE) core
