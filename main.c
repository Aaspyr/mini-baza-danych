#include <stdio.h>
#include <stdlib.h>
/*Zad 3
Utworzyc strukture i nazwac ja "osoba". Umiescic w niej pola: imie, nazwisko,
rok_urodzenia, plec. Utworzyc zmienna "osoby", bedacy tablica typu osoba (N elementowa).
Napisac dwie funkcje: (Odczytaj, Wyswietl) do wprowadzania i wyswietlania
danych do tablicy struktur.
Nastepnie napisac dwie funkcje (Sortuj_wg_Wieku, Sortuj_wg_Imienia)
do sortowania danych wedlug: imienia oraz wieku. W dalszej kolejnosci napisac funkcje
(Szukaj_Imie_Wiek) wyszukujaca osobe o zadanym imieniu w zadanym przedziale
wiekowym np.: wszystkie Agnieszki w wieku do 5 do 30 lat*/
#define N 3
typedef struct osoba tosoba;

struct osoba
{
    char imie [20];
    char nazwisko [20];
    int rok;
    char plec;
};

void Odczytaj(tosoba tab[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("Napisz imie: \n");
    scanf("%s", tab[i].imie);
    printf("Napisz nazwisko: \n");
    scanf("%s", tab[i].nazwisko);
    printf("Napisz rok urodzenia: \n");
    scanf("%d", &tab[i].rok);
    fflush(stdin);
    printf("Napisz plec - K lub M: \n");
    scanf("%c", &tab[i].plec);
    }
}
void Wczytaj(tosoba tab[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nDane osoby: \n");
        printf("Imie: %s\n", tab[i].imie);
        printf("Nazwisko: %s\n", tab[i].nazwisko);
        printf("Rok urodzenia: %d\n", tab[i].rok);
        printf("Plec: %c", tab[i].plec);
    }
}
void sortuj_wiek(tosoba tab[], int n)
{
    int i, d=n;
    tosoba b=tab[0];
    for(d; d>0; d--)
    {
    for(i=0; i<d-1; i++)
    {
        if(tab[i].rok<tab[i+1].rok)
        {
            b=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=b;
        }
    }
    }
}
void sortuj_imie(tosoba tab[], int n)
{
    int i, d=n;
    tosoba b=tab[0];
    for(d; d>0; d--)
    {
        for(i=0; i<d-1; i++)
      {
        if(strcmp(tab[i].imie,tab[i+1].imie)>0)
        {
            b=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=b;
        }
      }
    }
}
void szukaj_imie_wiek(tosoba tab[], int n)
{
    int i, wiekmin, wiekmax;
    char imie[20];
    printf("Podaj szukane imie: \n");
    gets(imie);
    printf("Podaj szukany min wiek: \n");
    scanf("%d", &wiekmin);
    printf("Podaj szukany max wiek: \n");
    scanf("%d", &wiekmax);

    wiekmin= 2019-wiekmin;
    wiekmax=2019- wiekmax;

    for (i=0; i<n; i++)
    {
        if(strcmp(tab[i].imie, imie)==0
           && tab[i].rok>wiekmax
           && tab[i].rok<wiekmin
        ) {
            printf("\nDane osoby: \n");
            printf("Imie: %s\n", tab[i].imie);
            printf("Nazwisko: %s\n", tab[i].nazwisko);
            printf("Rok urodzenia: %d\n", tab[i].rok);
            printf("Plec: %c", tab[i].plec);
        }
    }
}

int main(void)
{
    tosoba tab[N];
    /*={
        {
        "Aa",
        "Nazwisko",
        1990,
        'K'
    },
    {
        "C",
        "Nazwisko",
        1999,
        'K'
    },
    {
        "Ab",
        "Nazwisko",
        2001,
        'K'
    },
    };*/

    Odczytaj(tab, N);
    Wczytaj (tab, N);
    sortuj_wiek(tab, N);
    Wczytaj(tab,N);
    printf("\n\n");
    sortuj_imie(tab, N);
    Wczytaj(tab,N);
    printf("\n\n");
    szukaj_imie_wiek(tab, N);
    printf("\n\n");

    return(0);
}
