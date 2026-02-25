/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double f(double x) {
    return x;
}

double error(double expected_result, double calculated_result) {
    return fabs(expected_result - calculated_result);
}

int main()
{
    int intervals = 10;
    double a = 0.0;
    double b = 1.0;
    double expected_result = 0.5;
    double result;
    QuadFormula *qf = malloc(sizeof(QuadFormula));
    printf("Function : x -> x\tInterval : [%.2f, %.2f]\n", a, b);
    printf("Expected result : %f\n", expected_result);
    printf("Number of subdivisions : %d\n", intervals);

    setQuadFormula(qf, "left");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    setQuadFormula(qf, "right");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    setQuadFormula(qf, "middle");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    setQuadFormula(qf, "trapezes");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    setQuadFormula(qf, "simpson");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    setQuadFormula(qf, "gauss2");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    setQuadFormula(qf, "gauss3");
    // printQuadFormula(qf);
    result = integrate(f, a, b, intervals, qf);
    printf("Calculated result : %f\t Error : %f\n", result, error(expected_result, result));
    return 0;
}
