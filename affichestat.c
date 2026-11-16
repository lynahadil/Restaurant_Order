#include<stdio.h>
#include<stdlib.h>
typedef struct order{
float price;
struct order *next;
int status;
}order;
void affichestatic(order* head) {
int cpt_t=0;
int cpt_attente=0;
float pricef=0.0;
if(head!=NULL){
    order *current = head;

while(current!=NULL){
    cpt_t++ ;
    if (current->status==1){
        pricef += current->price;
    }else {
    cpt_attente++;}
current = current->next;}
}
printf("nombre total de command :%d\n",cpt_t);
printf("nombre de command en attente : %d\n",cpt_attente);
printf("Montant totaldes command teminees:%.2f\n",pricef);
}
