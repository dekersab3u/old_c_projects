#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void plus(int *a);
void echange(int *b, int *c);
int * allouer_tab(int n);
int * concat_tab(int * tab1, int n1, int tab2[], int n2);

int main()
{
    int n=5;
    int b, c;
    plus(&n);
    /*
    printf("%d \n Saisissez deux entiers : ", n);

    scanf("%d", &b);
    scanf("%d", &c);
    printf("\n b : %d\t c : %d \nEchange...", b, c);
    echange(&b, &c);
    printf("\n b : %d\t c : %d \n", b, c);
    */
    int n1, n2, j;
    int *tab1, *tab2;
    printf("entrez n1 et n2 : ");
    scanf("%d", &n1);
    scanf("%d", &n2);
    tab1 = allouer_tab(n1);
    tab2 = allouer_tab(n2);
    for(j=0; j<n1; j++)
        tab1[j] = 1+rand()%(100);

    for(j=0; j<n2; j++)
        tab2[j] = 1+rand()%(100);

    int *tab3 = concat_tab(tab1, n1, tab2, n2);

    for(j=0; j<(n1 + n2); j++)
        printf("t%d : %d \n", j+1, tab3[j]);
}

void plus (int *a)
{
    (*a) = (*a)+1;
}
//transmission paramètres : par valeur ou par copie
//ici N est copié dans a

void echange(int *b, int *c)
{
   int temp;
   temp = *b;
   *b = *c;
   *c = temp;
}

int * allouer_tab(int n)
{
    int * n1;
    n1 = (int *)malloc(n * sizeof(int));
    return n1;
}

int * concat_tab(int * tab1, int n1, int tab2[], int n2)
{
    int s, i;
    s = n1 + n2;
    int * concat = allouer_tab(s);
    for(i=0; i<n1; i++)
        concat[i] = tab1[i];
    
    for(i=n1; i<s; i++)
        concat[i] = tab2[i-n1];

    return concat;
}



/*
=========================================================
============ ALLOCATION DYNAMIQUE DE MEMOIRE ============
=========================================================

// C'est le programme qui demande de la mémoire au SE
#include...
int main()
{
    int n1, nz;
    int * tab1;
    int * tab2;
    printf("nb1 = ");
    scanf("%d", &n1);
    tab1 = malloc(n1 * sizeof(int));
    printf("nz = ");
    scanf("%d", &nz);
    tab2 = calloc(n1, sizeof(int));
    // sizeof : taille de, (int, double, frac...)
    free(tab1); // libérer de la mémoire
}


=========================================================
============ ALLOCATION STATIQUE DE MEMOIRE =============
=========================================================

int main()
{
    int tab[10]; // Le SE donne la mémoire pour stocker 10 entiers
    int n;
    scanf("%d", &n);
    int faux[n]; // IMPOSSIBLE : n inconnu au moment de l'execut°

}

*/
