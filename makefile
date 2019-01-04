C=g++
EXEC=main

all: $(EXEC)

main: test-piece.o window.o utilisateur.o balle.o brique.o raquette.o tabBriques.o message.o Bscore.o
	$(C) $^ -o $@ -lncurses

test-piece.o: test-piece.cpp
	$(C) -c $<

cellule.o: window.cpp window.h
	$(C) -c $<

utilisateur.o: utilisateur.cpp utilisateur.h
	$(C) -c $<

balle.o: balle.cpp balle.h
	$(C) -c $<

raquette.o: raquette.cpp raquette.h
	$(C) -c $<

brique.o: brique.cpp brique.h
	$(C) -c $<

tabBriques.o: tabBriques.cpp tabBriques.h
	$(C) -c $<

message.o: message.cpp message.h
	$(C) -c $<

Bscore.o: Bscore.cpp Bscore.h
	$(C) -c $<

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
