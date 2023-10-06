#include "equations.h"


double calculate_newtons_2nd_law(double mass, double acceleration) {
    return mass * acceleration;
}


double calculate_volume_cylinder(double radius, double height) {
    return PI * radius * radius * height;
}


char perform_character_encoding(char plaintext_character) {
    if (plaintext_character >= 'a' && plaintext_character <= 'z') {
        return (char)(plaintext_character - 'a' + 'A');
    }
    return plaintext_character; 
}


double calculate_gravity(double mass1, double mass2, double distance) {
    return (G * mass1 * mass2) / (distance * distance);
}


double calculate_resistive_divider(double r1, double r2, double vin) {
    return (r2 / (r1 + r2)) * vin;
}


double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


double calculate_general_equation(double x, double z, int a) {
    return (73.0 / 12.0) - x * z + (double)a / (a % 2);
}

