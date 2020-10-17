#include <stdio.h>

int sumOfDigits (int);
int input (void);

int main (void) {
    int sum, digit;
    digit = input ();
    sum = sumOfDigits (digit);
    printf ("%d\n", sum);
    return 0;
}

int sumOfDigits (int digit) {
    int result;
    if (digit < 10) {
        result = digit;
    } else {
        result = (digit % 10) + sumOfDigits(digit / 10);
    }
    return result;
}

int input (void) {
    int result;
    scanf ("%d", &result);
    return result;
}
