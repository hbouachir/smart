#include <stdlib.h>
#include <stdio.h>
#include <time.h>


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

void ajoutValeur(char chemin[],val valeur){
    
   FILE *f;
   f=fopen(chemin,"a+");
   if (f!=NULL){
   
        fprintf(f,"\n%d %d %d %d %f",valeur.id,valeur.d.jour,valeur.d.mois,valeur.d.annee,valeur.v);
        fclose(f);
}
else exit(1);
};

void ajoutCapteur(char chemin[],capt capteur){
    
   FILE *f;
   f=fopen(chemin,"a+");
   if (f!=NULL){
    

     time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    capteur.d.annee=tm.tm_year+1900;
    capteur.d.mois=tm.tm_mon+1;
    capteur.d.jour=tm.tm_mday;
        capteur.nbr_anomalies=0;
        fprintf(f,"%d %d %d %d %d %s\n",capteur.id,capteur.d.jour,capteur.d.mois,capteur.d.annee,capteur.type,capteur.marque);
        fclose(f);
}
else exit(1);
};

void modifierCapteur(int id,char chemin[]){
FILE *f;
 FILE *tmp;
 int a,b,c,d1,e,m;
 char g[20];
   f=fopen(chemin,"a+");
   tmp=fopen("tmp.txt","a+");
      if (f!=NULL && tmp!=NULL){
            while (fscanf(f,"%d   %d  %d  %d  %d  %s\n",&a,&b,&c,&d1,&e,&g)!=EOF)
{
    if (a==id){ do{
          printf("Pour modifier le type tapez 1\n") ;
          printf("Pour modifier la marque type 2") ;
          scanf("%d",&m);}
            while (m!=1 && m!=2);
            if (m==1) {printf("donner le type du capteur");
                        scanf("%d",&e);}
                else {printf("donner la marque du capteur");
                        scanf("%s",&g);}
                


                fprintf(tmp,"%d   %d  %d  %d  %d  %s\n",a,b,c,d1,e,g);break; }


};
remove(chemin);
rename("tmp.txt",chemin);
fclose(f);
}
else exit(1);



};



void supprimerCapteur(int id,char chemin[]){
 FILE *f;
 FILE *tmp;
 int a,b,c,d1,e;
 char g[20];
   f=fopen(chemin,"a+");
   tmp=fopen("tmp.txt","a+");
      if (f!=NULL && tmp!=NULL){
            while (fscanf(f,"%d   %d  %d  %d  %d  %s\n",&a,&b,&c,&d1,&e,&g)!=EOF)
{
    if (a!=id)fprintf(tmp,"%d   %d  %d  %d  %d  %s\n",a,b,c,d1,e,g);
};
remove(chemin);
rename("tmp.txt",chemin);
fclose(f);
}
else exit(1);
};

void chercherCapteur(int id ,char chemin[]){

FILE *f;
 FILE *tmp;
 int a,b,c,d1,e,m,x;
 char g[30];
x=0;
   f=fopen(chemin,"r");

      if (f!=NULL ){
            while (fscanf(f,"%d   %d  %d  %d  %d  %s\n",&a,&b,&c,&d1,&e,&g)!=EOF){
                if (a==id){ printf("%d   %d  %d  %d  %d  %s",a,b,c,d1,e,g);
				x=1;}

                };

        if (x==0) printf("élément introuvable");

fclose(f);
}
else exit(1);



};




void affichageCapteur(char chemin[]){

FILE *f;

 int a,b,c,d1,e,m;
 char g[30];
   f=fopen(chemin,"r+");

      if (f!=NULL ){
            while (fscanf(f,"%d   %d  %d  %d  %d  %s\n",&a,&b,&c,&d1,&e,g)!=EOF){
                 printf("%d   %d  %d  %d  %d  %s\n",a,b,c,d1,e,g);}



fclose(f);
}
else exit(1);



};

void defectueux(char chemin[]){
FILE *f;

 int a,b,c,d1,i,max;
 float e;
 int tab[100]={0};

   f=fopen(chemin,"r");
for(i=0;i<100;i++){tab[i]=0;};
      if (f!=NULL ){
            while (fscanf(f,"%d   %d  %d  %d  %f\n",&a,&b,&c,&d1,&e)!=EOF){
                 if (e>45) tab[a]+=1;}
    max=tab[0];

   for (i=0;i<100;i++){
    if (tab[i]>max) {max=tab[i];
                    }

   };


for (i=0;i<100;i++)if (tab[i]==max) printf("le capteur avec l identifiant %d est le plus defaillant\n",i);



fclose(f);
}
else exit(1);



};
