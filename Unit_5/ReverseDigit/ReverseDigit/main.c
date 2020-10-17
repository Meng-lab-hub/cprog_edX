#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit *readNumber(void);
struct digit *createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);

//add your prototype(s) here
struct digit * reverseNumber(struct digit * start);
struct digit * insertAtFront(struct digit * bstart, struct digit *newdigit);

int main(void) {
    struct digit *start, *backwards;
    start = readNumber();
    backwards = reverseNumber(start);
    printf("The reverse of ");
    printNumber(start);
    printf("is ");
    printNumber(backwards);
        
    freeNumber(start);
    freeNumber(backwards);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

//add your reverseNumber() function here
struct digit * reverseNumber(struct digit * start) {
    struct digit *ptr = start;
    struct digit *bstart = NULL;
    struct digit *newdigit;
    
    if (start!=NULL) {
        bstart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        newdigit = createDigit(ptr->num);
        bstart = insertAtFront(bstart, newdigit);
        ptr = ptr->next;
    }
    return bstart;
}

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}


/*
 #include <stdio.h>
 #include <stdlib.h>

 struct digit {
     int num;
     struct digit *next;
 };

 struct digit *reverseNumber(struct digit *start);
 int getLength(struct digit *start);
 int getNth(struct digit *start, int n);
 struct digit *createDigit(int dig);
 struct digit * append(struct digit * end, struct digit * newDigptr);
 void printNumber(struct digit *start);
 void freeNumber(struct digit *start);
 struct digit *readNumber(void);

 int main(void) {
     struct digit *start, *backwards;
     start = readNumber();
     backwards = reverseNumber(start);
     printf("The reverse of ");
     printNumber(start);
     printf("is ");
     printNumber(backwards);
         
     freeNumber(start);
     freeNumber(backwards);
     return 0;
 }

 struct digit *createDigit(int dig) {
     struct digit *ptr;
     ptr = (struct digit *) malloc(sizeof(struct digit));
     ptr->num = dig;
     ptr->next = NULL;
     return ptr;
 }

 struct digit * append(struct digit * end, struct digit * newDigptr) {
     end->next = newDigptr;
     return(end->next);
 }

 void printNumber(struct digit *start) {
     struct digit * ptr = start;
     while (ptr!=NULL) {
         printf("%d", ptr->num);
         ptr = ptr->next;
     }
     printf("\n");
 }

 void freeNumber(struct digit *start) {
     struct digit * ptr = start;
     struct digit * tmp;
     while (ptr!=NULL) {
         tmp = ptr->next;
         free(ptr);
         ptr = tmp;
     }
 }

 struct digit *readNumber(void) {
     char c;
     int d;
     struct digit *start, *end, *newptr;
     start = NULL;
     scanf("%c", &c);
     while (c != '\n') {
         d = c-48;
         newptr = createDigit(d);
         if (start == NULL) {
             start = newptr;
             end = start;
         } else {
             end = append(end, newptr);
         }
         scanf("%c", &c);
     }
     return(start);
 }

 int getNth(struct digit *start, int n){
     int i;
     struct digit *traverse = start;
     for (i=0; i<n; i++) {
         traverse = traverse->next;
     }
     return traverse->num;
 }

 int getLength(struct digit *start) {
     int i=0;
     struct digit *traverse = start;
     while (traverse != NULL) {
         traverse = traverse->next;
         i++;
     }
     return i;
 }
 
 */
