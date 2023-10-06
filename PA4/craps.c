#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "craps.h"

void print_game_rules(void) {
    printf("Welcome to the game of Craps!\n");
    printf("Rules:\n");
    printf("1. Roll two dice.\n");
    printf("2. If the sum is 7 or 11 on the first roll, you win.\n");
    printf("3. If the sum is 2, 3, or 12 on the first roll (called 'craps'), you lose.\n");
    printf("4. If the sum is 4, 5, 6, 8, 9, or 10 on the first roll, it becomes your 'point.'\n");
    printf("5. To win, you must roll your 'point' again before rolling a 7.\n");
}

double get_bank_balance(void) {
    double balance;
    printf("Enter your initial bank balance (in dollars, e.g., 100.00): ");
    scanf("%lf", &balance);
    return balance;
}

double get_wager_amount(void) {
    double wager;
    printf("Enter your wager amount (in dollars): ");
    scanf("%lf", &wager);
    return wager;
}

int check_wager_amount(double wager, double balance) {
    return (wager > 0 && wager <= balance);
}

int roll_die(void) {
    return (rand() % 6) + 1;
}

int calculate_sum_dice(int die1_value, int die2_value) {
    return die1_value + die2_value;
}

int is_win_loss_or_point(int sum_dice) {
    if (sum_dice == 7 || sum_dice == 11) {
        return 1; 
    } else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
        return 0; 
    } else {
        return -1; 
    }
}

int is_point_loss_or_neither(int sum_dice, int point_value) {
    if (sum_dice == point_value) {
        return 1; 
    } else if (sum_dice == 7) {
        return 0; 
    } else {
        return -1; 
    }
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
    if (add_or_subtract == 1) {
        return bank_balance + wager_amount;
    } else if (add_or_subtract == 0) {
        return bank_balance - wager_amount;
    } else {
        return bank_balance;
    }
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
    printf("Roll #%d: ", number_rolls + 1);
    if (win_loss_neither == 1) {
        printf("You win!\n");
    } else if (win_loss_neither == 0) {
        printf("You lose!\n");
    } else {
        printf("Rolling again...\n");
    }
    printf("Initial balance: $%.2lf, Current balance: $%.2lf\n", initial_bank_balance, current_bank_balance);
}
