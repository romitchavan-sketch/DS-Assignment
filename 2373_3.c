#include <stdio.h>

struct  student {
     int r_no;
     char name[20];
     float marks;
};
void linearSearch(struct student s[], int n, int val);
void binarySearch(struct student s[], int n, int val);
void selSort(struct student s[], int n);
void inSort(struct student s[], int n);
void shellSort(struct student s[], int n);
void display(struct student s[], int n);

int main(){
struct student s[10];
int choice ,n,val;
printf("Enter number of students: ");
    scanf("%d", &n);
if (n>10){
    printf("Error");
    return 0;
    }
    
    printf("\nEnter student details:\n");

    for (int i = 0; i < n; i++) {

        printf("\nStudent %d\n", i + 1);
        
        printf("Enter Students name:");
        scanf("%s",&s[i].name);
        
        printf("Enter Roll No: ");
        scanf("%d", &s[i].r_no);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    do {

        printf("\n= MENU =\n");
        printf("1. Linear  search\n");
        printf("2. Binary search\n");
        printf("3. Selection sort\n");
        printf("4. Insertion sort\n");
        printf("5. Shell sort\n");
        printf("6. Display students\n");
        printf("7. Exit\n");
       

        printf("\nEnter your choice:\n ");
        scanf("%d", &choice);
    
     
        switch (choice) {
                      case 1:
                                  printf("Enter Roll.no to search: ");
                                  scanf("%d", &val);
                                  linearSearch(s, n, val);
                                  break;
                       case 2:
                                  printf("Enter Roll.no to search: ");
                                  scanf("%d", &val);
                                  binarySearch(s,n,val);
                                  break;
                        case 3:
                                   selSort(s,n);
                                   printf("Students are sorted according to their marks:");
                                   display(s,n);
                                   break;
                          case 4:
                                   inSort(s,n);
                                   printf("Students are sorted according to their marks:");
                                   display(s,n);
                                   break;
                             case 5:
                                   shellSort(s,n);
                                   printf("Students are sorted according to their marks:");
                                   display(s,n);
                                   break;
                              case 6:
                                     display(s,n);
                                     break;
                               case 7:
                                      printf("end");
                                      break;
                                 }
                             } while (choice != 7); 
                return 0;
                            }                

           void linearSearch(struct student s[], int n, int val){
                       for (int i = 0; i<n; i++){
                              if ( s[i].r_no==val){
                                    printf("Student name: %s", s[i].name);
                                    printf("Student rollno: %d", s[i].r_no);
                                    printf("Student marks: %f" , s[i].marks);  
                                     return;
                                     }
                           }
           }
             void binarySearch(struct student s[], int n, int val){
                         int a = 0;
                         int b = n - 1;

                        while (a<= b) {

                           int mid = (a+ b) / 2;

                          if (s[mid].r_no == val);
                             printf("Name: %s\n", s[mid].name);
                             printf("Roll No: %d\n", s[mid].r_no);
                             printf("Marks: %d\n", s[mid].marks);

                             return;
                   }
             }
              void selSort(struct student s[], int n) {

                    int i, j, min;
                    struct student temp;

                       for (i = 0; i < n - 1; i++) {

                             min = i;

                             for (j = i + 1; j < n; j++) {

                                 if (s[j].marks < s[min].marks)
                                 min = j;
                                 }

                             if (min != i) {

                                 temp = s[i];
                                 s[i] = s[min];
                                 s[min] = temp;
                                 }
                              }
               }
             void inSort(struct student s[], int n) {

                  int i, j;
                  struct student key;

                  for (i = 1; i < n; i++) {

                       key = s[i];
                       j = i - 1;

                       while (j >= 0 && s[j].marks > key.marks) {

                              s[j + 1] = s[j];
                              j--;
                              }

                       s[j + 1] = key;
                       }
              }
             void shellSort(struct student s[], int n) {

                  int gap, i, j;
                  struct student temp;

                  for (gap = n / 2; gap > 0; gap /= 2) {

                        for (i = gap; i < n; i++) {

                            temp = s[i];
                            j = i;

                            while (j >= gap && s[j - gap].marks > temp.marks) {

                                  s[j] = s[j - gap];
                                  j -= gap;
                                  }

                           s[j] = temp;
                           }
             }
             }
            void display(struct student s[], int n) {

                 printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    

                 for (int i = 0; i < n; i++) {

                     printf("%-10d %-20s %-10.2f\n",s[i].r_no,s[i].name,s[i].marks);
    }


}


        
            
                   