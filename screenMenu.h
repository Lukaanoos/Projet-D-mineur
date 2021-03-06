#ifndef library
  #define library
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include<string.h>
#endif

#ifndef fonctionEB
  #define fonctionEB
  #include "fonctionEasyBoard.h"
#endif

#ifndef fonctionIB
  #define fonctionIB
  #include "fonctionIntermediateBoard.h"
#endif

#ifndef fonctionS
  #define fonctionS
  #include "fonctionStructure.h"
#endif




void easyBoard(t_cases tab[10][10]);
void easyBoardInitialisation(t_cases tab[10][10]);
void easyBoardFullfill(t_cases tab[10][10]);
void intermediateBoardInitialisation(t_cases tab[17][17]);
void intermediateBoardFullfill(t_cases tab[17][17]);
void intermediateBoard(t_cases tab[17][17]);
void creditScreen();
void rulesMS();
void menuScreen(t_cases Tab1[10][10],t_cases Tab2[17][17]);

