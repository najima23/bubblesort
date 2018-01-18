#ifndef TOOLS_H
   #define TOOLS_H TOOLS.H

   void clearBuffer();                          // Leert den Tastaturpuffer
   void clearScreen();                          // Leert den Terminal
   int askYesOrNo(char *);                    // Ja/Nein Abfrage
   void waitForEnter();                         // Eingabeaufforderung der Entertaste
   void printLine(char, int);                   // Gibt ein Zeichen mit der gewuenschten Anzahl aus
   short getText(char *, int, int, char **);
   void getNumber(char *, int *, int, int);
   char* clearSpaceOrTab(char *);

#endif
