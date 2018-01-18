/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           database.c
*** BESCHREIBUNG:
*** GLOBALE FKT:     save
***                  load
*** LOKALE FKT:      loadTeam
***                  loadPlayer
***                  saveTeam
***                  savePlayer
*****************************************************************************************************
****************************************************************************************************/
#define PATH  "IN2/save_teams.xml"     // Pfad zum Speichern

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "database.h"
#include "datetime.h"
#include "tools.h"
#include "list.h"

void loadTeam(char *, FILE *);
void loadPlayer(char *, FILE *, TTeam *);
void saveTeam(TTeam *, FILE *);
void savePlayer(TPlayer *, FILE *);

/********************************************************************
 * Funktion:      load
 * Beschreibung:  Eine .XML Datei wird eingelesen werden
 * Paramater:     Datei zum Laden
 * Ergebnis:      -/-
 *******************************************************************/
int load(char *Datei)
{
   FILE *fp;      // fp = filePointer
   char tmp[101];
   char *Zeile;

   fp = fopen(Datei, "rt");
   if (fp == NULL)
   {
      printf("\nDatei konnte nicht gelesen werden!\n");
      waitForEnter();
      clearScreen();
      return 0;
   }
   else
   {
      do
      {
         while((fgets(tmp, 100, fp)) != NULL)
         {
            Zeile = tmp;
            while((*Zeile == ' ') || (*Zeile == 9))
               Zeile++;
            if(strncmp(Zeile, "<Team>", 6) == 0)
            {
               loadTeam(tmp, fp);
            }
            if (feof(fp))
               break;
         }
      } while(strncmp(Zeile, "</Daten>", 8) != 0);
      fclose(fp);
   }
   waitForEnter();
   return 0;
}

/********************************************************************
 * Funktion:      loadTeam
 * Beschreibung:  Laedt die Teams aus der Datei
 * Paramater:     *tmp -
 *                *fp - FilePointer
 * Ergebnis:      -/-
 *******************************************************************/
void loadTeam(char *tmp, FILE *fp)
{
   char *Zeile;
   int len = 0;
   TTeam *Team = calloc(1, sizeof(TTeam));

   if(Team)
   {
      Team->Name = NULL;
      Team->Coach = NULL;
      Team->Size = 0;

      do
      {
         Zeile = tmp;
         fgets(tmp, 100, fp);
         while((*Zeile == ' ') || (*Zeile == 9))
            Zeile++;
         if(strncmp(Zeile, "<Player>", 8) == 0)
            loadPlayer(tmp, fp, Team);

         /* Ausgabe Manschaftsname */
         if(strncmp(Zeile, "<Name>", 6) == 0)
         {
            len = strlen(Zeile + 6) - 8;           // -2 differenz wegen \r
            if (*(Zeile + strlen(Zeile) - 2) == '\r')
                  len--;
            Team->Name = calloc(len + 1, sizeof(char));
            if(Team->Name)
               strncpy(Team->Name, Zeile + 6, len);
         }

         /* Ausgabe Trainername */
         if(strncmp(Zeile, "<Trainer>", 9) == 0)
         {
            len = strlen(Zeile + 9) - 11;           // -2 differenz wegen \r
            if (*(Zeile + strlen(Zeile) - 2) == '\r')
                  len--;
            Team->Coach = calloc(len + 1, sizeof(char));
            if(Team->Coach)
               strncpy(Team->Coach, Zeile + 9, len);
         }
      } while(strncmp(Zeile, "</Team>", 7) !=  0);
      insertInDVList(Team);
      TeamCounter++;
   }
}

/********************************************************************
 * Funktion:      loadPlayer
 * Beschreibung:  Laedt die Spieler aus der Datei
 * Paramater:     *tmp -
 *                *fp - FilePointer
 *                *Team - Das Team, wo die Spieler ausgelesen werden soll
 * Ergebnis:      -/-
 *******************************************************************/
