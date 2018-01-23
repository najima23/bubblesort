#ifndef DATETIME_H_INCLUDED
   #define DATETIME_H_INCLUDED

   short isLeapYear(int);                       // Überprüft, ob es sich um ein Schaltjahr handel
   short isDateValid(TDate);                    // Überprüft ein übergebenes Datum
   short getDateFromString(char *, TDate *);    // Extrahiert aus einem String ein Datum und speichert es in eine Struktur
   void getDate(char *, TDate **);
   void printDate(TDate *);                     // Datumausgabe

#endif
