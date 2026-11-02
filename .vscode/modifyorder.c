#include<stdio.h>
#include<stdlib.h>
#include "rasturant.h"

typedef struct Order {
    int id;
    int quantite;
    int status; // Par exemple : 0 pour en cours, 1 (ou autre) pour complété
    struct Order* next;
} Order;


int modifyorder(Order* head,int idorder,int x){
Order*current = head;
while(current!=NULL){
    if(current->id = idorder){
        if(current->status==1){
            printf("le plat est déja compléte,modification impossible./n");
        }else{
        current->quantite=x;
        printf("quantité modifiée");}
        return 1;
    }else {
    current=current->next;}
}
printf("order non trouvé./n");
return 0;
}
