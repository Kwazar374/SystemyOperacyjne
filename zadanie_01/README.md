# ĆWICZENIE 1: PROCESY POTOMNE: FORK

## Treść Zadania

### A

Napisać program wypisujący identyfikatory UID, GID, PID, PPID i PGID dla danego procesu.

### B

Wywołać funkcję fork trzy razy (najlepiej w pętli for) i wypisać powyższe identyfikatory dla procesu macierzystego oraz wszystkich procesów potomnych.
Przy pomocy funkcji wait sprawić, aby proces macierzysty zaczekał na zakończenie wszystkich procesów potomnych.

### C

Jak w (b), tylko przy użyciu funkcji sleep (nie używać funkcji wait) sprawiać by procesy potomne były adoptowane przez proces init lub systemd;
poleceniem pstree -p z poziomu powłoki wyswietlić drzewo procesów w danym systemie i zidentyfikować proces adoptujący osierocone procesy.

### D

Jak w (b), tylko wstawić funkcję sleep w takich miejscach programu, aby procesy pojawiały się na ekranie grupowane pokoleniami od najstarszego do najmłodszego, a proces macierzysty kończył się dopiero po procesach potomnych (nie używać funkcji wait).

Na podstawie wyników programu sporządzić (w pliku tekstowym) "drzewo genealogiczne" tworzonych procesów z zaznaczonymi identyfikatorami PID, PPID i PGID.

### E

Jak w (b), tylko przy użyciu fukcji `setpgid` sprawić by każdy proces potomny stawał się liderem swojej własnej grupy procesów.

Ile procesów powstanie przy n-krotnym wywołaniu funkcji fork i dlaczego?

W celu narysowania drzewa genealogicznego procesów, najpierw skopiować do pliku tekstowego wydruk na ekranie z przykładowego uruchomienia programu, a następnie w kolejnych liniach wypisać wartości(PID,PPID,PGID) procesów z kolejnych pokoleń i połączyć je kreskami, np.

```text
                  (PID1,PPID1,PGID1)

             |                         |

    (PID2a,PPID2a,PGID2a)      (PID2b,PPID2b,PGID2b)
```

## Zawartość

Pliki `.c` - rozwiązania:

- a.c
- b.c
- c.c
- d.c
- e.c

Plik `README.md` - treść zadania, opis plików, instrukcje dotyczące Makefile'a,

Plik `odpowiedzi.txt` - odpowiedzi do podpunktow C, D, E.

### Uruchomienie Programów

Uruchomienie poszczególnych programów:

```bash
make run_a
make run_b
make run_c
make run_d
make run_e
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
