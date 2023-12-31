#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define G 6.67e-11

double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character);
double calculate_gravity(double mass1, double mass2, double distance);
double calculate_resistive_divider(double r1, double r2, double vin);
double calculate_distance(double x1, double y1, double x2, double y2);
double calculate_general_equation(double x, double z, int a);

#endif
