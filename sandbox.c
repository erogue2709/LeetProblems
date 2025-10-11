#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0, lowerBound = 0, upperBound;

    while(lowerBound < pricesSize){
        while(lowerBound + 1 < pricesSize && prices[lowerBound] > prices[lowerBound+1])
            lowerBound++;
        upperBound = lowerBound;
        while(upperBound + 1 < pricesSize && prices[upperBound] < prices[upperBound+1])
            upperBound++;
        if(prices[upperBound] - prices[lowerBound] > 0 )
            profit += prices[upperBound] - prices[lowerBound];
        lowerBound = ++upperBound;
    }
    return profit;
}

int main(){
    int prices[] = {7,1,5,3,6,4};
    printf("%d",maxProfit(prices, 6));
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