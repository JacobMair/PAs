#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "craps.h"

int main() {
    srand(time(NULL)); 

    print_game_rules();

    double initial_balance = get_bank_balance();
    double current_balance = initial_balance;

    int num_rolls = 0;
    int point = 0;

    while (current_balance > 0) {
        printf("\nRoll #%d\n", num_rolls + 1);
        double wager = get_wager_amount();

        if (!check_wager_amount(wager, current_balance)) {
            printf("Invalid wager. Please try again.\n");
            continue;
        }

        int die1 = roll_die();
        int die2 = roll_die();
        int sum = calculate_sum_dice(die1, die2);

        if (num_rolls == 0) {
            int result = is_win_loss_or_point(sum);
            if (result == 1) {
                current_balance = adjust_bank_balance(current_balance, wager, 1);
                chatter_messages(num_rolls, result, initial_balance, current_balance);
                break;
            } else if (result == 0) {
                current_balance = adjust_bank_balance(current_balance, wager, 0);
                chatter_messages(num_rolls, result, initial_balance, current_balance);
                break;
            } else {
                point = sum;
                printf("Point is set to %d\n", point);
            }
        } else {
            int result = is_point_loss_or_neither(sum, point);
            if (result == 1) {
                current_balance = adjust_bank_balance(current_balance, wager, 1);
                chatter_messages(num_rolls, result, initial_balance, current_balance);
                break;
            } else if (result == 0) {
                current_balance = adjust_bank_balance(current_balance, wager, 0);
                chatter_messages(num_rolls, result, initial_balance, current_balance);
                break;
            }
        }

        num_rolls++;
    }

    if (current_balance == 0) {
        printf("Sorry, you've run out of money. Game over!\n");
    }

    return 0;
}
