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
#include "menu.h"
#include "teams.h"

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

/********************************************************************
 * Funktion:      menuDVSortList
 * Beschreibung:  Gibt das Menu für Sortieren aus
 * Paramater:     -/-
 * Ergebnis:      Zahl der Menuauswahl
 *******************************************************************/
int menuDVSortList()
{
   int input;
   char *menuTitle =       "Ausgabe";
   char *menuItems[] = {   "Aufwaerts ausgeben",
                           "Abwaerts ausgeben",
                           "zurueck zum Hauptmenu"};

   input = getMenu(menuTitle, menuItems, 3);  // Menuauswahl
   switch(input)
   {
      case 1: return 1;    break;
      case 2: return 2;    break;
      case 3: return 0;    break;
   }
   return 0;
}
