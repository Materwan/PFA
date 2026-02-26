#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
    strcpy(qf->name, name);
    qf->wk = malloc(3 * sizeof(float));
    qf->xk = malloc(3 * sizeof(float));
    if (strcmp(name, "left") == 0) {
        qf->n = 0;
        qf->xk[0] = 0.0;
        qf->wk[0] = 1.0;
    } else if (strcmp(name, "right") == 0) {
        qf->n = 0;
        qf->xk[0] = 1.0;
        qf->wk[0] = 1.0;
    } else if (strcmp(name, "middle") == 0) {
        qf->n = 0;
        qf->xk[0] = 0.5;
        qf->wk[0] = 1.0;
    } else if (strcmp(name, "trapezes") == 0) {
        qf->n = 1;
        qf->xk[0] = 0.0;
        qf->xk[1] = 1.0;
        qf->wk[0] = 0.5;
        qf->wk[1] = 0.5;
    } else if (strcmp(name, "simpson") == 0) {
        qf->n = 2;
        qf->xk[0] = 0.0;
        qf->xk[1] = 0.5;
        qf->xk[2] = 1.0;
        qf->wk[0] = 1.0 / 6.0;
        qf->wk[1] = 2.0 / 3.0;
        qf->wk[2] = 1.0 / 6.0;
    } else if (strcmp(name, "gauss2") == 0) {
        qf->n = 1;
        qf->xk[0] = 1.0 / 2.0 - 1.0 / (2.0 * sqrt(3.0));
        qf->xk[1] = 1.0 / 2.0 + 1.0 / (2.0 * sqrt(3.0));
        qf->wk[0] = 0.5;
        qf->wk[1] = 0.5;
    } else if (strcmp(name, "gauss3") == 0) {
        qf->n = 2;
        qf->xk[0] = 0.5 * (1 - sqrt(3.0 / 5.0));
        qf->xk[1] = 0.5;
        qf->xk[2] = 0.5 * (1 + sqrt(3.0 / 5.0));
        qf->wk[0] = 5.0 / 18.0;
        qf->wk[1] = 4.0 / 9.0;
        qf->wk[2] = 5.0 / 18.0;
    } else {
        return false;
    }
    return true;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
    printf("Quadratic formula: %s\n", qf->name);
    printf("n = %d\n", qf->n);
    printf("xk\twk\n");
    for (int i = 0; i <= qf->n; i++) {
        printf("%.3f\t%.3f\n", qf->xk[i], qf->wk[i]);
    }
    /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
    - f is a pointer to a function pointer
    - a and b are the integration bounds
    - Interval [a,b] is split in N subdivisions [ai,bi]
    - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
    double ai;
    double bi;
    double ratio = (b - a) / N;
    double diff;
    double res = 0.0;
    double sum;
    for (int i = 0; i < N; i++) {
        sum = 0.0;
        ai = a + i * ratio;
        bi = a + (i + 1) * ratio;
        diff = bi - ai;
        for (int j = 0; j <= qf->n; j++) {
            sum += qf->wk[j] * f(ai + qf->xk[j] * diff);
        }
        res += diff * sum;
    }
    return res;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
    int N = (int) round( fabs(b-a)/dx );
    if (N == 0) N = 1;
    return integrate(f, a, b, N, qf);
}


