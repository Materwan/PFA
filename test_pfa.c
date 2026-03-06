/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
    printf("%d\n", init_integration("trapezes", 0.1));

    Option *call = malloc(sizeof(Option));
    call->type = CALL;
    call->S0 = 100;
    call->K = 100;
    call->T = 2;
    call->mu = 0.05;
    call->sig = 0.02;

    printf("K ($)\t\t99\t100\t101\t102\t103\n");
    printf("Prix Call ($)");
    for (int i = 99; i <= 103; i++) {
        call->K = i;
        printf("\t%.4f", optionPrice(call));
    }
    printf("\n\n");

    call->K = 101;

    printf("T (année)\t1.8\t1.9\t2\t2.1\t2.2\n");
    printf("Prix Call ($)");
    for (double i = 1.8; i <= 2.2; i += 0.1) {
        call->T = i;
        // printf("%f\n", call->T);
        printf("\t%.4f", optionPrice(call));
    }
    printf("\n\n");

    Option *put = malloc(sizeof(Option));
    put->type = PUT;
    put->S0 = 100;
    put->K = 100;
    put->T = 2;
    put->mu = 0.05;
    put->sig = 0.02;

    printf("K ($)\t\t113\t114\t115\t116\t117\n");
    printf("Prix Put ($)");
    for (int i = 113; i <= 117; i++) {
        put->K = i;
        printf("\t%.4f", optionPrice(put));
    }
    printf("\n\n");

    put->K = 115;

    printf("T (année)\t1.8\t1.9\t2\t2.1\t2.2\n");
    printf("Prix Put ($)");
    for (double i = 1.8; i <= 2.2; i += 0.1) {
        put->T = i;
        // printf("%f\n", call->T);
        printf("\t%.4f", optionPrice(put));
    }
    printf("\n\n");

    InsuredClient *client = malloc(sizeof(InsuredClient));
    client->m = 1;
    client->s = 1;
    
    printf("x\t\t0\t1\t2\t3\n");
    printf("clientPDF_X1X2");
    for (int i = 0; i <= 3; i++) {
        printf("\t%.4f", clientPDF_X1X2(client, i));
    }
    printf("\nclientCDF_X1X2");
    for (int i = 0; i <= 3; i++) {
        printf("\t%.4f", clientCDF_X1X2(client, i));
    }
    printf("\n\n");

    client->p = malloc(3 * sizeof(double));
    client->p[0] = 0.9;
    client->p[1] = 0.05;
    client->p[2] = 0.05;

    printf("x\t\t0\t1\t2\t3\n");
    printf("clientCDF_S");
    for (int i = 0; i <= 3; i++) {
        printf("\t%.4f", clientCDF_S(client, i));
    }
    printf("\n\n");

    free(client->p);
    free(client);
    free(call);
    free(put);

    return 0;
}
