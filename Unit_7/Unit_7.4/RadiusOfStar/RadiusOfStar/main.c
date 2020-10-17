#include <stdio.h>
#include <string.h>
#include <math.h>
//add additional header files here

struct star {
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
    
};

void printStars(struct star mystars[], int N);
int readStars(struct star star[]);
void computeRadii(struct star star[], int numberOfStar);
void classifyStars(struct star star[], int numberOfStar);
//add your prototypes here

// Do not modify the main() function!
int main(void) {
    struct star mystars[50];
    int N;
    
    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);

    return 0;
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N) {
    int i;
    for (i=0; i<N; i++) {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') {
            printf("Main Sequence Star\n");
        } else if (mystars[i].classification == 'G') {
            printf("Giant\n");
        } else if (mystars[i].classification == 'S') {
            printf("Supergiant\n");
        } else if (mystars[i].classification == 'W') {
            printf("White Dwarf\n");
        } else if (mystars[i].classification == 'N') {
            printf("Unclassified Star\n");
        } else {
            printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

//add the functions readStars(), computeRadii() and classifyStars() here.
int readStars(struct star mystar[]) {
    FILE *ifile;
    int done = 0, i = -1, message;
    char fileName[] = "stardata.txt";
    
    ifile = fopen(fileName, "r");
    
    while ( !done ) {
        i++;
        message = fscanf(ifile, "%s %d %lf" , mystar[i].name, &mystar[i].temperature, &mystar[i].luminosity);
        if ( message == EOF ) {
            done = 1;
        }
    }
    fclose(ifile);
    return i;
}

void computeRadii(struct star mystar[], int numberOfStar) {
    int i, TempSun = 3500;
    double multipliedTemp;
    for (i =0; i<numberOfStar; i++) {
        multipliedTemp =(TempSun/ (double) mystar[i].temperature);
        mystar[i].radius = (double)((multipliedTemp*multipliedTemp) * sqrt(mystar[i].luminosity));
    }
}

void classifyStars(struct star mystar[], int numberOfStar) {
    int i;
    for ( i =0; i<numberOfStar; i++) {
        if ( mystar[i].radius > 0.1 && mystar[i].radius < 10 && (mystar[i].luminosity) > 0.01 && (mystar[i].luminosity) < 1000000 ) {
            mystar[i].classification = 'M';
        } else if ( mystar[i].radius > 10 && mystar[i].radius < 100 && (mystar[i].luminosity) > 1000 && (mystar[i].luminosity) < 100000 ) {
            mystar[i].classification = 'G';
        } else if ( mystar[i].radius > 100 && (mystar[i].luminosity) > 100000 && (mystar[i].luminosity) < 1000000 ) {
            mystar[i].classification = 'S';
        } else if ( mystar[i].radius < 0.01 ) {
            mystar[i].classification = 'W';
        } else {
            mystar[i].classification = 'N';
        }
    }
}
