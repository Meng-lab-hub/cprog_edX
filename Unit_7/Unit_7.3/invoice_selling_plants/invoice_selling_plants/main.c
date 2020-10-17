#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    if(argc < 3){
        printf("Invalid input.\n");
    }
    if(argc == 3){
    printf("%d plants for %.2f dollars each cost %.2f dollars.\n", atoi(argv[1]), atof(argv[2]), atoi(argv[1])*atof(argv[2]));
    }
    return 0;
}
