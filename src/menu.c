/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           menu.c
*** description:    print menu & get menu
*** global FKT:     getMenu
*** LOKALE FKT:      -/-
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "tools.h"

/********************************************************************
 * function:      getMenu
 * description:  print title und submenus
 * Paramater:     titel
 *                menuItem
 *                number auf submenu
 * return:      int chosen menu
 *******************************************************************/
int getMenu(char *titel, char **menuItem, int numberOfItems)
{
    int input = 0,
            i;

    do
    {
        clearScreen();

        printf("%s\n", titel);
        printLine('=', strlen(titel));                     //  Menutitel
        printf("\n\n");

        for (i = 0; i < numberOfItems; i++)              // submenus
            printf("%02d. %s\n", i + 1, *(menuItem + i));

        printf("\nIhre Wahl: ");
        scanf("%d", &input);
        clearBuffer();

    } while (input < 1 || input > numberOfItems);

    return input;
}
