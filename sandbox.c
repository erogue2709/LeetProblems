#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int hIndex(int* citations, int citationsSize) {
    int* bucket = (int*)calloc(citationsSize+1, sizeof(int));
    for(int i = 0; i < citationsSize; i++)
        bucket[citations[i] >= citationsSize? citationsSize : citations[i]]++;

    int cptH = 0;
    for(int j = citationsSize; j >= 0; j--){
        cptH += bucket[j];
        if(cptH>=j) return cptH;
    }
    return 0;
}

int main(){
    int array[] = {3,0,6,1,5};
    int arraySize = 5;
    printf("%d\n",hIndex(array, arraySize));
    for(int i = 0; i < arraySize; i++)
        printf("%d\t", array[i]);
    return 0;
}



/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <cstdint>

typedef struct{
    int age;
    char firstName[60];
    bool isHeOK;
    struct Personne* MOTHER;
} Personne;

void BuildAGuy(Personne* personne1){
    personne1->age = 35;
    strcpy(personne1->firstName, "idk");
    personne1->isHeOK = true;
    personne1->MOTHER = NULL;
}

int main(){
    Personne* personne1;
    BuildAGuy(personne1);
    printf("%s\n", personne1->firstName);
    printf("okok\n");
    return 0;
}
*/