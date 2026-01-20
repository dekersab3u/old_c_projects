#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"eleve.h"

void menu(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void DeuxAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void AucunAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void DeptAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void TabStat(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void NewEtud(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void AbandonAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique);
void viderBuffer();

/*===================================================================
---------------------- MENU DE L'APPLICATION ------------------------
===================================================================*/
void menu(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    int choix;
    printf("\n\t=========================================\n\t========== GESTION D'ETUDIANTS ==========\n\t=========================================\n\nProgramme de gestion des étudiants développé dans le cadre de la SAÉ 1.02\npar Titouan DUCLAUX et Thomas de KERSABIEC en 1re année de BUT Informatique \n");

    printf("\n \t1 : Afficher la liste des étudiants pratiquant les deux activités \n\t\t(sport et musique)\n\n \t2 : Afficher la liste des étudiants qui ne pratiquent aucune activité\n\n\t3 : Afficher la liste des étudiants d'un département donné \n\t\tpratiquant une activité donnée\n\n\t4 : Afficher/Editer un tableau statistique croisant département \n\t\tet activité pratiquée par l'étudiant\n\n\t5 : Inscrire un étudiant existant à une activité\n\n\t6 : Désinscrire un étudiant d'une activité donnée\n\nSaisissez le chiffre correspondant à la fonctionnalité \nque vous souhaitez utiliser : ");
    
    scanf("%d", &choix);

    // choisis la fonctionnalité
    
    if (choix == 1)
        DeuxAct(iut, sport, musique);
    else if (choix == 2)
        AucunAct(iut, sport, musique);
    else if (choix == 3)
        DeptAct(iut, sport, musique);
    else if (choix == 4)
        TabStat(iut, sport, musique);
    else if (choix == 5)
        NewEtud(iut, sport, musique);
    else if (choix == 6)
        AbandonAct(iut, sport, musique);
    else
        printf("Mauvaise saisie, veuillez recommencer");
}

//fonction qui vide le buffer
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/*===================================================================
------- ENSEMBLE DES ETUDIANTS PRATIQUANT LES DEUX ACTIVITES --------
===================================================================*/
void DeuxAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    int i, j;
    char rm;
    printf("\n\tListe des étudiants pratiquant les deux activités : \n\n");
    for(i=0; i<sport.card; i++)
    {
        for(j=0; j<musique.card; j++)
        {
            if(strcmp(sport.tab[i].nom, musique.tab[j].nom) == 0)
            {
                printf("%s  %s \n", musique.tab[j].nom, musique.tab[j].dpt);
            }
        }
    }
    viderBuffer();
    printf("\nAppuyez sur ENTREE pour retourner au menu");
    scanf("%c", &rm);
    if (rm == '\n')
        menu(iut, sport, musique);
    else
      {
        system("clear");
        printf("Le programme s'est arrêté en raison d'une erreur");
      }
}

/*===================================================================
------- ENSEMBLE DES ETUDIANTS NE PRATIQUANT AUCUNE ACTIVITE --------
===================================================================*/
void AucunAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    int i, j, k, act;
    char rm;
    printf("\n\tListe des étudiants ne pratiquant aucune activité : \n\n");
    for(i=0; i<iut.card; i++)
    {
        act=0;
        for(j=0; j<sport.card; j++)
        {
            if(strcmp(iut.tab[i].nom, musique.tab[j].nom) == 0)
                act=1;
            if(strcmp(iut.tab[i].nom, sport.tab[j].nom) == 0)
                act=1;  
        }
        if (act == 0)
            printf("%s %s\n", iut.tab[i].nom, iut.tab[i].dpt);
    }
    viderBuffer();
    printf("\nAppuyez sur ENTREE pour retourner au menu");
    scanf("%c", &rm);
    if (rm == '\n')
        menu(iut, sport, musique);
    else
      {
        system("clear");
        printf("Le programme s'est arrêté en raison d'une erreur");
      }
}

