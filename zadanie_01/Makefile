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

# zabezpieczenie przed omylkowym wywowalniem pliku
# o takiej samej nazwie jak nazwa reguly
.PHONY: all
# regula:
all: $(EXEC_TEST)

# jawna regula zaleznosci: najpierw uaktualnij
$(EXEC_TEST) : $(OBJS_TEST)
