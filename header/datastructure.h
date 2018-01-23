#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED

   #define MAXPLAYER 23
   #define MAXTEAMS  10

   typedef struct       // Struktur, um ein Datum abzuspeichern
   {
      int Day;
      int Month;
      int Year;
   } TDate;

   typedef struct       // Struktur, um Spielerdaten abzuspeichern
   {
      char  *Name;
      TDate *Birthday;
      int   Number;
      int   Goals;
   } TPlayer;

   typedef struct       // Struktur, um Teamdaten abzuspeichern
   {
      char     *Name;
      char     *Coach;
      int      Size;
      TPlayer  Player[MAXPLAYER];
   } TTeam;


    extern int TeamCounter;         // Definition in teams.c
    extern TTeam Teams[];

#endif
