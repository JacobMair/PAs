#include <stdio.h>
#include <stdlib.h>
#include "yahtzee.h"

int main() {
    srand(42); 

    int numDice = 5;

    printf("Dice rolled: ");
    int total = rollDice(numDice);

    for (int i = 0; i < numDice; i++) {
        int dieValue = rollDie();
        printf("%d ", dieValue);
    }
    printf("\n");

    printf("Total sum of dice: %d\n", total);

    return 0;
}
