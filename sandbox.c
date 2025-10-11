#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool inBound(char c){ return c > 47 && c < 58 || c > 64 && c < 91; }
bool isPalindrome(char* s) {
    int lower = 0, upper = strlen(s)-1;
    while(lower <= upper){
        if(s[lower]>96) s[lower]-=32;
        if(s[upper]>96) s[upper]-=32;
        if(!inBound(s[lower]))
            lower++;
        else if(!inBound(s[upper]))
            upper--;
        else if (s[lower] != s[upper])
            return false;
        else{
            lower++; upper--;
        }
    }
    return true;
}

int main(){
    char array[] = "0a";
    int arraySize = 5;
    printf("%d\n",isPalindrome(array));
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