#ifndef fonctionS
  #define fonctionS
  #include "fonctionStructure.h"
#endif

#ifndef screenMenu
  #define screenMenu
  #include "screenMenu.h"
#endif


void intermediateBoardInitialisation(t_cases tab[17][17]);
void intermediateBoardFullfill(t_cases tab[17][17]);
void intermediateBoardDisplay(t_cases tab[17][17]);
void intermediateBoard(t_cases tab[17][17]);
void intermediateBoardRecursion(t_cases tab[17][17], int i,int j);
