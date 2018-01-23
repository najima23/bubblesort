/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           menu.c
*** BESCHREIBUNG:    Zeichnet das Hauptmenu und nimmt die Auswahl der Unterfunktionen entgegen.
*** GLOBALE FKT:     getMenu
*** LOKALE FKT:      -/-
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "tools.h"

/********************************************************************
 * Funktion:      getMenu
 * Beschreibung:  Gibt den Titel des Menusund die einzelene
 *                Untermenus aus.
 * Paramater:     Titelname
 *                Text der Untermenus
 *                Anzahl der Menus
 * Ergebnis:      Zahl der Menuauswahl
 *******************************************************************/
int getMenu(char *titel, char **menuItem, int numberOfItems)
{
   int input = 0,
       i;

   do
   {
      clearScreen();

      printf("%s\n", titel);
      printLine('=', strlen(titel));                     // Ausgabe Menutitel
      printf("\n\n");

      for (i = 0 ; i < numberOfItems ; i++)              // Ausgabe Untermenus
         printf("%02d. %s\n", i+1, *(menuItem+i) );

      printf("\nIhre Wahl: ");                           // Auswahl des Untermenus
      scanf("%d", &input);
      clearBuffer();

   } while (input < 1 || input > numberOfItems);         // Solange keine gueltige Eingabe getaetigt

   return input;
}
