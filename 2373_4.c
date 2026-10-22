#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int reg;
    char name[50];
    struct Node *next;
};

struct Node *head = NULL;

void add() {
    struct Node *n = malloc(sizeof(struct Node));
    struct Node *t;

    printf("Enter RegNo and Name: ");
    scanf("%d %49s", &n->reg, n->name);
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
    printf("Student added successfully.\n");
}

void removeStudent() {
    int r;
    struct Node *t = head, *prev = NULL;

    printf("Enter RegNo to delete: ");
    scanf("%d", &r);

    while (t != NULL && t->reg != r) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    free(t);
    printf("Student deleted.\n");
}

void display() {
    struct Node *t = head;

    if (t == NULL) {
        printf("No students registered.\n");
        return;
    }

    while (t != NULL) {
        printf("RegNo: %d  Name: %s\n", t->reg, t->name);
        t = t->next;
    }
}

void count() {
    int c = 0;
    struct Node *t = head;

    while (t != NULL) {
        c++;
        t = t->next;
    }
    printf("Total students = %d\n", c);
}

void sort() {
    struct Node *i, *j;
    int r;
    char name[50];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->reg > j->reg) {
                r = i->reg;
                i->reg = j->reg;
                j->reg = r;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);
            }
        }
    }
    printf("List sorted by RegNo.\n");
}

void reverse() {
    struct Node *prev = NULL, *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    printf("List reversed.\n");
}

int main() {
    int ch;

    do {
        printf("\n1.Add 2.Remove 3.Display");
        printf("\n4.Count 5.Sort 6.Reverse 0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: add(); break;
            case 2: removeStudent(); break;
            case 3: display(); break;
            case 4: count(); break;
            case 5: sort(); break;
            case 6: reverse(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 0);

    return 0;
}