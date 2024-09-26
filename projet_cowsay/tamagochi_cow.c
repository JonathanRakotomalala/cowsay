#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

 
//#include "automate.h"

#define liferocks 0
#define lifesucks 1
#define byebyelife 2
#define CLOCKS_PER_SEG 100
typedef int etat ;

unsigned int m;
unsigned int longueur=0;
char eyes[6]="oo";
char tongue[1]=" ";
char top[50]="                      ";
char corn[50]="^__^";
char bos[10]="__";
int bulle=0;

int stocks = 5;
int lunchfood;
int fitness = 5;
int life = 5;
int crop = 0;
int digestion = 0;

int duree_de_vie = 0;


char sorties[3][10];

void dire(char *mod){
    int bulle=0;
    int longueur=strlen(mod);
    printf(" ");
    for(int n=1;n<=longueur;n++){
        printf("_");
    }
    if (bulle==0){
        printf("\n< ");
    }
    else if (bulle==1){
        printf("\n( ");
    }
    for(int n=0;n<longueur;n++){
        int i=0;
        if (strcmp(mod,"\0")){
            printf("%c",mod[n]);
        }
    }

    if (bulle==0){
        printf(">\n ");
    }
    else if ( bulle==1){
        printf(")\n ");
    }
    for(int n=1;n<=longueur;n++){
        printf("-");
    }
    printf("\n");
}

int lire_entree_lunch(int stocks){
    int c;
	scanf("%d", &c) ;
	while ((c < 0) | (c>(stocks))) {
		printf("entree invalide !\n") ;
		scanf("%d", &c) ;
	}
	return c;
}


int lire_entree() {
	char c;
	scanf(" %s", &c);
	return c;
}

void update(){ printf("\033[H\033[J");}

void affiche_vache(int fitness){
    if (fitness==1|fitness==2|fitness==3|fitness==7|fitness==8|fitness==9){
        strcpy(eyes, "oo");       
    }
    if (fitness==0|fitness==10){
        strcpy(eyes,"xx");
        strcpy(tongue,"u");
    }
    if (fitness==4|fitness==5|fitness==6){
        strcpy(eyes,"##-");
    }
    printf("                %s\n\
            \\    %s\n\
             \\   (%s)\\ _%s___\n\
                 (__)\\        )\\/\\\n\
                  %s  ||----w |\n\
                     ||     ||\n",top,corn,eyes,bos,tongue);
}

etat etat_initial(){
    return liferocks;
}



int transition(etat life, int fitness){
    char transitions[3][10];
    for (int i=0;i<=2;i++){
        for (int j=0;j<=10;j++){
            transitions[i][j]=0;
            if (j==1||j==2||j==3||j==7||j==8||j==9){
                transitions[i][j] = lifesucks;
            }
            if (j==0||j==10){
                transitions[i][j] = byebyelife;
            }
            if (j==4||j==5||j==6){
                transitions[i][j] = liferocks;
            }
        }
    }
    return transitions[fitness][fitness];
}




int stock_update(int lunchfood){
    int a;
    time_t t ;
    srand((unsigned) time(&t)) ;
    crop = rand() % -3;
    a=(stocks-lunchfood)+crop;
    return a;
}

int fitness_update(int lunchfood){
    int a;
    time_t t ;
    srand((unsigned) time(&t)) ;
    digestion = rand() % -3;
    a = (fitness+lunchfood)+digestion;
    return a;
}



int simule_automate(){
	etat etat_courant, etat_suivant;
    char entree;
    char smth[18] = "Hello";
	etat_courant = etat_initial();
    //clock_t start_t, end_t, total_t;
    int a;
    int reste=0;
	while (etat_courant!=byebyelife){
        time_t begin = time(NULL);
        dire(smth);
        affiche_vache(fitness);
        time_t t ;
        printf("Stock:%d\n",stocks);
        printf("Tapez \"lunchfood\" pour le nourrir quand il le faut\n");
		scanf("%s",&entree);
        time_t now=time(0);
        if (!strcmp(&entree,"lunchfood")){
            printf("combien ?\n");
            lunchfood = lire_entree_lunch(stocks);
            printf("\ndigestion\n");
            fitness = fitness_update(lunchfood);
            stocks = stock_update(lunchfood);
            if ((stocks==0)&(!strcmp(&entree,"racheter"))){
            affiche_vache(7);
            printf("Oh!\n");
            lunchfood=0;
            fitness = fitness_update(lunchfood);
            stocks = stock_update(lunchfood)+reste;
            }
            else if (stocks>10){
            printf("\nle reste a été vendu :)");
            reste=stocks-10;
            stocks=10;
            }
        }
        else if (!strcmp(&entree,"non")|!strcmp(&entree,"Non")){
            dire("fais gaffe!");
            strcpy(eyes,"--");
            affiche_vache(2);
            sleep(3);
            lunchfood=0;
            fitness = fitness_update(lunchfood);
            stocks = stock_update(lunchfood);
        }
        //temps=clock();
        //if ((clock() % 15)==0){
            //digestion = rand() % 3;
            //crop = rand() % -3;
        //}
        else if ((now - begin)> 1){
            fitness=fitness-2;
        }
        //clock_t end = clock();      
		etat_suivant = transition(etat_courant,fitness);
        update();
        etat_courant = etat_suivant;
        duree_de_vie=duree_de_vie+1;
        if (fitness==0|fitness==10){
            affiche_vache(fitness);
            etat_courant=byebyelife;
        }
        //strcpy(smth,&sorties[etat_courant][fitness]);
	}
    time_t end = time(NULL);
    return duree_de_vie;
}


int main(){
/* Intialise le generateur de nombres aleatoires */
    time_t t ;
    srand((unsigned) time(&t)) ;
    int nombre ;
    nombre=simule_automate();
    printf("Voici ton score : %d\n",nombre);
}

