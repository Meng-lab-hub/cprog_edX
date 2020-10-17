#include <stdio.h>

int main(void) {
    FILE *ofile;
    char filename[] = "myGrades.txt";
    int lastGrade, input;
    
    scanf("%d", &input);
    
    ofile = fopen(filename, "r");
    
    while ( fscanf(ofile,"%d", &lastGrade) != EOF ) {
        printf("%d ", lastGrade);
        lastGrade = lastGrade;
    }
    
    fclose(ofile);
    
    if ( input != lastGrade ) {
        ofile = fopen( filename, "a" );
        
        fprintf(ofile, " %d", input);
        fclose(ofile);
    }
    printf("%d ", input);
    
    return 0;
}
