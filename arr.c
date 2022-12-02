#include<stdio.h>
#include<stdlib.h>

int* addGrade(int numToAdd, int* arrayPtr, int currentLen){
    int *newLoc ;

    newLoc = (int*)malloc((currentLen+1)*sizeof(int));

    //int newLoc[currentLen+1];
    
    int i=0;
    while(i<=currentLen){
        *(newLoc+i) = *(arrayPtr + i);
        i += 1;
    }

    *(newLoc+currentLen) = numToAdd;

    return newLoc;

}

int main(){

    int gradeArray[] = {69,21,96};
    int *arrayPtr = &gradeArray[0];

    int *myGrades;
    myGrades = (int*)malloc(sizeof(gradeArray));

    int length = sizeof(gradeArray)/sizeof(int);

    for(int i=0; i < length; i++){
        *(myGrades+i) = *(arrayPtr+i);
    }

    printf("%i\n",*(arrayPtr));

    //int myGrades[] = {66,76,85};


    while(1){

        int numToAdd ;

        printf("\nInput a number to add to your grades: ");
        scanf("%i",&numToAdd);
        
        //int* gradesPtr = &myGrades[0];

        int* newArray = addGrade(numToAdd,myGrades,length);

        length += 1;


        free(myGrades);

        myGrades = newArray;

        printf("the array: [");

        for(int i=0; i < length; i++){
            printf("%i, ",*(myGrades+i));}
        printf("]\n");
    };
};