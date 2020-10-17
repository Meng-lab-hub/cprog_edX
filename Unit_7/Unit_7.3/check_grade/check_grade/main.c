#include <stdio.h>

int main(void) {
    int Hposition = 0, i = 1, loop_count = 0;
    float previousNumber = 0, ourgrade = 0, number;
    FILE *ifile;   /* ifile is a variable name, we call this a file pointer */
    
    ifile = fopen("gradeComparison.txt", "r");   /* open file for reading,
    r stand for reading */
    
    while ( fscanf(ifile, "%f", &number) != EOF ) {
        if ( i == 1 ) {
            ourgrade = number;      // use to store grade of our class from the first number
        }
        if ( number > previousNumber ) {
            previousNumber = number;      // at last previousNumber will be the highest grade
            if ( loop_count == 1) {
                Hposition = i;
            }
            loop_count = loop_count + 1;
        }
        i++;
    }
    
    if ( ourgrade >= previousNumber ) {
        printf("Yes\n");
    } else {
        printf("No %.d\n", Hposition);
    }
    
    fclose(ifile);    /* close the file */
    
    return 0;
}




/*
 
 #include <stdio.h>

 int main(void) {
     FILE *ifile;
     int N, done, best;
     double myClass, otherClass;
     
     ifile = fopen("gradeComparison.txt", "r");
     
     fscanf(ifile, "%lf", &myClass);
     N=1;
     done = 0;
     best = 1;
     
     while (!done) {
         done = fscanf(ifile, "%lf", &otherClass) == EOF;
         if (!done) {
             N++;
             if (otherClass>myClass) {
                 done = 1;
                 best = 0;
             }
         }
     }
     
     fclose(ifile);
     
     if (best) {
         printf("Yes\n");
     } else {
         printf("No %d\n", N);
     }
     
     return 0;
 }
 
 
 */
