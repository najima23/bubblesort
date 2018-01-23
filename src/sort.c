/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           sort.c
*** description:    file for sort
*** global FKT:     quickSort
***                 cmpName
***                 cmpBirthday
***                 cmpTrikot
***                 cmpGoals
*** local FKT:      swap
***                 partition
***                 qsort
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "sort.h"



/**********************************************************
 * function:      splitarray
 * description:   devide array in two parts each with differents size
 * parameter:     Array - array for sort
 *                lowerPart  - sort lower part of array
 *                higherPart    - sort higher part of array
 * return:     int   - index of middle value
 **********************************************************/
int splitarray(TPlayer *Array, int lowerPart, int higherPart, int (*cmp)(TPlayer *, TPlayer *)  )
{
    int i = lowerPart + 1, j = higherPart;
    TPlayer *comp = (Array + lowerPart);

    while (i <= j)
    {
        // next element search left
        while ((i <= j) && (cmp((Array + i), comp) <= 0))
            i++;
        // next element sort right
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
 * description:  split array in two parts and sort left and
 *                right recursivly
 * Parameter:     Array - array for sort
 *                lowerPart  - sort lower part of array
 *                higherPart    - sort higher part of array
 * return:     -/-
 **********************************************************/
void qsort(TPlayer *Array, int lowerpart, int higherPart, int (*cmp)(TPlayer *, TPlayer *))
{
    int middleValue;      // middle value

    if (lowerpart >= higherPart) // termination condition of the recursion
        return;
    else
    {
        middleValue = splitarray(Array, lowerpart, higherPart, cmp);
        qsort(Array, lowerpart, middleValue - 1, cmp); // sort left part recursively
        qsort(Array, middleValue + 1, higherPart, cmp); // sort right part recursively
    }
}

/***********************************************************
 * function:      QuickSort
 * description:  Sorts the specified number array in ascending order.
 * Parameter:     *Array  – pointer of sort array
 *                count - count element of array
 * return:     -/-
 ***********************************************************/
void QuickSort(TPlayer *Array, int count, int (*cmp)(TPlayer *, TPlayer *))
{
    printf("count: %i\n", count);
    qsort(Array, 0, count - 1, cmp);
}

/********************************************************************
 * function:      swap
 * description:  comparison
 * Paramater:     - dataset 1
 *                - dataset 2
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
 * description:  comparison
 * Paramater:     - dataset 1
 *                - dataset 2
 * return:      difference
 *******************************************************************/
int cmpName(TPlayer *D1, TPlayer *D2)
{
    return strcmp(D1->Name, D2->Name);
}

/********************************************************************
 * function:      cmpBirthday
 * description:  comparison
 * Paramater:     - dataset 1
 *                - dataset 2
 * return:      difference
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
 * description:  comparison
 * Paramater:     - dataset 1
 *                - dataset 2
 * return:      difference
 *******************************************************************/
int cmpTrikot(TPlayer *D1, TPlayer *D2)
{
    return D1->Number - D2->Number;
}

/********************************************************************
 * function:      cmpGoals
 * description:  comparison
 * Paramater:     - dataset 1
 *                - dataset 2
 * return:      difference
 *******************************************************************/
int cmpGoals(TPlayer *D1, TPlayer *D2)
{
    int Diff = D1->Goals - D2->Goals;

    if (Diff)
        return Diff;
    return cmpName(D1, D2);
}


/********************************************************************
 * Funktion:      toUpper
 * Beschreibung:  kleine Buchstaben zu große Buchstaben
 * Paramater:     -/-
 * Ergebnis:      -/-
 *******************************************************************/
/*char toUpper(char c)
{
   if((c >= 'a') && (c <= 'z'))
      return c -32;
   if(c == 228)
      return c -32;
   if(c == 235)
      return c -32;
   if(c == 252)
      return c -32;
   return c;
}
*/
