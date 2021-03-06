/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           teams.c
*** description      managing teams
*** global FKT:      createTeam
***                  deleteTeam
***                  addPlayer
***                  deletePlayer
***                  searchPlayer
***                  sortTeams
***                  listTeams
***                  loadFileMenu
*** local FKT:      createPlayer
***                  listOnePlayer
***                  listOneTeam
****************************************************************************************************
***************************************************************************************************/

#define TEAMSPATH  "./src/xml/teams.xml"
#define NEWTEAMS  "./src/xml/new_teams.xml"
#define SAVETEAMS  "./src/xml/save_teams.xml"

#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "database.h"
#include "menu.h"
#include "sort.h"

int TeamCounter = 0;
TTeam Teams[MAXTEAMS];

/********************************************************************
 * function:     createPlayer
 * description:  enter player
 * paramater:    -/-
 * return:      -/-
 *******************************************************************/
void createPlayer(TPlayer *Player)
{
    getText("\nGeben Sie bitte den Namen des Spielers ein:\n-> ", 50, 0, &(Player->Name));
    getDate("Geben Sie bitte das Geburtsdatum des Spielers ein:\n-> ", &(Player->Birthday));
    getNumber("Geben Sie bitte die Trikotnr. des Spielers ein (1-99):\n-> ", &(Player->Number), 1, 99);
    Player->Goals = 0;
}

/********************************************************************
 * function:      createTeam
 * description:  create a team
 * paramater:     -/-
 * return:      -/-
 *******************************************************************/
void createTeam()
{
    TTeam *Team = Teams +
                  TeamCounter;
    char *title = "Erfassung einer neuen Mannschaft";
    clearScreen();

    if (TeamCounter < MAXTEAMS)
    {
        printf("%s\n", title);
        printLine('=', strlen(title));
        printf("\n\n");

        getText("Geben Sie bitte den Namen der Mannschaften ein:\n-> ", 50, 0, &(Team->Name)); //
        getText("Geben Sie bitte den Namen des Trainers ein:\n-> ", 50, 1, &(Team->Coach));

        Team->Size = 0;

        title = "Erfassung der Spieler";
        printf("\n%s\n", title);
        printLine('-', strlen(title));

        do
        {
            createPlayer((Team->Player) + (Team->Size));
            (Team->Size)++;
            printf("\nAnzahl der Spieler in der Mannschaft: %i",
                   (Team->Size));
        } while (askYesOrNo("\nMoechten sie einen weiteren Spieler eingeben (j/n)? "));
        TeamCounter++;
    } else
    {
        printf("Die maximale Anzahl an Teams(10) ist erreicht!\n\n");
        waitForEnter();
    }
}

/********************************************************************
 * function:      deleteTeam
 * description:  delete a team
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void deleteTeam()
{
    printf("deleteTeam\n\n");
    waitForEnter();
}

/********************************************************************
 * function:      addPlayer
 * description:  add player
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void addPlayer()
{
    printf("addPlayer\n\n");
    waitForEnter();
}

/********************************************************************
 * function:      deletePlayer
 * description:  delete a player
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void deletePlayer()
{
    printf("deletePlayer\n\n");
    waitForEnter();
}

/********************************************************************
 * function:      searchPlayer
 * description:  search a player
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void searchPlayer()
{
    printf("searchPlayer\n\n");
    waitForEnter();
}

/********************************************************************
 * function:      sortTeams
 * description:  sort team
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
int sortTeams()
{
    int input, i;
    char *menuTitel = "Sortieren";
    char *menuItems[] = {"Spieler nach Namen sortieren",
                         "Spieler nach Geburtsdatum sortieren",
                         "Spieler nach TrikotNr. sortieren",
                         "Spieler nach Anzahl geschossener Tore sortieren",
                         "zurueck zum Hauptmenu"};
    input = getMenu(menuTitel, menuItems, 5);  // Menuauswahl
    switch (input)
    {
        case 1:
            for (i = 0; i < TeamCounter; i++)
                QuickSort((Teams + i)->Player, (Teams + i)->Size, cmpName);
            break;
        case 2:
            for (i = 0; i < TeamCounter; i++)
                QuickSort((Teams + i)->Player, (Teams + i)->Size, cmpBirthday);
            break;
        case 3:
            for (i = 0; i < TeamCounter; i++)
                QuickSort((Teams + i)->Player, (Teams + i)->Size, cmpTrikot);
            break;
        case 4:
            for (i = 0; i < TeamCounter; i++)
                QuickSort((Teams + i)->Player, (Teams + i)->Size, cmpGoals);
            break;
        case 5:
            return 0;
    }
    return 0;
}

/********************************************************************
 * function:      listOnePlayer
 * description:  list one player
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void listOnePlayer(TPlayer *Player, int Size)
{
    printf("\n   %02i. %-25s(%02i", Size, Player->Name, Player->Number);
    printDate(Player->Birthday);
    if (Player->Goals == 1)
        printf(" ,%2i Tor", Player->Goals);
    if (Player->Goals != 1)
        printf(" ,%2i Tore", Player->Goals);
    printf(")");
}

/********************************************************************
 * function:      listOneTeam
 * description:  list one team
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void listOneTeam(TTeam *Team)
{
    int i;

    printf("\n\nName               : %s", Team->Name);
    if (Team->Coach)
    {
        printf("\nTrainer            : %s", Team->Coach);
    }
    printf("\nAnzahl der Spieler : %i", Team->Size);
    printf("\nSpieler:");

    for (i = 0; i < (Team->Size); i++)
    {
        listOnePlayer((Team->Player) + i, i + 1);
    }
}

/********************************************************************
 * function:      listTeams
 * description:  List teams
 * Paramater:     -/-
 * return:      -/-
 *******************************************************************/
void listTeams()
{
    int i;

    clearScreen();
    char title[] = "Liste der Mannschaften";
    printf("%s\n", title);
    printLine('=', strlen(title));

    if (TeamCounter == 0)
        printf("\n\nAktuell sind keine Mannschaften erstellt worden!\n\n");

    else
    {
        for (i = 0; i < TeamCounter; i++)
        {
            listOneTeam(Teams + i);
        }
    }
    printf("\n\n");
    waitForEnter();
}

/********************************************************************
 * function:      loadFileMenu
 * description:  print submenu
 * Paramater:     -/-
 * return:      selection(int) submenu
 *******************************************************************/
int loadFileMenu()
{
    int input;
    char *menuTitel = "Datei Laden";
    char *menuItems[] = {"Datei laden (teams.xml)",
                         "Datei laden (new_teams.xml)",
                         "Datei laden (save_teams.xml)",
                         "zurueck zum Hauptmenu"};
    if (TeamCounter < MAXTEAMS)
    {
        input = getMenu(menuTitel, menuItems, 4);  // Menuauswahl
        switch (input)
        {
            case 1:
                load(TEAMSPATH);
                break;
            case 2:
                load(NEWTEAMS);
                break;
            case 3:
                load(SAVETEAMS);
                break;
            case 4:
                return 0;
        }
    } else
    {
        clearScreen();
        printf("Die maximale Anzahl an Teams(10) ist erreicht!\n\n");
        waitForEnter();
    }
    return 0;
}
