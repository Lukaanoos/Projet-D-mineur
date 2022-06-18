#ifndef fonctionMenu
  #define fonctionMenu
  #include "screenMenu.h"
#endif




void creditsScreen()
{
    printf("Merci a vous d'avoir joue a notre Demineur.\nOn espere que celui-ci vous aura plu et on vous souhaite de battre tous les records !!\nEnfin si vous vous en sentez capables bien sur ....\n\n");
    printf("                                      Il vous a ete presente par:                  \n\n");
    printf("-----------------------                    RODRIGUEZ Luka                  -----------------------\n");
    printf("---------------------                      IZEM Wissam                       -----------------------\n");
    printf("-----------------------                    BOUABDALLAH Yassine             -----------------------\n");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void rulesMS()
{
    printf("                                      Comment jouer au demineur ?   \n\n");
    printf("\nVous devez déminer un champ de mines. Pour cela, il a été découpé en carrés qui peuvent contenir\nsoit une seule mine 'X', soit aucune.\nAu début, les mines, enterrées, ne sont bien évidement pas visibles.\n");
    printf("\nPour gagner au Démineur, il vous faut déterminer l'emplacement de toutes les mines.\n");
    printf("\nPour atteindre cet objectif, vous pourrez prendre connaissance du nombre de mines \ndans le voisinage immédiat d'une case, en choisissant l'option 'Découvrir une case' puis en indiquant \nses coordonnées et à condition qu'elle ne cache pas une mine. \nCar attention, si jamais vous dévoilez une case contenant une mine, vous perdrez automatiquement la partie !\n");
    printf("\nIl vous est aussi possible de 'Placer un marqueur de mines', permettant d'indiquer l'emplacement supposé d'une mine.\n");
    printf("Si la case découverte est vide et ne se trouve pas à côté d'une bombe, toutes les autres cases vides adjacentes \ns'ouvriront à la suite jusqu'à tomber sur une case collée à une bombe.\n");
    printf("\nPour gagner, il ne doit pas y avoir de mines incorrectement marquée.\nEn revanche, il n'est pas nécessaire de marquer toutes les mines pour terminer la partie; \nvous avez juste besoin de découvrir toutes les cases vides.");
    printf("\nChaque partie est chronométrée, le timer s'affichera après chaque victoire et sera enregistrée dans un fichier \nafin de conserver vos meilleurs performances.");
    printf("\n\nAlors vous aussi, lancez vous dans l'aventure du Démineur mais surtout n'oubliez pas:");
    printf("\n\n                                    Ne touchez JAMAIS au fil rouge ...!!");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void menuScreen(t_cases Tab1[10][10],t_cases Tab2[17][17])
{
    int c;
    printf("---------      ----      -----------\n");
    printf("         ------    ------           \n");
    printf("-------------        ---------------\n");
    printf("-----------            -------------\n");
    printf("---------    DEMINEUR    -----------\n");
    printf("-----------            -------------\n");
    printf("-------------        ---------------\n");
    printf("         ------    ------           \n");
    printf("--------       ----      -----------\n");
    printf("\n\n\n\n");
    do
    {
        printf("Que souhaitez-vous faire ?\n\n");
        printf("1.Mode Facile.             \t2.Mode Intermediaire.\n3.Comment Jouer ?              \t4.Credits.\n");
        scanf("%d",&c);
    }
    while(c<1 || c>4);
    if(c==1)
    {
        easyBoardInitialisation(Tab1);
        easyBoardFullfill(Tab1);
        easyBoard(Tab1);
    }
    else
    {
        if(c==2)
        {
            intermediateBoardInitialisation(Tab2);
            intermediateBoardFullfill(Tab2);
            intermediateBoard(Tab2);
        }
        else
        {
            if(c==3)
            {
                rulesMS();
            }
            else
            {
                creditsScreen();
            }
        }
    }

}
