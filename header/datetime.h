#ifndef DATETIME_H_INCLUDED
   #define DATETIME_H_INCLUDED

   short getDateFromString(char *, TDate *);    // Extrahiert aus einem String ein Datum und speichert es in eine Struktur
   void getDate(char *, TDate **);
   void printDate(TDate *);                     // Datumausgabe

#endif
