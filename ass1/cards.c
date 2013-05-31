#include <stdio.h>
#include <stdlib.h>

#define N_TRIALS 100000
#define ACE 0   /* you don't have to use this macro */


double strategyA_Theoritical(int);
double strategyA(int);
double strategyB_Theoritical(int);
double strategyB(int);



int main(int argc, char **argv)
{
   // prompt the user to enter number of cards for this experiments
    printf("Enter the number of cards (3 ~ 10): ");
    int n_cards; scanf("%d",&n_cards);

    printf("strategyA (Theoritic):   %lf\n", strategyA_Theoritical(n_cards));
    printf("strategyA (Empirical):   %lf\n", strategyA(n_cards));

    printf("\nstrategyB (Theoritic):   %lf\n", strategyB_Theoritical(n_cards));
    printf(  "strategyB (Empirical):   %lf\n", strategyB (n_cards));


    return 0;
}

double strategyA_Theoritical(int n_cards)
{
    // Since player sticks with first guess, it makes no difference which
    // other card the dealer turns over, so

    // true probability = probability that first guess is correct
     //                 = 1 / n_cards.
    // Use 1.0 to avoid integer division.

    double true_probability = 1.0 / n_cards;

    return true_probability;
}

double strategyA(int n_cards) 
{

    // Measure probability by assuming cards are numbered 0 .. n_cards - 1
    // Repeatedly:
    //  randomly pick a card (i.e., a number in [0, n_cards))
    //  and count the number of times ACE is chosen.

    double wins = 0.0;
    int i;
    for (i = 0; i < N_TRIALS; i++) {
    	int card = rand() % n_cards;
        if (ACE == card) {
            wins++;
        }
    }
    return wins / N_TRIALS;
}


double strategyB_Theoritical(int n_cards)
{
    // true probability =
    //    (probability that first choice is wrong)
    //  * (probability that second choice is right)
    // = ( (n_cards - 1) / n_cards) * (1 / (n_cards - 2))
    // Rearrange and use 1.0 instead of 1 to avoid integer division:

    double true_probability =
        1.0 / (n_cards - 2) * (n_cards - 1) / n_cards;

    return true_probability;
}


double strategyB(int n_cards)
{
    // Measure probability by assuming cards are numbered 0 .. n_cards - 1
    // Repeatedly:
    //  - the player randomly chooses a card, i.e. a number in 0 .. nCards - 1.
    //  - the dealer turns over (i.e. eliminates) some other card that is
    //    not the chosen card or card ACE.
    //  - the player randomly chooses a second card that is not the first
    //    one chosen and also not the one turned over by the dealer
    double wins = 0.0;
    int i;
    for (i = 0; i < N_TRIALS; i++) {
        int card1 = rand() % n_cards;
        int card2 = rand() % (n_cards - 2);
        if (card1 != ACE && card2 == ACE) {
            wins++;
        }
    }
    return wins / N_TRIALS;

}

/*
 * StrategyB is clearly better
 */

