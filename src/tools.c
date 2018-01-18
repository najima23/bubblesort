/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           tools.c
*** BESCHREIBUNG:    Stellt einige nützliche Funktionen zur Verfügung
*** GLOBALE FKT:     clearBuffer
***                  clearScreen
***                  printLine
***                  WaitForEnter
***                  AskYesOrNo
***                  getNumber
*** LOKALE FKT:      -/-
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"


/**********************************************************
* Funktion:     clearBuffer
* Beschreibung: Tastaturpuffer leeren
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearBuffer()
{
   while (getchar() != '\n')
      ;
}

/**********************************************************
* Funktion:     clearScreen
* Beschreibung: Leert die Konsole
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearScreen()
{
   #ifdef __unix__
      #define clrscreen() system("clear")    // Leert die Konsole (Unix)
   #else
      #define clrscreen() system("CLS")      // Leert die Konsole (Windows)
   #endif __unix__

   clrscreen();
}

/**********************************************************
 * Funktion:      askYesOrNo
 * Beschreibung:  Nachfrage, ob etwas wiederholt werden soll
 * Parameter:     Promttext in Stringform
 * Ergebnis:      1 wenn j oder J eingegeben wurde,
 *                0 wenn n oder N
**********************************************************/
short askYesOrNo(char *prompt)
{
   unsigned char input;

   do
   {
      printf("%s", prompt);                                    // Abfrage zum Wiederholen anzeigen

      if ( (input = getchar()) != '\n')                        // Einlesen eines Chars
         clearBuffer();

      switch (input)                                           // Überprüfung des Chars
      {
         case 'j':
         case 'J': return 1;
         case 'n':
         case 'N': return 0;
         default: input = '\0';
      }
   } while (!input);                                           // Solange nicht ja oder nein eingegeben wurde

   return 0;   // Dummy, sonst gibts Compilerfehler
}

/**********************************************************
 * Funktion:      waitForEnter
 * Beschreibung:  Eingabeaufforderung zur Betätigung
 *                der Eingabetaste (Piratentaste, arrrrr)
 * Parameter:     -/-
 * Ergebnis:      -/-
**********************************************************/
void waitForEnter()
{
   puts("Bitte Eingabetaste druecken ...");
   clearBuffer();
}

/**********************************************************
 * Funktion:     printLine
 * Beschreibung: Gibt ein Zeichen in der gewuenschten
 *               Anzahl aus
 * Parameter:    - 1 Zeichen
 *               - Anzahl der Wiederholungen
 * Ergebnis:     -/-
**********************************************************/
void printLine(char Symbol, int lineLenght)
{
   int i;

   for (i = 0; i < lineLenght ; i++)
      putchar(Symbol);
}

/**********************************************************
 * Funktion:     getText
 * Beschreibung: XXXXXXXXXX
 * Parameter:    - Text der Eingelesen werden soll
 *               - maximale Anzahl an Zeichen
 *               - 0/1 leere eingabe nicht zulässig/zulässig
 *               - Zeiger auf Text, der in der Datenstruktur
 *                 gespeichert werden soll
 * Ergebnis:     - 1/0 Funktioniert/Funktioniert nicht
**********************************************************/
short getText(char *Prompt, int MaxLen, int AllowEmpty, char **Text)
{
   char *Input;
   char Format[20];
   int scanErg;
   int Len;                                                    // Länge
   if (MaxLen <=0)
      return 0;
   if (Text == NULL)
      return 0;
    *Text = NULL;
   Input = calloc(MaxLen +1, sizeof(char));                    // Speicher reservieren // im ersten Zeichen wird ein \0 gespeichert
   if (Input)                                                  // Prüfen, ob Speicher reserviert worden istt
   {
      sprintf(Format, "%%%i[^\n]", MaxLen);                   // Kapitel 5
      do
      {
         printf("%s", Prompt);
         scanErg = scanf(Format, Input);
         clearBuffer();
         Len = strlen (Input);                               // Wie lang ist die eingabe
         if (Len >0)
         {
            *Text = malloc((Len +1) * sizeof(char));        //
            if (Text)
            {
               strcpy(*Text, Input);
            }
            else
            {
               free(Input);
               return 0;
            }
            }
            else
            {
               if(AllowEmpty)
               {
                  free(Input);
                  return 1;
               }
               else
               {
                scanErg=0;
               }
            }
      } while(scanErg == 0);
      free(Input);
      return 1;
   }
   return 0;
}

/**********************************************************
 * Funktion:     getNumber
 * Beschreibung: XXXXXXXXXX
 * Parameter:    - Text der Eingelesen werden soll
 *               - Zeiger auf Text, der in der Datenstruktur
 *                 gespeichert werden soll
 *               - Gueltiger Zahlenbereich VON
 *               - Gueltiger Zahlenbereich BIS
 * Ergebnis:     -/-
**********************************************************/
void getNumber(char *Prompt, int *Number, int From, int To)
{
   int zahl;
   do
   {
      printf("%s", Prompt);
      zahl = 0;
      scanf("%d", &zahl);
      clearBuffer();
   } while (zahl < From || To < zahl);
   *Number = zahl;
}

/**********************************************************
 * Funktion:      clearSpaceOrTab
 * Beschreibung:  Wenn ein Zeiger auf ein space oder tab im
 *                string zeigt, geh ein Zeichen weiter.
 * Parameter:     zu prüfenden Zeiger
 * Ergebnis:      -/-
**********************************************************/
char* clearSpaceOrTab(char *Prompt)
{
   while((*Prompt == ' ') || (*Prompt == 9))
      Prompt++;
   return Prompt;
}
