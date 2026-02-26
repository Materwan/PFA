/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
    printf("%d\n", init_integration("trapezes", 0.001));

    Option *call = malloc(sizeof(Option));
    call->type = CALL;
    call->S0 = 100;
    call->K = 110;
    call->T = 1;
    call->mu = 0.05;
    call->sig = 0.2;

    printf("%f\n", optionPrice(call));

    Option *put = malloc(sizeof(Option));
    put->type = PUT;
    put->S0 = 100;
    put->K = 90;
    put->T = 1;
    put->mu = 0.05;
    put->sig = 0.2;

    printf("%f\n", optionPrice(put));

    return 0;
}
