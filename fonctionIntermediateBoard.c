#ifndef fonctionIB
  #define fonctionIB
  #include "focntionIntermediateBoard.h"
#endif



void intermediateBoardInitialisation(t_cases tab[17][17]) // cette partie du code est la meme que la partie "easyBoard" mais cette fois ci pour la grille intermediaire (16*16 avec 40mines)
{
    int i,j;
    for (i=0; i<17; i++)
    {
        for (j=0; j<17; j++)
        {
            tab[i][j].bombe=0;
            tab[i][j].cote=0;
            tab[i][j].etatcote=0;
            tab[i][j].etatb=0;
            tab[i][j].marquage='0';

        }
    }
}






void intermediateBoardFullfill(t_cases tab[17][17])
{
    int alea,alea2;
    int compteur=0;
    int compteurfinal=0;

    do
    {

        alea=rand()%16;
        alea2=rand()%16;
        if (tab[alea][alea2].bombe==1)
        {
            compteur=1;
        }
        else
        {
            tab[alea][alea2].bombe=1;
            tab[alea][alea2].etatcote=1;
            tab[alea][alea2].cote=7;
            tab[alea+1][alea2].cote++;
            tab[alea+1][alea2-1].cote++;
            tab[alea+1][alea2+1].cote++;
            tab[alea-1][alea2].cote++;
            tab[alea-1][alea2+1].cote++;
            tab[alea-1][alea2-1].cote++;
            tab[alea][alea2+1].cote++;
            tab[alea][alea2-1].cote++;
            compteur=0;
            compteurfinal++;
        }


    }
    while((compteur==1)||(compteurfinal<40));

}



void intermediateBoardDisplay(t_cases tab[17][17])
{
    printf("Voici votre Grille:\n");
    printf("   1 2 3 4 5 6 7 8 9 10111213141516 \n");
    int i=0,j=0;
    for (i=0; i<16; i++)
    {
        for (j=0; j<16; j++)
        {
            if(j==0)
            {
                if (i<9)
                {
                    printf(" %d",i+1);
                }
                else
                {
                    printf("%d",i+1);
                }

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
                    printf("|%c",tab[i][j].marquage);
                }
            }


            if(j==15)
            {
                printf("|");
                printf("\n");
            }
        }
    }
}
void intermediateBoard(t_cases tab[17][17])
{

    int choix;
    int nbligne,nbcolone;
    int compteur=40;
    int i,j;
    int perdu=0,gagne=0;
    time_t debut, fin ;
    double difference ;
    do
    {
        gagne=0;
        intermediateBoardDisplay(tab);
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
            while((nbligne<1)||(nbligne>16)||(nbcolone<1)||(nbcolone>16));
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
                    intermediateBoardRecursion(tab,nbligne-1,nbcolone-1);
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
                while((nbligne<1)||(nbligne>16)||(nbcolone<1)||(nbcolone>16));
                tab[nbligne-1][nbcolone-1].marquage='x';
                compteur--;
            }
            else
            {
                printf("Vous n'avez plus de marqueur.\n");
                printf("\n");
            }
        }

        for (i=0; i<16; i++)
        {
            for (j=0; j<16; j++)
            {

                if (tab[i][j].etatcote==1)
                {
                    gagne++;
                }

            }

        }
    }
    while ((perdu==0)&&(gagne<256));
    if (perdu==1)
    {
        printf("                          BOOOOMM !!\n\n\n");
        printf("Une mine a explose !!\n");
        printf("Vous venez de tuer un bon nombre d'innocents et vous compris..\n");
        printf("Je vous avais pourtant dit de ne jamais toucher au fil rouge...\n");
        printf("Heureusement pour vous ce n'est qu'un jeu. \n");
        printf("N'hesitez pas a retentez votre chance !\n");

    }
    if (gagne==256)
    {
        printf("                           VICTOIRE !!\n\n\n");
        printf("Bravo a vous, vous avez demine toute la grille !\n");
        fin=time(NULL) ;
        difference = difftime(fin, debut) ;

        printf("Votre temps est de ':%lf ' secondes\n\n",difference);
    }
}

void intermediateBoardRecursion(t_cases tab[17][17], int i,int j)
{
    if (tab[i][j].etatcote==0)
    {
        tab[i][j].etatcote=1;
        if (tab[i][j].cote==0)
        {
            if (i>0)
            {
                intermediateBoardRecursion(tab,i-1,j);
            }
            if ((i>0 )&&(j>0))
            {
                intermediateBoardRecursion(tab,i-1,j-1);
            }
            if (j>0)
            {
                intermediateBoardRecursion(tab,i,j-1);
            }
            if ((j>0 )&&(i<15))
            {
                intermediateBoardRecursion(tab,i+1,j-1);
            }
            if (i<15)
            {
                intermediateBoardRecursion(tab,i+1,j);
            }
            if ((i>15 )&&(j<15))
            {
                intermediateBoardRecursion(tab,i+1,j+1);
            }
            if (j<15)
            {
                intermediateBoardRecursion(tab,i,j+1);
            }
            if ((i>0 )&&(j<15))
            {
                intermediateBoardRecursion(tab,i-1,j+1);
            }
        }
    }

}
