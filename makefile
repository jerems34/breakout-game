C=g++
EXEC=jeu1

all: $(EXEC)

jeu1: test-piece.o raquette.o brique.o balle.o window.o
	$(C) $^ -o $@ -lncurses
test-piece.o: test-piece.cpp
	$(C) -c $<
window.o: window.cpp window.h
	$(C) -c $<
balle.o: balle.cpp balle.h
	$(C) -c $<
raquette.o: raquette.cpp raquette.h
	$(C) -c $<
brique.o: brique.cpp brique.h
	$(C) -c $<
clean:
	rm -f *.o
mrproper: clean
	rm -f $(EXEC)
