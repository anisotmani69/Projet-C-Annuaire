#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
char nom_annuaire[50];
printf("\tEntrer le nom de votre fichier texte: ");
scanf("%s", &nom_annuaire);
FILE *F=fopen(nom_annuaire , "r");

if(F==NULL)
{
    printf("\nLe fichier %s n'est pas present dans votre repertoire", nom_annuaire);
    return 0;
}

verifier_validate_annuaire(nom_annuaire);


int choix;
char nom_p[50];
char prenom_p[50];
char codepostal_p[50];
char ville_p[50];
char telephone_p[50];
char mel_p[50];
char profession_p[50];
char nom_champ1[50];
char val_chaine1[50];
char nom_champ2[50];
char val_chaine2[50];
char nom_champ[50];
char nv_valeur[50];
char val1[50];
char val2[50];

do
{
    printf("\t\tVotre Menu: \n\n");
    printf("\n");
    printf("\t'1' Ajouter un client\n");
    printf("\t'2' Modifier le mail d'un client\n");
    printf("\t'3' Modifier les informations autres que le mail d'un client\n");
    printf("\t'4' Supprimer un client\n");
    printf("\t'5' Afficher les clients par tries\n");
    printf("\t'6' Afficher les données manquants d'un client\n");
    printf("\t'7' Filtrer un champs\n");
    printf("\t'8' Filtrer deux champs simultanés\n");
    printf("\tEntrer la fonction que vous voulez utliser(si vous voulez quitter, taper 9)\n");
    printf("\t\tVotre choix : ");
    scanf("%d", &choix);

    switch(choix)
    {
        case 1 : ajouter_client(nom_annuaire, nom_p, prenom_p, codepostal_p, ville_p, telephone_p, mel_p, profession_p); break;
        case 2 : modifier_mel_client(); break;
        case 3 : modifier_autres_que_mel_client(nom_annuaire,mel_p,nom_champ,nv_valeur); break;
        case 4 : supprimer_client(nom_annuaire, mel_p ); break;
        case 5 : afficher_clients_tries_nom(nom_annuaire); break;
        case 6 : afficher_clients_donnees_manquantes(nom_annuaire); break;
        case 7 : filtrer_un_champ(nom_annuaire,val1,val2); break;
        case 8 : filtrer_combiner_deux_champs(nom_annuaire, nom_champ1, val_chaine1,nom_champ2, val_chaine2); break;
    }
}
while(choix!=9);
printf("\t\n Au revoir !\n\n");

   return 0;

}
