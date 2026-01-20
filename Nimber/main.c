/*Projet language C de Thomas de KERSABIEC, IS, DMRDS
Groupe 3*/

#include<stdio.h>
#define VMIN 5
#define VMAX 30

int Lire_Entier (int mini, int maxi)
/*Répéter Ecrire saisir n et p lire (n, p) Jusqu’à (n > p et p > 0)
*/

{
  int Entier;
  printf("Saisissez un nombre entier compris entre %d et %d : ",VMIN, VMAX);
  do
  {
    scanf("%d",&Entier);
    if (!(VMIN < Entier && Entier <= VMAX))
    {
      printf("la saisie est mauvaise, veuillez reccomencer");
    }
  }while(!(VMIN < Entier && Entier <= VMAX));
  //tant que la saisie est correcte ou fonctionne
  return Entier;
}

void Calcul_Nimbers(int nim[][VMAX], int nlig, int ncol) 
/*nlig et ncol déclarés après le main
/!\ ouverture d'accolades */
{
    nim[ncol-1][nlig-1] = 0;
    for (y = nlig-2; y >= 0; y--) 
{
        if (nim[ncol-1][y+1] == 1 && nim[ncol-1][y+2] == 1)
            nim[ncol-1][y] = 0;
        else
            nim[ncol-1][y] = 1;
}
    for (x = ncol-2; x >= 0; x--) 
{
        if (nim[x+1][nlig-1] == 1 && nim[x+2][nlig-1] == 1)
            nim[x][nlig-1] = 0;
        else
            nim[x][nlig-1] = 1;
        for (y = nlig-2; y >= 0; y--) 
      {
            if (x != ncol-1 && nim[x+1][y+1] == 0
                )
                nim[x][y] = 0;
            else
                nim[x][y] = 1;
        }
    }
}
/*x et y varaibles calcul nimber par case*/
int Coup_Ordi_Gagnant(int nb_vois, T_Case vois[][VMIN], int nim[][VMAX]) 
{
    int i, choice = -1;
    for (i = 0; i < nb_vois; i++) 
    { 
        if (nim[vois[i].x - 1][vois[i].y - 1] == 0) 
        {
            choice = i+1;
            break;
        }
    }
    if (choice == -1)
        choice = Coup_Ordi_Hasard(nb_vois, vois);

    return choice;
}
/*vois ??? poser question
fonction coup_ordi ok (testé sur le main de qqn d'un autre groupe)*/
void Deplacement(T_Case *pion, int rangVois, T_Case vois[]) {
    pion->x = vois[rangVois].x;
    pion->y = vois[rangVois].y;
}
/*txt du printf modifié. 
erreur avec var choice : à déclarer !!!*/
int Coup_joueur(int nb_vois, T_Case vois[]) {
    int i, choice;
    printf("C'est votre tour de jouer !\n");
    printf("Ou voulez vous déplacer votre pion ? ");
    for (i = 1; i <= nb_vois; i++) {
        printf("%d:(%d,%d)", i, vois[i-1].x, vois[i-1].y);
    if (i!=nb_vois) 
        printf(" | ");
    }
    printf("\nChoix : ");

    //la valeur et la direction du déplacement sont repris
    Lire_Entier(&choice, 1, nb_vois);

    return choice;
}
/* déclas variables ok
param avec move à tester (marchait pas dans la main d'un autre)*/
int main ()
{
int nlig;
int ncol;
int nim[VMAX][VMAX];
int x, y;
int move;
printf("Bienvenue dans cette partie de Nim ! \n");
printf("Nb lignes ?\n");
scanf("%d",nlig)
printf("Nb de colonnes ?\n")
scanf("%d",ncol)
move = Coup_joueur(nb_vois, vois);
move = Coup_Ordi_Gagnant(nb_vois, vois, nim);
printf("le pion s'est déplacé dans la case %d:(%d,%d)\n", move, vois[move-1].x, vois[move-1].y);

}
/*pas le temps de faire le contenu du main mais les fonctions sont pour la plupart ok*/
