#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct resturant {
int id;
char name[50];
char categore[50];
float price;
struct resturant* next;
};

struct resturant* creatnew(struct resturant* P , int x ,char y[],char t[],float z){
struct resturant *H, *Q ;
H = (struct resturant*) malloc(sizeof(struct resturant));
if (H == NULL){
    printf(" erreur d'allocation mémoire !/n");
    return P;
}
H->id =x;
H->price =z;
strcpy(H->name,y);
strcpy (H ->categore,t);
if (P== NULL){
    P=H;
} else{ Q=P;
while(Q-> next != NULL){
     Q = Q -> next;
} Q-> next  =H;
}

return P;
};


