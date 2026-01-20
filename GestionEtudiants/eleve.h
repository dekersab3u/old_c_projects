#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// définition du type étudiant
struct etudiant
{
    char nom[20];
    char dpt[5];
};

typedef struct etudiant T_Etudiant;

// définition du type ensemble d'étudiants
struct ensemble 
{
    T_Etudiant tab[150];
    int card;
};

typedef struct ensemble T_Ensemble;

// ENTÊTES DES FONCTIONS DU PROGRAMME
void DeuxAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void menu(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void AucunAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void DeptAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void TabStat(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void NewEtud(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void AbandonAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void viderBuffer();