/*===================================================================
--- ENSEMBLE DES ETUDIANTS D'UN DPT DONNÉ PRATIQUANT 1 ACT DONNÉE ---
===================================================================*/
void DeptAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    int cdept, coact, i;
    char rm;
    printf("\nSaisir le numéro correspondant au département demandé : \n1. GMP\n2. STID\n3. GEA\n4. INFO\n5. TC\n\t : ");
    scanf("%d", &cdept);
    printf("\nSaisir le numéro correspondant à l'activité demandée : \n1. Musique\n2. Sport\n\t : ");
    scanf("%d", &coact);
    printf("\n");
    if (coact == 1)
    {
        if (cdept == 1)
        {
            for(i=0; i<musique.card; i++)
            {
                if (strcmp(musique.tab[i].dpt, "GMP") == 0)
                    printf("%s\n", musique.tab[i].nom);
            }
        }
        else if (cdept == 2)
        {
            for(i=0; i<musique.card; i++)
            {
                if (strcmp(musique.tab[i].dpt, "STID") == 0)
                    printf("%s\n", musique.tab[i].nom);
            }
        }
        else if (cdept == 3)
        {
            for(i=0; i<musique.card; i++)
            {
                if (strcmp(musique.tab[i].dpt, "GEA") == 0)
                    printf("%s\n", musique.tab[i].nom);
            }
        }
        else if (cdept == 4)
        {
            for(i=0; i<musique.card; i++)
            {
                if (strcmp(musique.tab[i].dpt, "INFO") == 0)
                    printf("%s\n", musique.tab[i].nom);
            }
        }
        else if (cdept == 5)
        {
            for(i=0; i<musique.card; i++)
            {
                if (strcmp(musique.tab[i].dpt, "TC") == 0)
                    printf("%s\n", musique.tab[i].nom);
            }
        }
    }
    else if (coact == 2)
    {
        if (cdept == 1)
        {
            for(i=0; i<sport.card; i++)
            {
                if (strcmp(sport.tab[i].dpt, "GMP") == 0)
                    printf("%s\n", sport.tab[i].nom);
            }
        }
        else if (cdept == 2)
        {
            for(i=0; i<sport.card; i++)
            {
                if (strcmp(sport.tab[i].dpt, "STID") == 0)
                    printf("%s\n", sport.tab[i].nom);
            }
        }
        else if (cdept == 3)
        {
            for(i=0; i<sport.card; i++)
            {
                if (strcmp(sport.tab[i].dpt, "GEA") == 0)
                    printf("%s\n", sport.tab[i].nom);
            }
        }
        else if (cdept == 4)
        {
            for(i=0; i<sport.card; i++)
            {
                if (strcmp(sport.tab[i].dpt, "INFO") == 0)
                    printf("%s\n", sport.tab[i].nom);
            }
        }
        else if (cdept == 5)
        {
            for(i=0; i<sport.card; i++)
            {
                if (strcmp(sport.tab[i].dpt, "TC") == 0)
                    printf("%s\n", sport.tab[i].nom);
            }
        }
    }
    viderBuffer();
    printf("\nAppuyez sur ENTREE pour retourner au menu");
    scanf("%c", &rm);
    if (rm == '\n')
        menu(iut, sport, musique);
    else
      {
        system("clear");
        printf("Le programme s'est arrêté en raison d'une erreur");
      }
}

