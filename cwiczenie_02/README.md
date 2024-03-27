# ĆWICZENIE 2: URUCHAMIANIE PROGRAMOW: EXEC

## Treść Zadania

Zmodyfikować program z ćwiczenia 1b tak, aby komunikaty procesów potomnych były wypisywane przez program uruchamiany przez funkcję **execl**.
Nazwę programu do uruchomienia przekazywać przez argumenty programu procesu macierzystego.
*-> Ile procesów powstanie przy n-krotnym wywołaniu funkcji for-exec jak wyżej i dlaczego?*

## Zawartość

Pliki `.c` - rozwiązanie zadania oraz pomocnica funkcja wypisujaca:

- cw2.c
- wypisz.c

Plik `README.md` - treść zadania, opis plików, instrukcje dotyczące Makefile'a,

Plik `odpowiedzi.txt` - odpowiedź na pytanie postawione w treści zadania.

### Uruchomienie Programów

Uruchomienie programu:

```bash
make run_cw2
```

Czyszczenie katalogu ze zbędnych plików,
tzn.powrót do stanu sprzed uruchomienia któregokolwiek z programów):

```bash
make clean
```

Archiwizacja katalogu:

```bash
make tar
```

