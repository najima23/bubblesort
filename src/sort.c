/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           sort.c
*** description:    file for sort
*** global FKT:     quickSort
***                  cmpName
***                  cmpBirthday
***                  cmpTrikot
***                  cmpGoals
*** LOKALE FKT:      swap
***                  partition
***                  qsort
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "sort.h"

void swap(TPlayer *, TPlayer *);
// char toUpper(char);


/**********************************************************
 * function:      partition
 * description:  Unterteilt das angegebene Array in zwei
 *                Teile, wobei im linken Teil alle Werte
 *                kleiner und im rechten Teil alle Werte
 *                groesser als die mittlere Schranke sind.
 *                Der Index der Schranke wird zurueckgegeben.
 * Parameter:     Array - das zu sortierende Array
 *                ui    - der untere Index des Teils des
 *                         Arrays, der sortiert werden soll
 *                oi    - der obere Index (entsprechend ui)
 * Rueckgabe:     int   - Index der Schranke
 **********************************************************/
int partition(TPlayer *Array, int ui, int oi, int (*cmp)(TPlayer *, TPlayer *))
{
    int i = ui + 1, j = oi;       // Laufindizes
    TPlayer *comp = (Array + ui); // Vergleichselement (Schranke)

    while (i <= j)
    {
        // naechstes Element > comp von links suchen (im linken Teil)
        while ((i <= j) && (cmp((Array + i), comp) <= 0))
            i++;
        // naechstes Element < comp von rechts suchen (im rechten Teil)
        while ((j >= i) && (cmp((Array + j), comp) >= 0))
            j--;
        if (i < j)
        {
            swap(Array + i, Array + j);
            i++;
            j--;
        }
    }
    i--;
    swap(comp, Array + i);
    return i;
}

/**********************************************************
 * function:      qsort
 * description:  Unterteilt das Array in zwei Teile
 *                (function partition) und ruft sich selber
 *                fuer beide Teile erneut auf.
 * Parameter:     Array - das zu sortierende Array
 *                ui    - der untere Index des Teils des
 *                         Arrays, der sortiert werden soll
 *                oi    - der obere Index (entsprechend ui)
 * Rueckgabe:     -/-
 **********************************************************/
void qsort(TPlayer *Array, int ui, int oi, int (*cmp)(TPlayer *, TPlayer *))
{
    int idx;      // Schranke einer Zerlegung

    if (ui >= oi) // Abbruchbedingung der Rekursion
        return;
    else
    {
        idx = partition(Array, ui, oi, cmp);
        qsort(Array, ui, idx - 1, cmp); // linken Teil rekursiv sortieren
        qsort(Array, idx + 1, oi, cmp); // rechten Teil rekursiv sortieren
    }
}

/***********************************************************
 * function:      QuickSort
 * description:  Sortiert das angegebene Zahlen-Array in
 *                aufsteigender Reihenfolge.
 * Parameter:     Array  – Zeiger auf das zu sortierende Array
 *                Anzahl – Anzahl der Elemente im Array
 * Rueckgabe:     -/-
 ***********************************************************/
void QuickSort(TPlayer *Array, int Anzahl, int (*cmp)(TPlayer *, TPlayer *))
{
    printf("Anzahl: %i\n", Anzahl);
    qsort(Array, 0, Anzahl - 1, cmp);
}

/********************************************************************
 * function:      swap
 * description:  vergleich
 * Paramater:     - Datensatz 1
 *                - Datensatz 2
 * return:      -/-
 *******************************************************************/
void swap(TPlayer *D1, TPlayer *D2)
{
    TPlayer tmp;
    tmp = *D1;
    *D1 = *D2;
    *D2 = tmp;
}

/********************************************************************
 * function:      cmpName
 * description:  vergleich
 * Paramater:     - Datensatz 1
 *                - Datensatz 2
 * return:      Differenz
 *******************************************************************/
int cmpName(TPlayer *D1, TPlayer *D2)
{
    return strcmp(D1->Name, D2->Name);
}

/********************************************************************
 * function:      cmpBirthday
 * description:  vergleich
 * Paramater:     - Datensatz 1
 *                - Datensatz 2
 * return:      Differenz
 *******************************************************************/
int cmpBirthday(TPlayer *D1, TPlayer *D2)
{
    if (D1->Birthday && D2->Birthday)
    {
        if (D1->Birthday->Year > D2->Birthday->Year)
            return 1;
        if (D1->Birthday->Year < D2->Birthday->Year)
            return -1;
        if (D1->Birthday->Month > D2->Birthday->Month)
            return 1;
        if (D1->Birthday->Month < D2->Birthday->Month)
            return -1;
        if (D1->Birthday->Day > D2->Birthday->Day)
            return 1;
        if (D1->Birthday->Day < D2->Birthday->Day)
            return -1;
        return cmpName(D1, D2);
    }
    return 0;
}

/********************************************************************
 * function:      cmpTrikot
 * description:  vergleich
 * Paramater:     - Datensatz 1
 *                - Datensatz 2
 * return:      Differenz
 *******************************************************************/
int cmpTrikot(TPlayer *D1, TPlayer *D2)
{
    return D1->Number - D2->Number;
}

/********************************************************************
 * function:      cmpGoals
 * description:  vergleich
 * Paramater:     - Datensatz 1
 *                - Datensatz 2
 * return:      Differenz
 *******************************************************************/
int cmpGoals(TPlayer *D1, TPlayer *D2)
{
    int Diff = D1->Goals - D2->Goals;

    if (Diff)
        return Diff;
    return cmpName(D1, D2);
}

