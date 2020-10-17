#include <stdio.h>

int main(void) {
    int N = 0, number, done = 0, message, sum = 0;
    FILE *ifile;   /* ifile is a variable name, we call this a file pointer */
    
    ifile = fopen("studentGrades.txt", "r");   /* open file for reading,
    r stand for reading */
    
    while ( !done ) {
        message = fscanf(ifile, "%d", &number);  // actually fscanf return something
        if ( message == EOF ) {
            done = 1;
        } else {
            printf("the %d number is: %d\n", N, number);
            sum += number;
            N++;
        }
    }
    
    printf("there are %d number in the file\n", N);
    printf("the sum of all the number is: %d\n", sum);
    printf("the average of all the number is: %.2f\n", (float) (sum/N));
    fclose(ifile);    /* close the file */
    
    return 0;
}

/*

while ( fscanf(ifile, "%d", &number) != EOF ) {
        printf("the %d number is: %d\n", N, number);
        sum += number;
        N++;
    }
}
 
 */
