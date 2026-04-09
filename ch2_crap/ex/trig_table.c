#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define NSTEPS 20

int main(void) {

    int n = 1;
    double x;
    double end = 2.0 * M_PI;
    double step_size = end / (NSTEPS-1);
    
    printf("%-9s %-9s %-9s %-9s %-9s\n%9s %9s %9s %9s %9s\n",
        "n", "x", "sin(x)", "cos(x)", "tan(x)",
        "---------", "---------", "---------", "---------", "---------");
        
    for (x = 0.0; x <= end; x += step_size) {
        printf("%-9d %-9f %-9f %-9f %-9f\n",
            n, x, sin(x), cos(x), tan(x));
            ++n;
    }
    

    return 0;
}