/*===================================================================
---------- EDITION TABLEAU STATISTIQUE DEPARTEMENT/ACTIVITE ---------
===================================================================*/
void TabStat(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    //Calcul du nombre d'étudiants total par département
    int ngmp=0, nstid=0, ngea=0, ninfo=0, ntc=0, i;
    for(i=0; i<iut.card; i++)
    {
        if (strcmp(iut.tab[i].dpt, "GMP") == 0)
            ngmp=ngmp+1;
        if (strcmp(iut.tab[i].dpt, "STID") == 0)
            nstid=nstid+1;
        if (strcmp(iut.tab[i].dpt, "GEA") == 0)
            ngea=ngea+1;
        if (strcmp(iut.tab[i].dpt, "INFO") == 0)
            ninfo=ninfo+1;
        if (strcmp(iut.tab[i].dpt, "TC") == 0)
            ntc=ntc+1;
    }

    int j;

    //calcul pour la musique par département
    float mgmp=0, mstid=0, mgea=0, minfo=0, mtc=0;
    float pmgmp, pmstid, pmgea, pminfo, pmtc;
    for(j=0; j<musique.card; j++)
    {
        if (strcmp(musique.tab[j].dpt, "GMP") == 0)
            mgmp=mgmp+1;
        if (strcmp(musique.tab[j].dpt, "STID") == 0)
            mstid=mstid+1;
        if (strcmp(musique.tab[j].dpt, "GEA") == 0)
            mgea=mgea+1;
        if (strcmp(musique.tab[j].dpt, "INFO") == 0)
            minfo=minfo+1;
        if (strcmp(musique.tab[j].dpt, "TC") == 0)
            mtc=mtc+1;
    }
    
    // (pourcentage) PARTIE DES PERSONNES QUI FONT DE LA MUSIQUE
    
    pmgmp = ((mgmp/ngmp)*100);
    pmstid = ((mstid/nstid)*100);
    pmgea = ((mgea/ngea)*100);
    pminfo = ((minfo/ninfo)*100);
    pmtc = ((mtc/ntc)*100);


    //Calcul pour le sport
    int o;
    float sgmp=0, sstid=0, sgea=0, sinfo=0, stc=0;
    float psgmp, psstid, psgea, psinfo, pstc;
        for(o=0; o<sport.card; o++)
    {
        if (strcmp(sport.tab[o].dpt, "GMP") == 0)
            sgmp=sgmp+1;
        if (strcmp(sport.tab[o].dpt, "STID") == 0)
            sstid=sstid+1;
        if (strcmp(sport.tab[o].dpt, "GEA") == 0)
            sgea=sgea+1;
        if (strcmp(sport.tab[o].dpt, "INFO") == 0)
            sinfo=sinfo+1;
        if (strcmp(sport.tab[o].dpt, "TC") == 0)
            stc=stc+1;
    }

    // Calcul du nombre d'étud pratiquant les 2 act en mm temps par dépt.
    
    float agmp=0, astid=0, agea=0, ainfo=0, atc=0;
    for(i=0; i<sport.card; i++)
    {
        for(j=0; j<musique.card; j++)
        {
            if(strcmp(sport.tab[i].nom, musique.tab[j].nom) == 0)
            {
                if(strcmp(musique.tab[j].dpt, "GMP") == 0)
                    agmp = agmp +1;
                else if(strcmp(musique.tab[j].dpt, "STID") == 0)
                    astid = astid +1;
                else if(strcmp(musique.tab[j].dpt, "GEA") == 0)
                    agea = agea +1;
                else if(strcmp(musique.tab[j].dpt, "INFO") == 0)
                    ainfo = ainfo +1;
                else if(strcmp(musique.tab[j].dpt, "TC") == 0)
                    atc = atc +1;
            }
        }
    }

    // PARTIE DES PERSONNES QUI FONT DU SPORT

    psgmp = (((sgmp-agmp)/ngmp)*100);
    psstid = (((sstid-astid)/nstid)*100);
    psgea = (((sgea-agea)/ngea)*100);
    psinfo = (((sinfo-ainfo)/ninfo)*100);
    pstc = (((stc-atc)/ntc)*100);

    float pcgmp, pcstid, pcgea, pcinfo, pctc;

    // PARTIE DES PERSONNES QUI FONT LES 2 

    pcgmp = (agmp/ngmp)*100;
    pcstid = (astid/nstid)*100;
    pcgea = (agea/ngea)*100;
    pcinfo = (ainfo/ninfo)*100;
    pctc = (atc/ntc)*100;

    float pagmp=100, pastid=100, pagea=100, painfo=100, patc=100;

    // PARTIE DES PERSONNES QUI NE FONT RIEN

    pagmp = pagmp - pmgmp - psgmp;
    pastid = pastid - pmstid - psstid;
    pagea = pagea - pmgea - psgea;
    painfo = painfo - pminfo - psinfo;
    patc = patc - pmtc - pstc;

    // AFFICHAGE DU TABLEAU

    printf("\n\t\t|| GMP\t\t|| STID\t\t|| GEA\t\t|| INFO\t\t|| TC\t\n---------------------------------------------------------------------\nmusique\t|| %.2f %% \t|| %.2f %%\t|| %.2f %%\t|| %.2f %%\t|| %.2f %%\t\n----------------------------------------------------------------------\nsport\t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \n----------------------------------------------------------------------\ncombo\t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \n----------------------------------------------------------------------\naucun\t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \t|| %.2f %% \t|| %.2f %% ", pmgmp, pmstid, pmgea, pminfo, pmtc, psgmp, psstid, psgea, psinfo, pstc, pcgmp, pcstid, pcgea, pcinfo, pctc, pagmp, pastid, pagea, painfo, patc);

    char rm;
    viderBuffer();
    printf("\nAppuyez sur ENTREE pour retourner au menu");
    scanf("%c", &rm);
    if (rm == '\n')
        menu(iut, sport, musique);
    else
    {
        system("clear");
        printf("Le programme s'est arrêté en raison d'une erreur");
    }
    
}

