all: Demineur

main.o: main.c screenMenu.h fonctionEasyBoard.h fonctionIntermediateBoard.h fonctionStructure.h
	gcc -c $< -o $@

fonctionscreenMenu.o: screenMenu.c screenMenu.h
	gcc -c $< -o $@

fonctionStructure.o: fonctionStructure.h
	gcc -c $< -o $@

fonctionEasyBoard.o: fonctionEasyBoard.c fonctionEasyBoard.h
	gcc -c $< -o $@
  
fonctionIntermediateBoard.o: fonctionIntermediateBoard.c fonctionIntermediate.h
	gcc -c $< -o $@

Demineur: main.o screenMenu.o fonctionStructure.o fonctionEasyBoard.o fonctionIntermediateBoard.o
	gcc $^ -o $@
