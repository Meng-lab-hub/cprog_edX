#include <stdio.h>

double square(double);

int main() {
        double a = 2.5;
        printf(" %.2lf square is %.2lf\n", a, square(a));
        return 0;
}

double square(double x){
        return x*x;
}
