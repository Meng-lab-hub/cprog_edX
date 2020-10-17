#include <stdio.h>

double ctof(int);
// insert prototype for function ftoc() here

double ftoc(int);
// insert prototype for function ctof() here


int main(void) {

    int usertemp;
    char unit;
    double convertedtemp;
    printf("the temperature to convert: ");
    scanf("%d %c", &usertemp, &unit);
    if (unit=='C'){
        convertedtemp = ctof(usertemp);
        printf("%.1lf F\n", convertedtemp);
        // insert function call here to convert usertemp
           /* from Celsius to Fahrenheit and store the result in convertedtemp */

        // complete this line to print out the conversion result

    } else if (unit=='F'){
        convertedtemp = ftoc(usertemp);
        printf("%.1lf C\n", convertedtemp);
        // insert function call here to convert usertemp
           /* from Fahrenheit to Celsius and store the result in convertedtemp */
        
        // complete this line to print out the conversion result
        
    }

    return 0;

}

/* Function definitions below are provided for you*/

/* Conversion from Celsius to Fahrenheit: */
double ctof(int x){
    return((9.0/5)*x+32);
}

/* Conversion from Fahrenheit to Celsius: */
double ftoc(int x){
    return(5.0/9*(x-32));
}