/*===================================================================
---------------- INSCRIPTION ETUDIANT A UNE ACTIVITE ----------------
===================================================================*/
void NewEtud(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    int i, num=0, numetud[40], ask=0, aska, verif=0, verifm=0;
    char PremLet;
    printf("\nSaisissez la première lettre (en majuscule) du nom de l'étudiant que vous souhaitez inscrire à une activité : ");
    viderBuffer();
    scanf("%c", &PremLet);
    for(i=0; i<iut.card; i++)
    {
        if(iut.tab[i].nom[0] == PremLet)
        {
            printf("\n\t%d. %s %s", num, iut.tab[i].nom, iut.tab[i].dpt);
            numetud[num] = i;
            num= num+1;
        } 
    }
    printf("\n\nSaisissez ensuite le numéro correspondant à l'étudiant que vous souhaitez inscrire : ");
    scanf("%d", &ask);
    
    printf("\nSaisissez ensuite le numéro correspondant à l'activité à laquelle vous souhaitez inscrire l'étudiant %s\n\t1. Sport\n\t2. Musique\n: ", iut.tab[numetud[ask]].nom);
    
    scanf("%d", &aska);
    if (aska == 1)
    {
        //FOR servant à vérifier si l'étudiant demandé n'est pas déjà inscrit
        for(i=0; i<sport.card; i++)
        {
            if(strcmp(iut.tab[numetud[ask]].nom, sport.tab[i].nom) == 0)
            {
                verif =1;
            }
        }

        if(verif == 0)
        {
            FILE *IS;
            IS = fopen("SPORT.txt", "a");
            fprintf(IS, "\n%s %s", iut.tab[numetud[ask]].nom, iut.tab[numetud[ask]].dpt);
            system("clear");
            printf("L'élève a bien été ajouté\n");
            fclose(IS);
        }
        else if(verif == 1)
        {
            char rm;
            system("clear");
            printf("ERREUR : L'étudiant est déjà inscrit à cette activité. Appuyez sur ENTREE pour retourner au menu");
            viderBuffer();
            scanf("%c", &rm);
            if (rm == '\n') menu(iut, sport, musique);
            else menu(iut, sport, musique);
        }
    }
    else if (aska == 2)
    {
        for(i=0; i<musique.card; i++)
        {
            if(strcmp(iut.tab[numetud[ask]].nom, musique.tab[i].nom) == 0) verifm =1; 
        }

        if(verifm == 0)
        {
            FILE *IM;
            IM = fopen("MUSIQUE.txt", "a");
            fprintf(IM, "\n%s %s", iut.tab[numetud[ask]].nom, iut.tab[numetud[ask]].dpt);
            system("clear");
            printf("\nL'élève a bien été ajouté");
            fclose(IM);
        }
        else if(verifm == 1)
        {
            char rm;
            system("clear");
            printf("ERREUR : L'étudiant est déjà inscrit à cette activité. Appuyez sur ENTREE pour retourner au menu");
            viderBuffer();
            scanf("%c", &rm);
            if (rm == '\n') menu(iut, sport, musique);
            else menu(iut, sport, musique);
        }
    }
    // on reremplit correctement les tableaux avant de réouvrir le menu de l'application
    FILE * S, * M, * S2, * M2; 
    S= fopen("SPORT.txt", "r");
    S2= fopen("SPORT.txt", "r");
    int js=0, ck;
    while((ck=fgetc(S2)) != EOF)
        {
	        if(ck=='\n')
		        js++;
        }

    for(i=0; i<150; i++)
    {
        fscanf(S, "%s %s\n", sport.tab[i].nom, sport.tab[i].dpt);
    }
    sport.card = js+1;
   
    M= fopen("MUSIQUE.txt", "r");
    M2= fopen("MUSIQUE.txt", "r");
    int jm=0;
    while((ck=fgetc(M2)) != EOF)
        {
	        if(ck=='\n')
		        jm++;
        }
    for(i=0; i<150; i++)
    {
        fscanf(M, "%s %s\n", musique.tab[i].nom, musique.tab[i].dpt);
    }
    musique.card = jm+1;

    char rm;
    printf("Appuyez sur ENTREE pour retourner au menu");
    viderBuffer();
    scanf("%c", &rm);
    if (rm == '\n') menu(iut, sport, musique);
    else menu(iut, sport, musique);
}

