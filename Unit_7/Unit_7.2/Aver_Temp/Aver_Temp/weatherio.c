#include <stdio.h>

void printTemps(double *temps, int numOfTemps){
    int i;
    printf("Over past %d days, the temperature were:\n", numOfTemps);
    for(i=0;i<numOfTemps;i++){
        printf("Day %d: %.2lf\n", i+1, temps[i]);
    }
}
