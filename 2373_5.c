#include<stdio.h>
#include<stdlib>

struct node{
            int coeff, exp;
            struct node *next;
            };
struct node* createnode(int c, int e){
            struct node n = malloc(sizeof(struct node));
            n-> coeff = c;
            n-> exp = e;
            n-> next = NULL;
            return n;
            }
void insert(struct node** head , int c, int e){
         struct node* n = createnode(c, e);
         if (*head = NULL){
             *head = n;
             return;
             }
         struct node* t = *head;
         while ( t-> next != NULL){
                    t = t-> next;}
          t-> next = n;
struct node* add( struct node* p, struct node* q){
            struct node* r = NULL;
            while (p !=NULL && q !=NULL){
                   if (p-> exp == q-> exp) {
                       int sum = p-> coeff + q-> coeff;
                       if(sum!=0)
                          insert(&r , sum , p-> exp);
                       p = p-> next;
                       q = q-> next;
                       }
                else if (p->exp > q->exp) {
                            insert(&r, p->coeff, p->exp);
                            p = p->next;    
                       }
                 else {
                          insert(&r, q->coeff, q->exp);
                          q = q-> next;
                          }      
                     
              
        
