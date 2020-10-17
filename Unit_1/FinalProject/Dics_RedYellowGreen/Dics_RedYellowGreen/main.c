#include <stdio.h>

int main (void) {
    int i, numOfSet, red, yellow, green, value, sum = 0;
    float sumD, result;
    scanf ("%d", &numOfSet);
    for (i = 0; i < numOfSet; i++) {
        scanf ("%d %d %d", &red, &yellow, &green);
        value = red + (yellow*10) + (green*100);
        sum += value;
        sumD = (double) sum;
        result = sumD / (i+1);
        printf("%d. you rolled: %d, current average: %.1lf\n", i+1, value, result);
    }
    return 0;
}
