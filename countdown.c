#include <stdio.h>

void countdownfrom10() {
    for (int i = 10; i >= 1; i--) {
        printf("%d\n", i);
    }
}

void countdownfrom1() {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
}

void invalid() {
    printf("Please enter either 10 or 1\n");
}

int main() {
    int number = 0;

    printf("Would you like the countdown to start from 10 or 1?\n");
    scanf("%d", &number);

    if (number == 10) {
        countdownfrom10();
    } else if (number == 1) {
        countdownfrom1();
    } else {
        invalid();
    }

    return 0;
}
