#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int cpt_ligne(nom_annuaire) /*cyprien*/
{
    int cpt=0;
    char ligne[500];

    FILE* fichier = fopen(nom_annuaire, "r");
    if (fichier==NULL)
        {
            printf("erreur");
        return -1;
        }
    while((fgets(ligne,499,fichier)) , !feof(fichier))
    {
        cpt++;
    }

    fclose(fichier);
    return cpt;
};

void modifier_mel_client(char *nom_annuaire) /*aragorn*/
{
    // sa marche sur l'écran mais pas dans le fichier

    int found=false;
    char ligne[500];
    printf("Entrer le mail que vous voulez modifier: \n");
    char mel_p[50];                                                               //variable a chercher
    scanf("%s", mel_p);

        FILE *input_file = fopen(nom_annuaire, "r");                         //creer un nouveau fichier pour editer sans pertes
        if (input_file == NULL) {
            printf("Error: unable to open file\n");
            return 1;
        }

        FILE *output_file = fopen("modifier_mel_p.txt", "w");                   // creer un copie de l'annuaire en cas de problèmes
        if (output_file == NULL) {
            printf("Error: unable to create output file\n");
            return 1;
    }

        printf("Entrez votre nouveau mail: ");
        char nv_mel_p[50];
        scanf("%s", nv_mel_p);
        int indice=1,i;
        char c,champ[10][50]={"","","","","","","","","",""};

        while((fgets(ligne,499,input_file)) , !feof(input_file))
        {
                    //while (c != ',' && c != EOF)
                if (strstr (ligne,mel_p) > 0)    //cela veut dire qu on a trouvé une correspondance pour l email, mais pas forcement au champs email
                {
                   for (i =0 ; i < strlen(ligne); i++)
                     {
                         //printf("OK");
                         c=ligne[i];
                     if ((c ==',') && (ligne[i+1]!='\n')) indice++;
                    else strncat(champ[indice],&c,1);
                     }
                     if (strcmp(champ[6],mel_p))
                        {strcpy(champ[6],nv_mel_p); // on verifie maintenant que le champ email est bien celui qu on change
                        found=true;}
                    for(i =1 ; i < indice+1; i++)
                    {printf(output_file,"%s",champ[i]);printf(output_file,"%s",",");
                    }
                    printf(output_file,"\n");

                }
                else printf(output_file,"%s",ligne);
        }


        if (found == false)                                                                               // si on n'a pas trouver le client
        {
            printf(" address mail introuvable, essayer un autre.");
        }
        printf(output_file,"%s","aragorn");
        fclose(input_file);
        fclose(output_file);
        printf("Modification applique\n");


    return 0;

}

void afficher_clients_tries_nom(nom_annuaire)/*cyprien*/
{
    int taille=cpt_ligne(nom_annuaire), i=0, j=0 ,h;
    char tmp[taille][300],tmp2[300];


    FILE* fichier = fopen(nom_annuaire, "r");
    if (fichier==NULL)
        {
            printf("erreur fichier entr�");
        return -1;
        }

    for(i; i<taille;i++)
    {
        fgets(tmp[i],299,fichier);

        if (tmp[i][0]>'Z')tmp[i][0]=tmp[i][0]+'A'-'a';

        if (i>0)
        {
            h=i;
            while((h>0) &&(strcmp(tmp[h-1],tmp[h])>0))
            {
                strcpy(tmp2,tmp[h]);
                strcpy(tmp[h],tmp[h-1]);
                strcpy(tmp[h-1],tmp2);
                h--;
            }
        }
    }

    fclose(fichier);

    FILE* sortie = fopen("resultat_trier_par_nom.txt", "w+");
    if (sortie==NULL)
        {
            printf("erreur ouverture annuaire_trie_par_nom.txt");
        return -1;
        }

    while(j<taille)
    {
        fputs( tmp[j], sortie);
        j++;
    }

    fclose(sortie);
}

