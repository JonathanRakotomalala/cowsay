#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

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
    for(int n=1;n<longueur;n++){
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
    for(int n=1;n<longueur;n++){
        printf("-");
    }
    printf("\n");
}

void reading_cow(char *argv[]){
    char c[1];
    //char *nom = f;
    char z[MAX]=" ";
    char cop[MAX]="boop";
    int n;
    FILE *f=fopen(*argv, "r");
    if (f==NULL){f=stdin;}
    else{
        fscanf(f,"%c",c);
        while (!feof(f)){
            n++;
            strcpy(tongue, c);
            //printf("%c",c);
            //printf("\n");
            dire(z);
            affiche_vache();
            strcat(z,c);
            fscanf(f,"%c",c);
            //update();
            sleep(1);
            //z[n+1]='\0';
        }
    }
    fclose(f);
    //return 0;
}
int main(int argc, char *argv[]){
    reading_cow(&argv[1]);
    //return 0;
}
