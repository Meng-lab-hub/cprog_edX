#include <stdio.h>
#include <stdlib.h>   // for atoi and atof
#include <string.h>     // for strcmp

int main(int argc,const char *argv[]) {
    int i, compare, age;
    double idNumber;
    char c, gender;
    
    printf("Please give your information in the format showed below:\nIndex: Name: Age: Id number");
    printf("I have %d arguments:\n", argc);
    for(i=0;i<argc;i++){
        printf("%s\n", argv[i]);
    }
    
    printf("for the last argument in separate charater is:\n");
    while((c = *(argv[argc-1]++)) != '\0'){
        printf("%c\n",c);
    }
    
    if(argc == 5){
        if(strcmp(argv[1], "Mr") == 0){
            gender = 'M';
        }
        if(strcmp(argv[1], "Mrs") == 0){
            gender = 'F';
        } else {
            printf("Please give your title in the given way: Mr or Mrs\n");
            return 1;
        }
        
    age = atoi(argv[3]);
    if(gender == 'M'){
        compare = strcmp(argv[2], "meng");
        if(compare == 0){
            printf("He is our employee\n");
        }else{
            printf("He is not our employee\n");
        }
        if(age < 18){
            printf("He is not adult yet\n");
        }else{
            printf("He is not adult yet\n");
        }
        idNumber = atof(argv[4]);
         if(idNumber < 192168.118){
             printf("He is general employee\n");
         }else{
             printf("He is super employee\n");
         }
    }else{
        compare = strcmp(argv[2], "meng");
        if(compare == 0){
            printf("she is our employee\n");
        }else{
            printf("She is not our employee\n");
        }
        if(age < 18){
            printf("She is adult\n");
        }else{
            printf("She is adult\n");
        }
        idNumber = atof(argv[4]);
         if(idNumber < 192168.118){
             printf("She is general employee\n");
         }else{
             printf("She is super employee\n");
         }
    }
    }
    return 0;
}