/*===================================================================
------------------ ABANDON ACTIVITE PAR UN ETUDIANT -----------------
===================================================================*/
void AbandonAct(T_Ensemble iut, T_Ensemble sport, T_Ensemble musique)
{
    int i, rep, m, s, o=0;
    FILE* M, * S; 
    
    printf("\nVoulez vous enlever un élève de la liste musique (1) ou sport (2) ? Tapez le numéro correspondant.");
    scanf("%d", &rep);

    // CHOIX DE L'ELEVE A DESINSCRIRE DE LA LISTE MUSIQUE

    if (rep == 1)
    {
        for (i=0; i<musique.card; i++)
        {
            printf("\n\t%d. %s %s", i, musique.tab[i].nom, musique.tab[i].dpt);
        }
        printf("\n\nSaisissez le numéro attribué à l'élève que vous souhaitez supprimer : ");
        scanf("%d", &m);

        M = fopen("MUSIQUE.txt", "w");
        for(i=0; i<musique.card; i++)
        {
            if(i!=m && i != musique.card-1) fprintf(M, "%s %s\n", musique.tab[i].nom, musique.tab[i].dpt);
            else if(i!=m) fprintf(M, "%s %s", musique.tab[i].nom, musique.tab[i].dpt);
        }
        fclose(M);
        printf("\nL'élève a bien été supprimé");
    }
    
    // CHOIX DE L'ELEVE A DESINSCRIRE DE LA LISTE SPORT

    else if (rep == 2)
    {
        for (i=0; i<sport.card; i++)
        {
            printf("\n\t%d. %s %s", i, sport.tab[i].nom, sport.tab[i].dpt);
        }
        printf("\n\nSaisissez le numéro attribué à l'élève que vous souhaitez supprimer : ");
        scanf("%d", &s);

        S = fopen("SPORT.txt", "w");
        for(i=0; i<sport.card; i++)
        {
            if(i!=s && i != sport.card-1) fprintf(S, "%s %s\n", sport.tab[i].nom, sport.tab[i].dpt);
            else if(i!=s) fprintf(S, "%s %s", sport.tab[i].nom, sport.tab[i].dpt);
        }
        fclose(S);
        printf("\nL'élève a bien été supprimé");
    }
    else 
    {
        char rm;
        system("clear");
        printf("\nErreur de saisie, retour au menu \n");
        viderBuffer();
        printf("\nAppuyez sur ENTREE pour retourner au menu");
        scanf("%c", &rm);
        if (rm == '\n')
            menu(iut, sport, musique);
        else
            menu(iut, sport, musique);
    }

    // on reremplit correctement les tableaux avant de réouvrir le menu de l'application
    FILE * S2, * M2; 
    S= fopen("SPORT.txt", "r");
    S2= fopen("SPORT.txt", "r");
    int js=0, ck;
    while((ck=fgetc(S2)) != EOF)
        {
	        if(ck=='\n')
		        js++;
        }

    for(i=0; i<150; i++)
    {
        fscanf(S, "%s %s\n", sport.tab[i].nom, sport.tab[i].dpt);
    }
    sport.card = js+1;
   
    M= fopen("MUSIQUE.txt", "r");
    M2= fopen("MUSIQUE.txt", "r");
    int jm=0;
    while((ck=fgetc(M2)) != EOF)
        {
	        if(ck=='\n')
		        jm++;
        }
    for(i=0; i<150; i++)
    {
        fscanf(M, "%s %s\n", musique.tab[i].nom, musique.tab[i].dpt);
    }
    musique.card = jm+1;

    char rm;
    system("clear");
    printf("Appuyez sur ENTREE pour retourner au menu");
    viderBuffer();
    scanf("%c", &rm);
    if (rm == '\n') menu(iut, sport, musique);
    else menu(iut, sport, musique);
    
}

