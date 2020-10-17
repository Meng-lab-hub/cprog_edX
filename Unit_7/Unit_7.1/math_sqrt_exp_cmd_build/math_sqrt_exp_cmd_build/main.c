#include <stdio.h>
#include <math.h>
int main(void) {
    int number;
    scanf("%d", &number); // get the input
    double square = sqrt(number);  // find the square of the input
    double exponential = exp(1);  // find the e^1
    printf("%.8lf\n", square);
    printf("%.10lf\n", exponential);
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -lm -o program\n");  /* print the cmd build which has been change and add the relative path of the defination of the libary*/
    return 0;
}