void filtrer_combiner_deux_champs(char *nom_annuaire, char nom_champ1[20],char val_chaine1[100],char nom_champ2[20],char val_chaine2[100])/*cyprien*/
{
    int taille=cpt_ligne(nom_annuaire), i=0, j, h=0, l=0, n=0, o=0, a1, a2=strlen(val_chaine2),valide1,valide2;
    char  ligne_tmp[8][50], ligne[300], sousch1[a1+1], sousch2[a2+1];

    printf("Vous pouvez trier sur les champ suivants : nom, prenom, codepostal, vile, telephone, mail, profession\n");
    printf("Entrez le nom du premier champ que vous voulez trier:");
    scanf("%s",&nom_champ1);
    printf("Entrez la chaine de carataire recherchee : ");
    scanf("%s",&val_chaine1);
    printf("Entrez le nom du deuxieme champ que vous voulez trier:");
    scanf("%s",&nom_champ2);
    printf("Entrez la chaine de carataire recherchee : ");
    scanf("%s",&val_chaine2);

    a1=strlen(val_chaine1);
    a2=strlen(val_chaine2);

    FILE* fichier = fopen(nom_annuaire, "r");
    if (fichier==NULL)
        {
            printf("erreur fichier entr�");
        return -1;
        }

    FILE* sortie = fopen("resultat_filtrer_combiner_deux_champs.txt", "w+");
    if (sortie==NULL)
        {
            printf("erreur ouverture annuaire_filtre_deux_champ.txt");
        return -1;
        }

    for(i; i<taille;i++)
    {
        fgets(ligne,299,fichier);

        valide1=0;
        valide2=0;
        j=0;
        n=0;
        o=0;
        l=0;

        while(ligne[j]!='\n')
        {
            if (ligne[j]==',')
            {
                ligne_tmp[l][h]='\0';
                h=0;
                l++;
            }
            else
            {
                ligne_tmp[l][h]=ligne[j];
                h++;
            }
            j++;
            if (ligne[j]!='\0')ligne_tmp[l][h]='\0';
        }

        if (strcmp(nom_champ1,"nom")==0)
        {
            while (ligne_tmp[0][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[0][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }

                n++;
            }
        }

        if (strcmp(nom_champ1,"prenom")==0)
        {
           while (ligne_tmp[1][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[1][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }
                n++;
            }
        }

        if (strcmp(nom_champ1,"codeposatl")==0)
        {
            while (ligne_tmp[2][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[2][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }
                n++;
            }
        }

        if (strcmp(nom_champ1,"ville")==0)
        {
            while (ligne_tmp[3][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[3][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }
                n++;
            }
        }

        if (strcmp(nom_champ1,"telephone")==0)
        {
            while (ligne_tmp[4][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[4][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }
                n++;
            }
        }

        if (strcmp(nom_champ1,"mail")==0)
        {
            while (ligne_tmp[5][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[5][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }
                n++;
            }
        }

        if (strcmp(nom_champ1,"profession")==0)
        {
            while (ligne_tmp[6][n+a1-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch1[z]=ligne_tmp[6][n+z];
                }
                if (strcmp(sousch1,val_chaine1)==0)
                {
                    valide1=1;
                }
                n++;
            }
        }

        if (strcmp(nom_champ2,"nom")==0)
        {
            while (ligne_tmp[0][o+a2-1]!='\0')
            {
                for (int z=0;z<a2;z++)
                {
                    sousch2[z]=ligne_tmp[0][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }

        if (strcmp(nom_champ2,"prenom")==0)
        {
            while (ligne_tmp[1][o+a2-1]!='\0')
            {
                for (int z=0;z<a2;z++)
                {
                    sousch2[z]=ligne_tmp[1][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }

        if (strcmp(nom_champ2,"codeposatl")==0)
        {
           while (ligne_tmp[2][o+a2-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch2[z]=ligne_tmp[2][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }

        if (strcmp(nom_champ2,"ville")==0)
        {
            while (ligne_tmp[3][o+a2-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch2[z]=ligne_tmp[3][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }

        if (strcmp(nom_champ2,"telephone")==0)
        {
            while (ligne_tmp[4][o+a2-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch2[z]=ligne_tmp[4][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }

        if (strcmp(nom_champ2,"mail")==0)
        {
            while (ligne_tmp[5][o+a2-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch2[z]=ligne_tmp[5][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }

        if (strcmp(nom_champ2,"profession")==0)
        {
            while (ligne_tmp[6][o+a2-1]!='\0')
            {
                for (int z=0;z<a1;z++)
                {
                    sousch2[z]=ligne_tmp[6][o+z];
                }
                if (strcmp(sousch2,val_chaine2)==0)
                {
                    valide2=1;
                }
                o++;
            }
        }
        if(valide1 && valide2)
        {
            fprintf(sortie,"%s,%s,%s,%s,%s,%s,%s\n",ligne_tmp[0],ligne_tmp[1],ligne_tmp[2],ligne_tmp[3],ligne_tmp[4],ligne_tmp[5],ligne_tmp[6]);
        }
    }
    fclose(fichier);
    fclose(sortie);
}

int manque_data(char chaine[])/*cyprien*/
{
    int manque=0, espace=1, long_ch= strlen(chaine);

    for(int i; chaine[i]!='\0';i++)
    {
        if (chaine[i]==',')
        {

            if (espace)
            {
                manque=1;
            }

            else
            {
                if (chaine[i+1]==',')manque=1;
                else
                {
                    if (chaine[i+1]=='\0')manque=1;
                }
            }
            espace=1;
        }
        else
        {
            if (chaine[i]>'a'&&chaine[i]<'z'||chaine[i]>'A'&&chaine[i]<'Z'||chaine[i]>'0'&&chaine[i]<'9')
            {
                espace=0;
            }
        }
    }
    if (manque) return 1;

    return 0;
}

void afficher_clients_donnees_manquantes(nom_annuaire)/*cyprien*/
{
    int taille=cpt_ligne(nom_annuaire), i=0;
    char tmp2[500];

    FILE* fichier = fopen(nom_annuaire, "r");
    if (fichier==NULL)
    {
        printf("erreur ouverture");
        exit(0);
    }
    FILE* sortie = fopen(" resultat_afficher_donnees_manquantes.txt", "w+");
    if (sortie==NULL)
        {
            printf("erreur ouverture  resultat_afficher_donnees_manquantes.txt");
        return -1;
        }

    for(i; i<taille;i++)
    {
        fgets(tmp2,499,fichier);

        if (manque_data(tmp2))
        {
            fprintf(sortie,"%s",tmp2);
        }

    }
    fclose(fichier);
    fclose(sortie);
}

struct client* charger_annuaire(int *cpt_taille, char *nom_annuaire) /*Anis*/ {
    // Ouvre le fichier en lecture
    FILE* fichier_p= fopen(nom_annuaire, "r");
    if (fichier_p== NULL){
        perror("Erreur lors de l'ouverture du fichiers deihduhsaa\n");
        exit(EXIT_FAILURE);
    }

    // Alloue un tableau de structures
    struct client* tab = malloc(sizeof(struct client) * (*cpt_taille ));
    if (tab == NULL) {
        fclose(fichier_p);
        exit(EXIT_FAILURE);
    }

    char c;
    int i;

    // Lit le fichier ligne par ligne jusqu'à la fin du fichier
    while (!feof(fichier_p)) {
        // Sparez les deux valeurs de chaque ligne
        tab = realloc(tab, sizeof(struct client) * (*cpt_taille + 1));

        if (tab == NULL) {
          fclose(fichier_p);
          exit(EXIT_FAILURE);
        }

        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].nom_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }

        tab[*cpt_taille].nom_p[i] = '\0';
        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].prenom_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }

        tab[*cpt_taille].prenom_p[i] = '\0';
        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].codepostal_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }

        tab[*cpt_taille].codepostal_p[i] = '\0';
        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].ville_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }

        tab[*cpt_taille].ville_p[i] = '\0';
        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].telephone_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }

        tab[*cpt_taille].telephone_p[i] = '\0';
        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].mel_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }

        tab[*cpt_taille].mel_p[i] = '\0';
        c = fgetc(fichier_p);
        i = 0;

        while (c != ',' && c != EOF && c!='\n')
        {
            tab[*cpt_taille].profession_p[i]=c;
            c = fgetc(fichier_p);
            i++;
        }
        tab[*cpt_taille].profession_p[i] = '\0';

        (*cpt_taille)++;
    }

    // Ferme le fichier et renvoie le tableau de structures
    fclose(fichier_p);
    return tab;
}



int recherche_mail(char mel_p[256], char *nom_annuaire) /*Anis*/
{
    int cpt_taille=0;
    struct client *annuaire= charger_annuaire(&cpt_taille, nom_annuaire);
    if (annuaire==NULL)
    {
        printf("Error: unable to open filezzzz\n");
        return 1;
    }

    FILE *input_file = fopen(nom_annuaire, "r");
    if (input_file == NULL) {
        printf("Error: unable to open file\n");
        return 1;
    }
    for(int i=0; i<cpt_taille; i++)
    {
        if (strcmp(annuaire[i].mel_p, mel_p) == 0)
        {
            return 2;
        }
    }
    fclose(input_file);
    return 0;

}

void supprimer_client(char *nom_annuaire, char mel_p [256]) /*Anis*/
{
    int cpt_taille=0;
    struct client *annuaire= charger_annuaire(&cpt_taille, nom_annuaire);
    if (annuaire==NULL)
    {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(nom_annuaire, "r");
    if (input_file == NULL) {
        printf("Error: unable to open file\n");
    exit(EXIT_FAILURE);
    }

  printf("Entrer le mail du client que vous voulez supprimer: ");
  scanf("%s", mel_p);
  if(recherche_mail(mel_p, nom_annuaire)==2)
  {
    FILE *output_file = fopen("resultat_supprimer.txt", "w");

    if (output_file == NULL) {
        printf("Error: unable to create output file\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<cpt_taille; i++){

        if (strcmp(annuaire[i].mel_p, mel_p) != 0) {
            fprintf(output_file, "%s,%s,%s,%s,%s,%s,%s\n", annuaire[i].nom_p, annuaire[i].prenom_p, annuaire[i].codepostal_p, annuaire[i].ville_p, annuaire[i].telephone_p, annuaire[i].mel_p, annuaire[i].profession_p);
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("\n\tLa suppression du client avec le mail %s a ete effectuee avec succes.\n\n", mel_p);
    free(annuaire);
  }
  else
  {
      printf("\n\t\tLe client n'a pas ete trouve .\n\n");
      free(annuaire);
      fclose(input_file);
  }
}


void ajouter_client(char *nom_annuaire, char *nom_p, char *prenom_p, char *codepostal_p, char *ville_p, char *telephone_p, char *mel_p, char *profession_p) /*Anis*/ {

    int cpt_taille=0;
    struct client *annuaire= charger_annuaire(&cpt_taille, nom_annuaire);
    if (annuaire==NULL)
    {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }
    FILE *input_file = fopen(nom_annuaire, "r");
    if (input_file == NULL) {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);}
    FILE *ajouter = fopen("resultat_ajouter.txt", "a");
    if (ajouter == NULL) {
      printf("Erreur lors de l'ouverture du fichierw\n");
      return;
   }
   printf("Entrer le nom que vous voulez ajouter: \n");
   scanf("%s", nom_p);
   printf("Entrer son prenom: \n");
   scanf("%s", prenom_p);
   printf("Entrer son code postal: \n");
   scanf("%s", codepostal_p);
   printf("Entrer sa ville: \n");
   scanf("%s", ville_p);
   printf("Entrer son numero de telephone: \n");
   scanf("%s", telephone_p);
   printf("Entrer son e-mail: \n");
   scanf("%s", mel_p);
   printf("Entrer sa profession: \n");
   scanf("%s", profession_p);

    if (recherche_mail(mel_p, nom_annuaire)==2)
    {
        printf("\n\t\tLe client ayant pour mail %s existe deja\n\n", mel_p);
        return 0;
    }
     for(int i=0; i<cpt_taille; i++){

            fprintf(ajouter, "%s,%s,%s,%s,%s,%s,%s\n", annuaire[i].nom_p, annuaire[i].prenom_p, annuaire[i].codepostal_p, annuaire[i].ville_p, annuaire[i].telephone_p, annuaire[i].mel_p, annuaire[i].profession_p);
    }
   fprintf(ajouter, "%s,%s,%s,%s,%s,%s,%s", nom_p, prenom_p, codepostal_p, ville_p, telephone_p, mel_p, profession_p);
   printf("\n\tClient ajoute avec succes ! \n\n");

   fclose(input_file);
   fclose(ajouter);
}

void valider_annuaire(char *nom_annuaire) /*Anis*/
{
    int cpt_taille = 0;
    int n = 0;
    struct client *annuaire = charger_annuaire(&cpt_taille, nom_annuaire);
    if (annuaire == NULL) {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Ouvre le fichier "annuaire_valide.txt" en écriture
    FILE *output_file = fopen("annuaire_valide.txt", "w");
    if (output_file == NULL) {
        printf("Error: unable to open file\n");
       exit(EXIT_FAILURE);
    }

    // Pour chaque entrée de l'annuaire, vérifiez si elle a déjà été écrite dans le fichier
    for (int i = 0; i < cpt_taille; i++) {
        // Définissez un flag pour suivre si l'entrée a déjà été écrite dans le fichier
        int erreur = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(annuaire[i].mel_p, annuaire[j].mel_p) == 0 || strstr( annuaire[i].mel_p,"@server.fr") ==NULL ) {
                erreur = 1;
                break;
            }
        }
        if (erreur==0) {
            fprintf(output_file, "%s,%s,%s,%s,%s,%s,%s\n",annuaire[i].nom_p,annuaire[i].prenom_p,annuaire[i].codepostal_p,annuaire[i].ville_p,annuaire[i].telephone_p,annuaire[i].mel_p,annuaire[i].profession_p);
        }
    }

    // Fermez le fichier "annuaire_valide.txt"
    fclose(output_file);
}

void verifier_validate_annuaire(char *nom_annuaire) /*Anis*/
{
    int cpt_taille = 0;
    struct client *annuaire = charger_annuaire(&cpt_taille, nom_annuaire);
    if (annuaire == NULL) {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }
    int doublon=1;
    int i;
    int n=0;
    for ( i = 0; i < cpt_taille; i++) {
        if (strstr( annuaire[i].mel_p,"@server.fr") ==NULL) {
            n = 1;
            break;
        }
        for (int j = i + 1; j < cpt_taille; j++) {
            if (strcmp(annuaire[i].mel_p, annuaire[j].mel_p) == 0)
            {
                doublon=0;
                break;
            }
     }
    }
    if(doublon==0 || n==1)
    {
        char choix[5];
        printf("\t\n Il y a des doublons ou des mails non rensegnes pour certains clients present dans l'annuaire .\n");
        printf("\t Voulez-vous rendre votre annuaire valide ?(o/n): ");
        scanf("%s", &choix);
        if(choix[0]=='o' || choix=='O')
        {
            printf("\n\tL'annuaire a bien ete rendu valide !\n\n");
             valider_annuaire(nom_annuaire);
        }

        else
            printf("\n\tL'annuaire n'a donc pas ete rendu valide .\n\n");
    }
}

void modifier_autres_que_mel_client(char *nom_annuaire,char *mel_p,char *nom_champ,char *nv_valeur) /*Anis*/
{
    int cpt_taille=0;
    struct client *annuaire= charger_annuaire(&cpt_taille, nom_annuaire);
    if (annuaire==NULL)
    {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }
    FILE *input_file = fopen(nom_annuaire, "r");
    if (input_file == NULL) {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);}
  printf("\tEntrer le mail du client que vous voulez modifier: ");
  scanf("%s", mel_p);
  if(recherche_mail(mel_p, nom_annuaire)==2)
  {
    FILE *output_file = fopen("resultat_modifier_autre_que_mel_p.txt", "w");
    if (output_file == NULL) {
        printf("Error: unable to create output file\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
       }
    printf("\tClient trouve !\n");
    printf("\tEntrez le  nom du champ que vous voulez modifier(sans accens et en tout attache): ");
    scanf("%s", nom_champ);
     if(strcmp(nom_champ, "nom")!=0 && strcmp(nom_champ,"prenom")!=0 && strcmp(nom_champ,"codepostal")!=0 && strcmp(nom_champ, "ville")!=0 && strcmp(nom_champ, "telephone")!=0 && strcmp(nom_champ, "mail")!=0 && strcmp(nom_champ, "profession")!=0)
            {
                printf("\n\tDesole, mails le champ renseigne ne corespond a aucun des champs 'nom', 'prenom', 'codepostal', 'ville', 'telephone'et'profession'\n");
                exit(EXIT_FAILURE);
            }
    printf("\tEntrez son nouveau contenu: ");
    scanf("%s", nv_valeur);
    for(int i=0; i<cpt_taille; i++)
    {
        if (strcmp(annuaire[i].mel_p, mel_p)==0)
        {
            if(strcmp(nom_champ,"nom")==0)
                strcpy(annuaire[i].nom_p, nv_valeur);
            if(strcmp(nom_champ,"prenom")==0)
                strcpy(annuaire[i].prenom_p ,nv_valeur);
            if(strcmp(nom_champ,"codepostal")==0)
                strcpy(annuaire[i].codepostal_p, nv_valeur);
            if(strcmp(nom_champ,"ville")==0)
                strcpy(annuaire[i].ville_p, nv_valeur);
            if(strcmp(nom_champ,"telephone")==0)
                strcpy(annuaire[i].telephone_p, nv_valeur);
            if(strcmp(nom_champ,"profession")==0)
                strcpy(annuaire[i].profession_p, nv_valeur);
            break;
        }
    }
    for (int i = 0; i < cpt_taille; i++) {
        fprintf(output_file, "%s,%s,%s,%s,%s,%s,%s\n", annuaire[i].nom_p, annuaire[i].prenom_p, annuaire[i].codepostal_p, annuaire[i].ville_p, annuaire[i].telephone_p, annuaire[i].mel_p, annuaire[i].profession_p);
    }
    fclose(output_file);
    printf("\n\t\tModification applique avec succes !\n\n");
  }
  else
  {
    printf("\n\tDesole mais le client ayant pour mail %s n'existe pas\n", mel_p);
    free(annuaire);
  }
  fclose(input_file);
}


void filtrer_un_champ(nom_annuaire,val1,val2)   /*Aragorn*/
// afficher les enregistrement contenant la chaine de caracteres dans n importe quel champ
{

    char ligne[500],val_chain[50];

    FILE* inputfile = fopen(nom_annuaire, "r");
    if (inputfile==NULL)
        {
            printf("error file not found");
            exit(EXIT_FAILURE);
        }
    /*FILE *outputfile = fopen("annuaire_filtre.txt", "w");
    if (outputfile == NULL) {
        printf("Error: unable to open file\n");
        return -1;
    }*/
    printf("Entrer le filtre selon laquelle vous vouliez chercher en utilisant les mots cle suivant: \n");

    scanf("%s", val_chain);

    while((fgets(ligne,499,inputfile)) , !feof(inputfile))
    {
        if (strstr (ligne, val_chain) > 0) printf(ligne);// nous affichons les lignes contenant la chaine de charactres! ;-)
    }
    fclose(inputfile);
    //fclose(outputfile);
}
