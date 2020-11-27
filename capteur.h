#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED


#ifndef CAPTEURS_H_INCLUDED
#define CAPTEURS_H_INCLUDED

typedef struct Date {

int jour;

int mois;

int annee;

}date;

typedef struct valeur
{
int id;
date d;
float v;
}val;


typedef struct capteur
{   int id;
    int nbr_anomalies;
    char marque[10];
    int type;
    date d;
}capt;

void ajoutValeur(char chemin[],val valeur);
void ajoutCapteur(char chemin[],capt capteur);
void modifierCapteur(int id,char chemin[]);
void supprimerCapteur(int id,char chemin[]);
void chercherCapteur(int id ,char chemin[]);
void affichageCapteur(char chemin[]);

void defectueux(char chemin[]);





#endif // CAPTEURS_H_INCLUDED


#endif // CAPTEUR_H_INCLUDED
