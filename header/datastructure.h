#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED

   #define MAXPLAYER 23

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

   typedef struct sTeam      // Struktur, um Teamdaten abzuspeichern
   {
      char     *Name;
      char     *Coach;
      int      Size;
      TPlayer  Player[MAXPLAYER];
      struct sTeam *Next;
      struct sTeam *Prev;
   } TTeam;


   extern int TeamCounter;

   extern TTeam *FirstTeam;
   extern TTeam *LastTeam;

#endif
