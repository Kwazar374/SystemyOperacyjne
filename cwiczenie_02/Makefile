# rozszerzenia w nazwach plikow
.SUFFIXES: .c .o .x .h

# DIR = nazwa katalogu, w ktorym znajduje sie Makefile
DIR = $(notdir $(CURDIR))

# SYSNAME = nazwa systemu operacyjnego (jadra)
SYSNAME = $(shell uname -s)

# Nazwy
# Rdzenie nazw plikow
NAME_CW2 = cw2
NAME_WYP = funkcja_wypisujaca
# Program wykonawczy
EXEC_CW2 = $(NAME_CW2).x
EXEC_WYP = $(NAME_WYP).x
# Object file
OBJS_CW2 = $(NAME_CW2).o
OBJS_WYP = $(NAME_WYP).o

# opcje kompilatora i linkera
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O

# kompiltor i linker
CO = gcc
LD = $(CO)

# Regula wzorcowa, mowiaca jak otrzymac plik
# z rozszerzeniem .o z pliku .c
%.o: %.c
	$(CO) $(CFLAGS) -c $<

# Zabezpieczenie przed omylkowym wywolaniem pliku
# o takiej samej nazwie jak nazwa reguly
.PHONY: all
# Regula
all: $(EXEC_CW2) $(EXEC_WYP)

# Jawna regula zaleznosci: najpierw uaktualnij
# pliki po prawej stronie dwukropka, a potem
# wykonaj komende, ktora jest w nastepnej linijce
# (tutaj linkowanie)
$(EXEC_CW2) : $(OBJS_CW2) $(LIBS_CW2)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_WYP) : $(OBJS_WYP) $(LIBS_WYP)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: run_cw2 run_wyp
# Uruchom program $(EXEC_CW2); najpierw sprawdz, czy kod
# wykonawczy jest aktualny
run_cw2: $(EXEC_CW2) $(EXEC_WYP)
	./$(EXEC_CW2) $(EXEC_WYP)

run_wyp: $(EXEC_WYP)
	./$(EXEC_WYP)

# Sprzatanie
.PHONY: clean tar
clean:
	rm -f *.o *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

# Archiwizacja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz $(DIR))
