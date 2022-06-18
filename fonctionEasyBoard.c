#ifndef fonctionEB
  #define fonctionEB
  #include "fonctionEasyBoard.h"
#endif





////////////////////////////////////////////////////////////////////////////////////////////
/*cette fonction va permettre de creer la grille de jeu du mode Facile (9*9 avec 10 mines)*/
////////////////////////////////////////////////////////////////////////////////////////////
void easyBoardInitialisation(t_cases tab[10][10])
{
    int i,j;
    for (i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
        {
            tab[i][j].bombe=0;
            tab[i][j].cote=0;
            tab[i][j].etatcote=0;
            tab[i][j].etatb=0;
            tab[i][j].marquage='0';

        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////
/*cette fonction va servir a remplir notre grille (qui est en fait un tableau a 2 dimensions) */
////////////////////////////////////////////////////////////////////////////////////////////////

void easyBoardFullfill(t_cases tab[10][10])
{
    int alea,alea2;
    int compteur=0;
    int compteurfinal=0;

    do
    {
//deux axes x et y il nous faut donc 2 "alea" qui vont nous permettre d'inserer les mines de manieres aleatoires dans les tableaux
        alea=rand()%9;
        alea2=rand()%9;
        if (tab[alea][alea2].bombe==1)
        {
            compteur=1; //ici on s'assure que l'emplacement choisi par la fonction "rand" ne contient pas deja une mine
        }
        else
        {
            tab[alea][alea2].bombe=1; //c'est pourquoi on doit aussi faire en sorte que des qu'une mine est placee, on lui donne une valeur
            tab[alea][alea2].etatcote=1;
            tab[alea][alea2].cote=7;  // on donne une valeur au cases contenant une mine ne pouvant etre atteintes par d'autres cases pour ne pas avoir de problemes ensuite
            tab[alea+1][alea2].cote++; //le long processus qui suit permet de rajouter 1 a chaque autour de la mine venant d'etre placee
            tab[alea-1][alea2-1].cote++;
            tab[alea][alea2+1].cote++;
            tab[alea][alea2-1].cote++;
            compteur=0;
            compteurfinal++; // le compteur final permet de s'assurer qu'on ne place pas plus de 9 mines
        }


    }
    while((compteur==1)||(compteurfinal<10));

}

///////////////////////////////////////////////////////////////////////////////////////
/*cette fonction va servir a afficher la grille venant d'etre creer et remplie       */
///////////////////////////////////////////////////////////////////////////////////////

void easyBoardDisplay(t_cases tab[10][10])
{
    printf("Voici votre Grille:\n");
    printf("  1 2 3 4 5 6 7 8 9 \n"); // sert a afficher les colonnes
    int i=0,j=0;
    for (i=0; i<9; i++)
    {
        for (j=0; j<9; j++)
        {
            if(j==0)
            {
                printf("%d",i+1); //sert a afficher les lignes
            }
            if (tab[i][j].marquage=='0')
            {

                if (tab[i][j].etatcote==0)
                {
                    printf("| ");
                }
                if (tab[i][j].etatcote==1)
                {
                    if (tab[i][j].cote>=7)
                    {
                        printf("| ");
                    }
                    else
                    {
                        printf("|%d",tab[i][j].cote);
                    }
                }
            }
            else
            {
                if (tab[i][j].marquage=='x')
                {
                    printf("|%c",tab[i][j].marquage); // introduction des marqueurs de mines
                }
            }


            if(j==8)
            {
                printf("|");
                printf("\n");
            }
        }
    }
}
void easyBoard(t_cases tab[10][10])
{

    int choix;
    int nbligne,nbcolone;
    int compteur=10;
    int i,j;
    int perdu=0,gagne=0;
    time_t debut, fin ; // pour le timer
    double difference ;


    debut=time(NULL) ;
    do
    {
        gagne=0;
        easyBoardDisplay(tab);
        printf("\n");
        printf("Il reste %d bombes a placer.\n",compteur);
        do
        {
            printf("Voulez vous :\n");
            printf(" 1. Decouvrir une case\n");
            printf(" 2. Placer un marqueur de bombe\n");
            scanf("%d",&choix);
        }
        while ((choix!=1)&&(choix!=2));

        if (choix==1)
        {
            do
            {
                printf("Veuillez indiquer les coordonnees \n") ;
                printf("Quelle ligne:\n");
                scanf("%d",&nbligne);
                printf("Quelle colonne:\n");
                scanf("%d",&nbcolone);
            }
            while((nbligne<1)||(nbligne>9)||(nbcolone<1)||(nbcolone>9));
            if (tab[nbligne-1][nbcolone-1].bombe==1)
            {
                perdu=1;
            }
            else
            {
                if (tab[nbligne-1][nbcolone-1].cote>0)
                {
                    tab[nbligne-1][nbcolone-1].etatcote=1;
                }
                else
                {
                    easyBoardRecursion(tab,nbligne-1,nbcolone-1);
                }
            }

        }
        else
        {
            if (compteur>0)
            {
                do
                {
                    printf("Veuillez indiquer les coordonnees \n") ;
                    printf("Quelle ligne:\n");
                    scanf("%d",&nbligne);
                    printf("Quelle colonne:\n");
                    scanf("%d",&nbcolone);
                }
                while((nbligne<1)||(nbligne>9)||(nbcolone<1)||(nbcolone>9));
                tab[nbligne-1][nbcolone-1].marquage='x';
                compteur--;
            }
            else
            {
                printf("Vous n'avez plus de marqueur.\n");
                printf("\n");
            }
        }

        for (i=0; i<9; i++)
        {
            for (j=0; j<9; j++)
            {

                if (tab[i][j].etatcote==1)
                {
                    gagne++;
                }

            }

        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while ((perdu==0)&&(gagne<81));
    if (perdu==1) // ecran de defaite
    {
        printf("                          BOOOOMM !!\n\n\n");
        printf("Une mine a explose !!\n");
        printf("Vous venez de tuer un bon nombre d'innocents et vous compris..\n");
        printf("Je vous avais pourtant dit de ne jamais toucher au fil rouge...\n");
        printf("Heureusement pour vous ce n'est qu'un jeu. \n");
        printf("N'hesitez pas a retentez votre chance !\n");

    }
    if (gagne==81) //ecran de victoire
    {
        printf("                           VICTOIRE !!\n\n\n");
        printf("Bravo a vous, vous avez demine toute la grille !\n");
        fin=time(NULL) ;
        difference = difftime(fin, debut) ;
        printf("Votre temps est de ':%lf ' secondes\n\n",difference); // le temps s'affichera en secondes
    }
}

void easyBoardRecursion(t_cases tab[10][10], int i,int j) /* cette recursion va permettre au programme de faire le tour de la grille a la fin de chasue tour afin de verifier l'etat des cases (decouverte ou non)*/
{
    if (tab[i][j].etatcote==0)
    {
        tab[i][j].etatcote=1;
        if (tab[i][j].cote==0)
        {
            if (i>0)
            {
                easyBoardRecursion(tab,i-1,j);
            }
            if ((i>0 )&&(j>0))
            {
                easyBoardRecursion(tab,i-1,j-1);
            }
            if (j>0)
            {
                easyBoardRecursion(tab,i,j-1);
            }
            if ((j>0 )&&(i<8))
            {
                easyBoardRecursion(tab,i+1,j-1);
            }
            if (i<8)
            {
                easyBoardRecursion(tab,i+1,j);
            }
            if ((i>8 )&&(j<8))
            {
                easyBoardRecursion(tab,i+1,j+1);
            }
            if (j<8)
            {
                easyBoardRecursion(tab,i,j+1);
            }
            if ((i>0 )&&(j<8))
            {
                easyBoardRecursion(tab,i-1,j+1);
            }
        }
    }

}
