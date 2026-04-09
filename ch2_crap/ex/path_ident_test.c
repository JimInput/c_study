#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// test that sin2(x) + cos2(x) = 1 for all x real (or on 0...2pi)

int main(void) {
    double x;
    double sin2, cos2, result;
    double step_size = 0.01;
    double end = 2.0 * M_PI;

    for (x = 0.0; x <= end; x+=step_size) {
        sin2 = pow(sin(x), 2);
        cos2 = pow(cos(x), 2);
        result = sin2 + cos2;
        printf("%lf + %lf = %lf\n", sin2, cos2, result);
    }
    return 0;
}