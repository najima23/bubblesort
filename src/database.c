/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           database.c
*** description:
*** global FKT:     save
***                  load
*** LOKALE FKT:      loadTeam
***                  loadPlayer
***                  saveTeam
***                  savePlayer
*****************************************************************************************************
****************************************************************************************************/
#define PATH  "/Users/najimajaadari/Desktop/ueb05Naji/src/xml/teams.xml"     // Pfad zum Speichern

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "database.h"
#include "datetime.h"
#include "tools.h"

void loadTeam(char *, FILE *);
void loadPlayer(char *, FILE *, TTeam *);
void saveTeam(TTeam *, FILE *);
void savePlayer(TPlayer *, FILE *);

int load(char *Datei)
{
   FILE *fp;      // fp = filePointer
   char tmp[101];
   char *row;

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
            row = tmp;
            while((*row == ' ') || (*row == 9))
               row++;
            if(strncmp(row, "<Team>", 6) == 0)
            {
               loadTeam(tmp, fp);
            }
            if (feof(fp))
               break;
         }
      } while(strncmp(row, "</Daten>", 8) != 0);
      fclose(fp);
   }
   waitForEnter();
   return 0;
}

void loadTeam(char *tmp, FILE *fp)
{
   char *Zeile;
   int len = 0;
   TTeam *Team = Teams + TeamCounter;

   if(TeamCounter < MAXTEAMS)
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
      TeamCounter++;
   }
}

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

int save(TTeam *D)
{
   FILE *wp;
   int i;

   if(askYesOrNo("Moechten Sie Ihre Eingaben speichern (j/n) ? ") == 1)
   {
      wp = fopen(PATH, "ab+");

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
            for(i = 0; i < TeamCounter; i++)
               saveTeam((Teams+i), wp);
            fprintf(wp, "</Daten>");

            fclose(wp);
         }
         fclose(wp);
      }
   }
   return 1;
}

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
