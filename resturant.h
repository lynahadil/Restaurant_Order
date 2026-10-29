#ifdef  RESTURANT_H
#define RESTURANT_H

typedef struct MenuItem{
  int id;
  char name[50];
  char category[50];
  float price;
  struct MenuItem *next;

}MenuItem;
typedef struct OrderItem{
  int ItemId;
  int quantity;
}OrderItem;



#endif  

