#ifndef fonctionS
  #define fonctionS
  #include "fonctionStructure.h"
#endif

#ifndef screenMenu
  #define screenMenu
  #include "screenMenu.h"
#endif 

#ifndef fonctionEB
  #define fonctionEB
  #include "fonctioneasyBoard.h"
#endif

void easyBoardInitialisation(t_cases tab[10][10]);
void easyBoardFullfill(t_cases tab[10][10]);
void easyBoardDisplay(t_cases tab[10][10]);
void easyBoard(t_cases tab[10][10]);
void easyBoardRecursion(t_cases tab[10][10], int i,int j);