void loadPlayer(char *tmp, FILE *fp, TTeam *Team)
{
   char *Zeile;
   int len = 0;
   TPlayer *Player = Team->Player + Team->Size;

   if(Team->Size < MAXPLAYER)
   {
      do
      {
         Zeile = tmp;
         fgets(tmp, 100, fp);
         while((*Zeile == ' ') || (*Zeile == 9))
            Zeile++;
         if(strncmp(Zeile, "</Player>", 9) != 0)
         {
            /* Ausgabe Spielername */
            if(strncmp(Zeile, "<Name>", 6) == 0)
            {
               len = strlen(Zeile + 6) - 8;           // -2 differenz wegen \r
               if (*(Zeile + strlen(Zeile) - 2) == '\r')
                  len--;
               Player->Name = calloc(len + 1, sizeof(char));
               if(Player->Name)
                  strncpy(Player->Name, Zeile + 6, len);
            }

            /* Ausgabe Geburtstag */
            if(strncmp(Zeile, "<Birthday>", 10) == 0)
            {
               len = strlen(Zeile + 10) - 12;           // -2 differenz wegen \r
               if (*(Zeile + strlen(Zeile) - 2) == '\r')
                  len--;
               Player->Birthday = calloc(1, sizeof(TDate));
               if(Player->Birthday)
               {
                  getDateFromString(Zeile+10, Player->Birthday);
               }
            }

            /* Ausgabe Trikotnummer */
            if(strncmp(Zeile, "<TricotNr>", 10) == 0)
            {
               len = strlen(Zeile + 10) - 12;           // -2 differenz wegen \r
               if (*(Zeile + strlen(Zeile) - 2) == '\r')
                  len--;
               Player->Number = atoi(Zeile + 10);
            }

            /* Ausgabe Tore */
            if(strncmp(Zeile, "<Goals>", 7) == 0)
            {
               len = strlen(Zeile + 7) - 9;           // -2 differenz wegen \r
               if (*(Zeile + strlen(Zeile) - 2) == '\r')
                  len--;
               Player->Goals = atoi(Zeile + 7);
            }
         }
      } while(strncmp(Zeile, "</Player>", 9) != 0);
      (Team->Size)++;
   }
   else
      fgets(tmp, 100, fp);
}

/********************************************************************
 * Funktion:      save
 * Beschreibung:  Speichert Inhalte in eine Datei
 * Paramater:     -/-
 * Ergebnis:      0 - nicht erfolgreich gespeichert
 *                1 - erfolgreich gespeichert
 *******************************************************************/
int save()
{
   FILE *wp;

   if(askYesOrNo("Moechten Sie Ihre Eingaben speichern (j/n) ? ") == 1)
   {
      wp = fopen(PATH, "w");

      if (wp == NULL)
      {
         printf("Datei, um Daten zu speichern, konnte nicht geöffnet werden!\n");
         waitForEnter();
         clearScreen();
         return 0;
      }
      else
      {
         if(TeamCounter != 0)
         {
            fprintf(wp, "<Daten>\n");
            TTeam *tmp = FirstTeam;
            while(tmp)
            {
               saveTeam(tmp, wp);
               tmp = tmp->Next;
            }
            fprintf(wp, "</Daten>");
            fclose(wp);
         }
         fclose(wp);
      }
   }
   return 1;
}

/********************************************************************
 * Funktion:      saveTeam
 * Beschreibung:  Speichert das Team in die Datei
 * Paramater:     *D - ??
 *                *wp - ??
 * Ergebnis:      -/-
 *******************************************************************/
void saveTeam(TTeam *D, FILE *wp)
{
   int i;
   fprintf(wp," <Team>\n");
   fprintf(wp,"  <Name>%s</Name>\n", D->Name);
   if(D->Coach)
      fprintf(wp,"  <Trainer>%s</Trainer>\n", D->Coach);

   for(i = 0; i < D->Size; i++)
   {
      savePlayer(D->Player + i, wp);
   }
   fprintf(wp," </Team>\n");
}

/********************************************************************
 * Funktion:      savePlayer
 * Beschreibung:  Speichert die Speieler in die Datei
 * Paramater:     *P - ??
 *                *wp - ??
 * Ergebnis:      -/-
 *******************************************************************/
void savePlayer(TPlayer *P, FILE *wp)
{
   fprintf(wp, "  <Player>\n");
   fprintf(wp, "   <Name>%s</Name>\n", P->Name);
   if(P->Birthday)
      fprintf(wp, "   <Birthday>%02i.%02i.%4i</Birthday>\n", P->Birthday->Day, P->Birthday->Month, P->Birthday->Year);
   fprintf(wp, "   <TricotNr>%02i</TricotNr>\n", P->Number);
   fprintf(wp, "   <Goals>%i</Goals>\n", P->Goals);
   fprintf(wp, "  </Player>\n");
}
