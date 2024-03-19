# rozszerzenia w nazwach plikow
.SUFFIXES: .c .o .x .h

# DIR = nazwa katalogu, w ktorym znajduje sie makefile
DIR = $(notdir $(CURDIR))

# SYSNAME = nazwa systemu operacyjnego (jadra)
SYSNAME = $(shell uname -s)

# Nazwy, tu: rdzenie nazw plikow
NAME_TEST = test
# Program wykonawczy
EXEC_TEST = $(NAME_TEST).x
# Object file
OBJS_TEST = $(NAME_TEST).o

# opcje kompilatora i linkera
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O

# kompilator i linker
CO = gcc
LD = $(CO)

# regula wzorcowa, mowiaca jak otrzymac plik
# z rozszerzeniem .o z plikow .c oraz .h
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<

# zabezpieczenie przed omylkowym wywowalniem pliku
# o takiej samej nazwie jak nazwa reguly
.PHONY: all
# regula:
all: $(EXEC_TEST)

# jawna regula zaleznosci: najpierw uaktualnij
# pliki po prawej stronie dwukropka, a potem
# wykonaj komene, ktora jest w nastepnej linijce
# (tutaj linkowanie)
$(EXEC_TEST) : $(OBJS_TEST) $(LIBS_TEST)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: run_test
# uruchom program $(EXEC_TEST); najpierw sprawdz, czy kod
# wykonawczy jest aktualny
run_test: $(EXEC_TEST)
	./$(EXEC_TEST)

# sprzatanie
.PHONY: clean tar
clean:
	rm -f *.o *~ *.a *.so *x core core* a.out; rm -rf ${LIB_DIR}

# archiwizacja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz $(DIR) )







