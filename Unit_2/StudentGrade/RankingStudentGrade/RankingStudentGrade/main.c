#include <stdio.h>

void print (int numStudent, int arrayRank[], char arrayName[][50]);
void input (int numStudent, int arrayGradeTemp[], int arrayGrade[], char arrayName[][50]);
void sorting (int numStudent, int arrayGrade[], int arrayGradeTemp[], int arrayRank[]);
int getNbStudent (void);

int main (void) {
    int nbStudent;
    nbStudent = getNbStudent (); // this function come first because we need to know how long the array we                                      need to declare other variable
    
    int grade[nbStudent], gradeTemp[nbStudent], rankOf[nbStudent];
    char name[nbStudent][50];
    
    input (nbStudent, gradeTemp, grade, name);
    sorting (nbStudent, grade, gradeTemp, rankOf);
    print (nbStudent, rankOf, name);
    
    return 0;
}

int getNbStudent (void) {           // get how many student we have
    int result;
    scanf ("%d", &result);
    return result;
}

void input (int numStudent, int arrayGradeTemp[], int arrayGrade[], char arrayName[][50]) {  // this function                                                                 is to get all the information from the user
    
    int i;
    for (i = 0; i < numStudent; i++) {
        scanf ("%d", &arrayGrade[i]);
        arrayGradeTemp[i] = arrayGrade[i];
    }
    for (i = 0; i < numStudent; i++) {
        scanf ("%s", arrayName[i]);
    }
}

void sorting (int numStudent, int arrayGrade[], int arrayGradeTemp[], int arrayRank[]) {
    int i, j, temp;
    for (i = 0; i < numStudent-1; i++) {                // here I sort the grade in order from big to small
        for (j = 0; j < numStudent-1; j++) {            // I copied all the grade to temporary array and sort           this array so I can keep the order of the old grade to match the order of student's name
            if (arrayGradeTemp[j] < arrayGradeTemp[j+1]) {
                temp = arrayGradeTemp[j];
                arrayGradeTemp[j] = arrayGradeTemp[j+1];
                arrayGradeTemp[j+1] = temp;
            }
        }
    }
    for (i = 0; i < numStudent; i++) {                  //here I look for the first grade and when I found it                                       I can give its rank to its location without modify its position
        for (j = 0; j < numStudent; j++) {
            if (arrayGradeTemp[i] == arrayGrade[j]) {
                arrayRank[j] = i+1;
            }
        }
    }
    
}

void print (int numStudent, int arrayRank[], char arrayName[][50]) {  // this function is to print our the                                                                             result
    int i;
    for (i = 0; i < numStudent; i++) {
        printf ("%s rank is %d\n", arrayName[i], arrayRank[i]);
    }
}





// below is the solution from edX


/*
 #include <stdio.h>
 int main(void)
 {
     int nbStudents;
     char name[51];
     int grade[30];
     int ranking[30];
     int i,j;
     int rank=0;

     scanf("%d", &nbStudents);
         
     for(i=0;i<nbStudents; i++) {
         scanf("%d", &grade[i]);
     }

     for(i=0;i<nbStudents; i++) {
        rank=0;
        for(j=0;j<nbStudents; j++) {
          if(grade[i]<grade[j]){
            rank++;
          }
          ranking[i]=rank+1;
        }
     }
     
     for(i=0;i<nbStudents; i++) {
         scanf("%s", name);
         printf("%s rank is %d\n",name,ranking[i]);
     }

     return 0;
 }
 */
