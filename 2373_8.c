#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int q[SIZE];
int rear= -1;
int front= -1;

void enqueue(int a);
void dequeue();
void display();
void peek();

int main(){
int choice , val;
while(1){
          printf("\n MENU \n");
          printf("\n 1. Enqueue ");
          printf("\n 2. Dequeue ");
          printf("\n 3. Display ");
          printf("\n 4. Peek ");
          printf("\n 5. Exit ");
          printf("\n Enter your choice: ");
          scanf("%d", &choice);
          
          switch (choice){
          case 1: 
                     printf("Enter valeue in queue");
                     scanf("%d", &val);
                     enqueue(val);
                     break;
           case 2:
                      dequeue();
                      break;
            case 3:
                       display();
                       break;
             case 4:
                        peek();
                        break;
              case 5:
                         exit(0);
              }
            
         }
         return 0;
 }
 void enqueue(int val){
          if(rear == SIZE - 1){
               printf("queue is full");
           }
           else if(front== -1){
                    front = 0;
            }
            rear++;
            q[rear] = val;
        }
 void dequeue(){
           if(front==-1 && rear==-1){
               printf("queue is empty");
           }
           else{
                 printf("\nDeleted element: %d", q[front]);
                 front++;
                 }
           }
 void display(){
         if( front == -1){
             printf("\n queue is empty");}
         else{
              printf("\n Elements of queue are: ");
                      for(int i= front; i<= rear; i++){
                             printf("\n %d", q[i]);
                             }
                      }        
          }
  void peek(){
          printf("\n The first element in the queue is : %d", q[front]);
          }
