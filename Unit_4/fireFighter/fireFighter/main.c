#include <stdio.h>
#include <stdlib.h>

int * allocateIntArray(int);
int ** allocateIntStarArray (int);

int main (void) {
    int lenght, width;
    int ** star;

    scanf ("%d %d", &lenght, &width);
    
    star = allocateIntStarArray (width);
    for (int i = 0; i < width; i++) {
        * (star + i) = allocateIntArray (lenght);
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < lenght; j++) {
            scanf ("%d", &star[i][j]);
        }
    }
    
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 6; col++) {
            if (* (* (star + row) + col) > 1000) {
                * (* (star + row) + col) = 'X';
            } else if (* (* (star + row) + col) >= 100 && (* (* (star + row) + col) <= 1000)) {
                * (* (star + row) + col) = '*';
            } else {
                * (* (star + row) + col) = ' ';
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 6; j++) {
            printf ("[%c]", * (* (star + i) + j));
        }
        printf ("\n");
    }
    
    return 0;
}

int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}

int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}


/*
 
 #include <stdio.h>
 #include <stdlib.h>

 int ** allocateIntStarArray(int num){
     int ** ptr = (int **) malloc(num * sizeof(int *));
     return ptr;
 }

 int * allocateIntArray(int num){
     int * ptr = (int *) malloc(num * sizeof(int));
     return ptr;
 }

 int main(void)
 {
     int line, col,i,j;
     scanf("%d",&col);
     scanf("%d",&line);
     int ** matrix = allocateIntStarArray(line);
     for(i = 0; i < line; i++){
      matrix[i] = allocateIntArray(col);
     }


     for(i = 0; i < line; i++){
         for(j = 0; j < col; j++){
             scanf("%d",&matrix[i][j]);
         }
     }

      for(i = 0; i < line; i++){
         for(j = 0; j < col; j++){
             if(matrix[i][j]>1000){
                 printf("[X]");
             }else{
                 if(matrix[i][j]>=100){
                 printf("[*]");
                 }else{
                 printf("[ ]");
                 }
             }
            
         }
         printf("\n");
     }
    

     return 0;
 }
 
 */
