#ifndef DATETIME_H_INCLUDED
   #define DATETIME_H_INCLUDED

   short isLeapYear(int);
   short isDateValid(TDate);
   short getDateFromString(char *, TDate *);
   void getDate(char *, TDate **);
   void printDate(TDate *);

#endif
