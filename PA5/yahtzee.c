#include "yahtzee.h"
#include <stdlib.h>

int rollDie() {
    return (rand() % 6) + 1;
}

int rollDice(int numDice) {
    int sum = 0;
    for (int i = 0; i < numDice; i++) {
        sum += rollDie();
    }
    return sum;
}
