#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED

   #define MAXPLAYER 23
   #define MAXTEAMS  10

   typedef struct       //  struct save date
   {
      int Day;
      int Month;
      int Year;
   } TDate;

   typedef struct
   {
      char  *Name;
      TDate *Birthday;
      int   Number;
      int   Goals;
   } TPlayer;

   typedef struct
   {
      char     *Name;
      char     *Coach;
      int      Size;
      TPlayer  Player[MAXPLAYER];
   } TTeam;


    extern int TeamCounter;
    extern TTeam Teams[];

#endif
