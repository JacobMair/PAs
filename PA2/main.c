#include <stdio.h>
#include "equations.h"

int main() {
    double result;
    char char_result;
    double mass, acceleration, radius, height, r1, r2, vin, x1, y1, x2, y2, x, z;
    int a;

    printf("Enter mass and acceleration for Newton's Second Law: ");
    scanf("%lf %lf", &mass, &acceleration);

   
    result = calculate_newtons_2nd_law(mass, acceleration);
    printf("Result: %.2lf\n", result);

    
    printf("Enter radius and height for Volume of a Cylinder: ");
    scanf("%lf %lf", &radius, &height);
    result = calculate_volume_cylinder(radius, height);
    printf("Result: %.2lf\n", result);

  

    return 0;
}
