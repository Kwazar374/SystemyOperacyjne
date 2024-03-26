# Rozszerzenia w nazwach plikow
.SUFFIXES: .c .o .x .h

# DIR = nazwa katalogu, w ktorym znajduje sie makefile
DIR = $(notdir $(CURDIR))

# SYSNAME = nazwa systemu operacyjnego (jadra)
SYSNAME = $(shell uname -s)

# Nazwy, tu: rdzenie nazw plikow
NAME_A = a
NAME_B = b
NAME_C = c
NAME_D = d
NAME_E = e
# Program wykonawczy
EXEC_A = $(NAME_A).x
EXEC_B = $(NAME_B).x
EXEC_C = $(NAME_C).x
EXEC_D = $(NAME_D).x
EXEC_E = $(NAME_E).x
# Object file
OBJS_A = $(NAME_A).o
OBJS_B = $(NAME_B).o
OBJS_C = $(NAME_C).o
OBJS_D = $(NAME_D).o
OBJS_E = $(NAME_E).o

# Opcje kompilatora i linkera
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O

# Kompilator i linker
CO = gcc
LD = $(CO)

# Regula wzorcowa, mowiaca jak otrzymac plik
# z rozszerzeniem .o z plikow .c
%.o: %.c
	$(CO) $(CFLAGS) -c $<

# Zabezpieczenie przed omylkowym wywowalniem pliku
# o takiej samej nazwie jak nazwa reguly
.PHONY: all
# regula:
all: $(EXEC_A) $(EXEC_B) $(EXEC_C) $(EXEC_D) $(EXEC_E)

# Jawna regula zaleznosci: najpierw uaktualnij
# pliki po prawej stronie dwukropka, a potem
# wykonaj komende, ktora jest w nastepnej linijce
# (tutaj linkowanie)
$(EXEC_A) : $(OBJS_A) $(LIBS_A)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_B) : $(OBJS_B) $(LIBS_B)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_C) : $(OBJS_C) $(LIBS_C)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_D) : $(OBJS_D) $(LIBS_D)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC_E) : $(OBJS_E) $(LIBS_E)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: run_a run_b run_c run_d run_e
# Uruchom program $(EXEC_TEST); najpierw sprawdz, czy kod
# wykonawczy jest aktualny
run_test: $(EXEC_TEST)
	./$(EXEC_TEST)

run_a: $(EXEC_A)
	./$(EXEC_A)
	
run_b: $(EXEC_B)
	./$(EXEC_B)

run_c: $(EXEC_C)
	./$(EXEC_C)

run_d: $(EXEC_D)
	./$(EXEC_D)

run_e: $(EXEC_E)
	./$(EXEC_E)

# Sprzatanie
.PHONY: clean tar
clean:
	rm -f *.o *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

# Archiwizacja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz $(DIR) )







