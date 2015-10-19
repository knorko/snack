snak: snak.c snak_update.o snak.h
	gcc -o snak snak_update.o snak.h snak.c
snak_update.o: snak_update.c snak.h
	gcc -c snak_update.c snak.h
