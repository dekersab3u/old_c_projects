#include<stdio.h>

/*On écrira tout d’abord une fonction Lire_Entier qui permet de saisir et de retourner un entier compris entre deux bornes données*/
int Lire_Entier (int mini, int maxi)
{
  int Entier;
  printf("Saisissez un nombre entier compris entre %d et %d : ",mini, maxi);
  do
  {
    scanf("%d",&Entier);
    if (!(mini < Entier && Entier <= maxi))
    {
      printf("la saisie est incorrecte, veuillez reccomencer");
    }
  }
  while(!(mini < Entier && Entier <= maxi));//tant que la saisie est mauvaise
  return Entier;
}

int main ()
{
  int variable;
  int a,b,c;
  char crt;
  int Nimporte;
  crt = 'A';
  variable = 36;
  printf ("\n Ceci doit \t etre affiche \n");
  printf("Le caractere est egal a %c.\n",crt);
  printf("L'entier est egal a %d.\n",variable);
  printf("Le caractere est egal a %c. Et l'entier est egal a %d. \n",crt,variable);
  printf("veuillez saisir un entier : ");
  scanf("%d",&a);
  printf("%d \n",a);
  printf("L'entier est egal a %d.\n",a);
  /*Exemple d'appel de fonction*/
  Nimporte = Lire_Entier(0, 5);
  b = Lire_Entier(5, 10);
  c = Lire_Entier(Nimporte, b);
  printf("%d < %d < %d\n",Nimporte,c,b);
  return 0;
}
