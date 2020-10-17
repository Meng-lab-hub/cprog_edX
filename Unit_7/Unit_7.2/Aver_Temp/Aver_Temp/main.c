#include <stdio.h>
#include "weatherstats.h"
#include "weatherio.h"


int main(void) {
    double temperatures[7] = {6.9, 12.3, 9.0, 5.3, 9.8, 1.8, 0.3};
    printf("Average 7 days Temperature is: %.2lf\n", averageTemp(temperatures, 7));
    printf("Maximum temperature is: %.2lf\n", maxTemp(temperatures, 7));
    printf("Minimum temperature is: %.2lf\n", minTemp(temperatures, 7));
    printTemps(temperatures, 7);
    return 0;
}