/*===================================================================
----------------------------- BLOC MAIN -----------------------------
===================================================================*/
int main() 
{
    int i;
    FILE* I, * I2;
    FILE* M, * M2;
    FILE* S, * S2;
    
    //remplissage liste de tous les étudiants
    I= fopen("IUT.txt", "r");
    I2= fopen("IUT.txt", "r");
    T_Ensemble iut;
    int ji=0, ck;
    while((ck=fgetc(I2)) != EOF)
        {
	        if(ck=='\n')
		        ji++;
        } 
    
    for(i=0; i<150; i++)
    {
        fscanf(I, "%s %s\n", iut.tab[i].nom, iut.tab[i].dpt);
    }
    iut.card = ji+1;
    
    //remplissage liste étudiants sport
    S= fopen("SPORT.txt", "r");
    S2= fopen("SPORT.txt", "r");
    T_Ensemble sport;
    int js=0;
    
    //while qui compte les lignes du fichier
    while((ck=fgetc(S2)) != EOF)
        {
	        if(ck=='\n')
		        js++;
        }

    for(i=0; i<150; i++)
    {
        fscanf(S, "%s %s\n", sport.tab[i].nom, sport.tab[i].dpt);
    }
    
    sport.card = js+1;
   
    //remplissage liste étudiants musique
    M= fopen("MUSIQUE.txt", "r");
    M2= fopen("MUSIQUE.txt", "r");
    T_Ensemble musique;
    int jm=0;
    while((ck=fgetc(M2)) != EOF)
        {
	        if(ck=='\n')
		        jm++;
        }
    for(i=0; i<150; i++)
    {
        fscanf(M, "%s %s\n", musique.tab[i].nom, musique.tab[i].dpt);
    }

    musique.card = jm+1;

    //Appel du menu de l'application
    menu(iut, sport, musique); 
}

/* https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16421-lire-et-ecrire-dans-des-fichiers

https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16993-la-saisie-de-texte-securisee
*/
