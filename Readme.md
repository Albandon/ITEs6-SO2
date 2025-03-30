# Problem jedzących filozofów
Problem, polegający na synchronizacji dostępu wątków do współdzielonych zasobów.

Ideą tego problemu jest sytuacja, w której **pięciu filozofów** siedzi przy jednym stole z jedzeniem. Na stole znajduję się również **pięć widelców/pałeczek**. Filozofowie mogą `myśleć` (Stan podstawowy), `zgłodnieć` lub `jeść`. Problem w tej sytuacji wynika z faktu, że aby jeść potrzebne, są filozofom dwa widelce/pałeczki.

## Od strony informatycznej
Problem prezentuje nam sytuacje, gdzie posiadamy jakiś **wspólny zasób** (widelce) oraz **wątki**, które mają do niego dostęp. Naszym zadaniem jest umożliwić ciągły dostęp do widelców, bez sytuacji gdzie dwaj filozofowie używają tego samego widelca lub żaden filozof nie może wybrać drugiego widelca, ponieważ każdy podniósł jeden.

## Rozwiązanie
Tego typu problemy, rozwiązuje się przy pomocy mechanizmów synchronizacji, takich jak **muteksy** czy **semafory**. 

W tym przypadku wybrane zostały semafory binarne `std::binary_semaphore`, które mogą odgrywać rolę obu. Semafory binarne pozwolą nam blokować odpowiednie widelce, zabezpieczając do nich tym samym dostęp. Ważnym dodatkiem jest tutaj dodanie mechanizmu zapobiegającego ściganiu, się wątków. Dziele się to tutaj poprzez zmodyfikowanie hierarchi zasobów dla ostatniego z filozofów. Wątek ten pobierze zamiast lewego widelca jako pierwszy, prawy. Zaskutkuje to brakiem sytuacji, w której wszyscy filozofowie wybrali widelec lewy i nie ma możliwości dobrania prawego. 

## Dokumentacja:
### Klasa: `DiningTable`

**Opis:**
Klasa reprezentuje stół do jedzenia, na którym znajduje się określona liczba widelców. Oferuje operacje związane z "wzięciem" i "odłożeniem" widelców.
#### Metody:
`DiningTable(int count)` - Konstruktor przyjmuje liczbę widelców, a następnie tworzy dla nich semafory binarne (po jednym dla każdego widelca).

`TakeForks(int leftIndex, int rightIndex)` - Wstrzymuje (aktywuje) dwa semafory odpowiadające widelcom o podanych indeksach (wskaźniki na lewy i prawy widelec).

`PutForks(int leftIndex, int rightIndex)` - Zwolnia (odblokowuje) semafory odpowiadające widelcom o podanych indeksach.

### Klasa: `Philosoph`

**Opis:** 
Klasa reprezentuje filozofa, który symuluje proces myślenia, głodowania oraz jedzenia przy stole. Filozof w danym momencie może być w jednym z trzech stanów: `Thinking`, `Hungry` `Eating`.

#### Metody:
`Philosoph(int id, DiningTable &table)` - Konstruktor, który inicjalizuje filozofa
`changeState(PhiloState changeTo)` - Zmienia stan filozofa i wywołuje funkcję wyświetlania stanu.
`printState()` - Wyświetla aktualny stan filozofa.
`Exist()` - Symuluje życie filozofa, który zmienia kolejno stany. Filozof przez określony czas "je" (3 sekundy), a potem zwraca widelce.

