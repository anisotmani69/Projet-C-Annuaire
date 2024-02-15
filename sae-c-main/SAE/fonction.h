#ifndef _FONCTION_H_
#define _FONCTION_H_

struct client
{
    char nom_p[50];
    char prenom_p[50];
    char codepostal_p[10];
    char ville_p[50];
    char telephone_p[20];
    char mel_p[50];
    char profession_p[50];
};

struct client* charger_annuaire(cpt_taille, nom_annuaire);

int recherche_mail(mel_p, nom_annuaire);



void ajouter_client(nom_annuaire, nom_p, prenom_p, codepostal_p, ville_p, telephone_p, mel_p, profession_p);

/**< \file fonction.h */
/**
* \fn void ajouter_client(nom_annuaire, nom_p, prenom_p, code_postal_p, ville_p, telephone_p, mel_p, profession_p);
* \brief ajoute un  client dans l'annuaire
* \param nom_annuaire nom de l'annuaire modifier
* \param nom_p nom de la personne ajouter
* \param prenom_p prenom de la personne ajouter
* \param code_postal_p code postal de la personne ajouter
* \param ville_p ville de la personne ajouter
* \param telephone_p numero de téléphone de la personne ajouter
* \param mel_p mail de la personne ajouter
* \param profession_p profession de la personne ajouter
* \return
*/

void modifier_mel_p();

/**
* \fn void modifier_mel_p(nom_annuaire, mel_p, nv_mel_p);
* \brief modifie le mail d'un client dans l'annuaire
* \param nom_annuaire nom de l'annuaire modifier
* \param mel_p ancien mail de la personne à qui on change le mail
* \param nv_mel_p nouvau mail de la personne
* \return
*/

void modifier_autres_que_mel_client(nom_annuaire, mel_p, nom_champ, nv_valeur);
/**
* \fn void modifier_autres_que_mel_client(nom_annuaire, mel_p, nom_champ, nv_valeur);
* \brief modifie un autre champ que le mail d'une personne
* \param nom_annuaire nom de l'annuaire modifier
* \param mel_p mail de la personne à qui on change une information
* \param nom_champ nom du champ modifier
* \param nv_valeur nouvelle valeur du champ
* \return
*/

void afficher_clients_tries_nom(nom_annuaire);

/**
* \fn void trier_clients_par_nom(nom_annuaire);
* \brief trie les client dans l'ordre croissant
* \param nom_annuaire nom de l'annuaire trier
* \return un fichier avec les client ranger dans l'ordre croissant.
*/

void afficher_clients_donnes_manquantes(nom_annuaire);

/**
* \fn void filtrer_clients_donnes_manquantes(nom_annuaire);
* \brief affiche et filtre les client à qui il manque au moins une information
* \param nom_annuaire nom de l'annuaire sur lequel on applique  le filtre
* \return affiche l'annuaire filtré
*/

void filtrer_un_champ(nom_annuaire,val1,val2);

/**
* \fn  void filtrer_un_champ( nom_annuaire, nom_champ, val_chaine);
* \brief affiche et filtre les client celon le champ choisi
* \param nom_annuaire nom de l'annuaire sur lequel on applique  le filtre
* \param nom_champ nom du champ qu'on filtre
* \param val_chaine valeur rechercher dans le filtre
* \return affiche l'annuaire filtré
*/

void filtrer_combiner_deux_champs(nom_annuaire, nom_champ1,val_chaine1, nom_champ2, val_chaine);

/**
* \fn  void filtrer_combiner_deux_champ(nom_annuaire, nom_champ1,val_chaine1, nom_champ2, val_chaine);
* \brief affiche et filtre les client celon deux champs choisient
* \param nom_annuaire nom de l'annuaire sur lequel on applique  le filtre
* \param nom_champ1 nom du premier champ qu'on filtre
* \param val_chaine1 valeur rechercher dans le premier filtre
* \param nom_champ2 nom du second champ qu'on filtre
* \param val_chaine2 valeur rechercher dans le second filtre
* \return affiche l'annuaire filtré
*/

void affiche_client(mon_annuaire); /* Aragorn n°1 ( pour rendre plus facile ↓ ) */

/**
* \fn  void affiche_client(mon_annuaire);
* \brief affiche l'annuaire
* \param nom_annuaire nom de l'annuaire affiché
* \return affiche l'annuaire
*/


int cpt_ligne(nom_annuaire);

int manque_data(chaine);

void supprimer_client(nom_annuaire, mel_p);

void remplir_annuaire(cpt_taille);

void valider_annuaire();

void verifier_validate_annuaire();

void modifier_autres_que_mel_client(nom,prenom,mel, code_postal, ville, telephone, profession);

#endif
