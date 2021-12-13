#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct 
{
    int j;
    int m;
    int a;
}datek;

typedef struct utilisateur
{
    int id;
    int role;
    char prenom[50];
    char nom[50];
    char email[50];
    int sexe;
    datek d ;
    int nv;

}utilisateur;

typedef struct alarme {

        int type;         // 0 pour mouvement, 1 pour fumée
        char etage[5];
        datek d;
        int h;           //heure
        int m;           //minute

}alarme;

void ajouter_utilisateur(utilisateur u, char *fname);
void supprimer_utilisateur(utilisateur u, char *fname);
void modifier_utilisateur(utilisateur u, char *fname);
void afficher_utilisateur(GtkWidget *liste, char *fname);
utilisateur chercher_utilisateur(int id, char *fname);
void afficher_alarme(GtkWidget *liste, char *fname);

