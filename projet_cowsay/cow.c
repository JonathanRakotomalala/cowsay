#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

unsigned int m;
unsigned int longueur=0;
char eyes[6]="oo";
char tongue[1]=" ";
char top[50]="                      ";
char corn[50]="^__^";
char bos[10]="__";
int bulle=0;
int animate=0;

void update(){ printf("\033[H\033[J");}

void gotoxy(x,y){
    printf("\033[%d;%dH",x,y);
}

void affiche_vache(void){
    printf("                %s\n\
            \\    %s\n\
             \\   (%s)\\ _%s___\n\
                 (__)\\        )\\/\\\n\
                  %s  ||----w |\n\
                     ||     ||\n",top,corn,eyes,bos,tongue);
}



// bulle
void dire(int argc, char *mod[]){
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
    for(int n=1;n<argc;n++){
        int i=0;
        if (!strcmp(mod[n],"-e")|!strcmp(mod[n],"--eyes")){
            i=1;
            n++;
        }
        else if (!strcmp(mod[n],"-t")|!strcmp(mod[n], "--tired")){
            i=1;
        }
        else if (!strcmp(mod[n],"-z")|!strcmp(mod[n],"--zebu")){
            i=1;
        }
        else if (!strcmp(mod[n],"-g")|!strcmp(mod[n],"--greedy")){
            i=1;
        }
        else if (!strcmp(mod[n],"-b")|!strcmp(mod[n],"--borg")){
            i=1;
        }
        else if (!strcmp(mod[n],"-y")|!strcmp(mod[n],"--young")){
            i=1;
        }
        else if (!strcmp(mod[n],"-s")|!strcmp(mod[n],"--stone")){
            i=1;
        }
        else if (!strcmp(mod[n],"-d")|!strcmp(mod[n],"--dead")){
            i=1;
        }
        else if (!strcmp(mod[n],"-p")|!strcmp(mod[n],"--paranoia")){
            i=1;
        }
        else if (!strcmp(mod[n],"-w")|!strcmp(mod[n],"--what")){
            i=1;
        }
        else if (!strcmp(mod[n], "-a")|!strcmp(mod[n], "--animate")){
            i=1;
        }
        else if (i==0){
            printf("%s ",mod[n]);
        }
    }

    if (bulle==0){
        printf(">\n ");
    }
    else if ( bulle==1){
        printf(")\n ");
    }
    for(int n=1;n<longueur;n++){
        printf("-");
    }
    printf("\n");
}


int main(int argc, char *mod[]){
    // modifications sur la vache
    for (int n=1;n<argc;n++){
        if (!strcmp(mod[n], "-e")|!strcmp(mod[n],"--eyes")){
            m=(n+1);
            if (strlen(mod[m])>=1){
                    strcpy(eyes, mod[m]);
                
            }
            else{
                printf("erreur");
            }
        }
        else if ( !strcmp(mod[n], "-T") |!strcmp(mod[n], "--tongue")){
            m=(n+1);
            if (strlen(mod[m])==1){
                strcpy(tongue, mod[m]);
            }
        }
        else if ( !strcmp(mod[n], "-t") |!strcmp(mod[n], "--tired")){
            strcpy(eyes, "--");
        }
        else if ( !strcmp(mod[n], "-g") |!strcmp(mod[n], "--greedy")){
            strcpy(eyes, "$$");
        }
        else if ( !strcmp(mod[n], "-p") |!strcmp(mod[n], "--paranoia")){
            strcpy(eyes, "@@");
        }
        else if ( !strcmp(mod[n], "-d") |!strcmp(mod[n], "--dead")){
            strcpy(eyes, "xx");
            strcpy(tongue, "U");
        }
        else if ( !strcmp(mod[n], "-s") |!strcmp(mod[n], "--stone")){
            strcpy(tongue, "U");
            strcpy(eyes, "**");
        }
        else if ( !strcmp(mod[n], "-b") |!strcmp(mod[n], "-borg")){
            strcpy(eyes, "==");
        }
        else if ( !strcmp(mod[n], "-w") |!strcmp(mod[n], "--what")){
            strcpy(eyes, "OO");
        } 
        else if ( !strcmp(mod[n], "-y") |!strcmp(mod[n], "--young")){
            strcpy(eyes, "..");
        }
        else if ( !strcmp(mod[n], "-z") |!strcmp(mod[n], "--zebu")){
            strcpy(top," ^   ^");
            strcpy(corn,"|\\_/|");
            strcpy(bos, "/\\");
        }
        else if (!strcmp(mod[n], "-a")|!strcmp(mod[n], "--animate")){
            animate=1;
        }
    }
    // comptage des arguments
    for(int n=1;n<argc;n++){
        int i=0;
        if (!strcmp(mod[n],"-e")|!strcmp(mod[n],"--eyes")){
            i=1;
            n++;
        }
        else if (!strcmp(mod[n],"-t")|!strcmp(mod[n],"--tired")){
            i=1;
        }
        else if (!strcmp(mod[n],"-z")|!strcmp(mod[n],"--zebu")){
            i=1;
        }
        else if (!strcmp(mod[n],"-g")|!strcmp(mod[n],"--greedy")){
            i=1;
        }
        else if (!strcmp(mod[n],"-b")|!strcmp(mod[n],"--borg")){
            i=1;
        }
        else if (!strcmp(mod[n],"-y")|!strcmp(mod[n],"--young")){
            i=1;
        }
        else if (!strcmp(mod[n],"-s")|!strcmp(mod[n],"--stone")){
            i=1;
        }
        else if (!strcmp(mod[n],"-d")|!strcmp(mod[n],"--dead")){
            i=1;
        }
        else if (!strcmp(mod[n],"-p")|!strcmp(mod[n],"--paranoia")){
            i=1;
        }
        else if (!strcmp(mod[n],"-w")|!strcmp(mod[n],"--what")){
            i=1;
        }
        else if (!strcmp(mod[n], "-a")|!strcmp(mod[n], "--animate")){
            animate=1;
        }
        else if (n<argc & i==0){
            longueur=(longueur+1+strlen(mod[n]));
        }
    }
    if (longueur == 0){
        printf("Erreur:Au moins 2 arguments");
    }
    longueur = longueur+1;
    // affichage de la vache
    
    printf("\n");

    if (animate==0){
    dire(argc,mod);
    affiche_vache();
    }
    else if (animate==1){
        for(int s=0;s<=10;s++){
            strcpy(eyes,"OO");
            strcpy(tongue, "U");
            dire(argc,mod);
            affiche_vache();
            sleep(1);
            update(); 
            strcpy(eyes,"xx");
            strcpy(tongue, " ");
            gotoxy(20,1);
            dire(argc,mod);
            affiche_vache();
            sleep(1);
            update();
        }
    }
    return 0;
}