#include <stdio.h>
#include "stats.h"

int main() {

    FILE *infile = fopen("input.dat", "r");
    FILE *outfile = fopen("output.dat", "w");

    if (infile == NULL || outfile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

  
    double sum_gpa = 0.0;
    int sum_class_standing = 0;
    double sum_age = 0.0;
    double max_gpa = -1.0;
    double min_gpa = 5.0;

    for (int i = 0; i < 5; i++) {
        double gpa = read_double(infile);
        int class_standing = read_integer(infile);
        double age = read_double(infile);

        sum_gpa += gpa;
        sum_class_standing += class_standing;
        sum_age += age;

        if (gpa > max_gpa) {
            max_gpa = gpa;
        }

        if (gpa < min_gpa) {
            min_gpa = gpa;
        }
    }

    // Calculate statistics
    double mean_gpa = calculate_mean(sum_gpa, 5);
    double mean_class_standing = calculate_mean(sum_class_standing, 5);
    double mean_age = calculate_mean(sum_age, 5);

    double deviation1 = calculate_deviation(read_double(infile), mean_gpa);
    double deviation2 = calculate_deviation(read_double(infile), mean_gpa);
    double deviation3 = calculate_deviation(read_double(infile), mean_gpa);
    double deviation4 = calculate_deviation(read_double(infile), mean_gpa);
    double deviation5 = calculate_deviation(read_double(infile), mean_gpa);

    double variance_gpa = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);
    double standard_deviation_gpa = calculate_standard_deviation(variance_gpa);

    fprintf(outfile, "%.2lf -- GPA Mean\n", mean_gpa);
    fprintf(outfile, "%.2lf -- Class Standing Mean\n", mean_class_standing);
    fprintf(outfile, "%.2lf -- Age Mean\n", mean_age);
    fprintf(outfile, "%.2lf -- GPA Standard Deviation\n", standard_deviation_gpa);
    fprintf(outfile, "%.2lf -- GPA Min\n", min_gpa);
    fprintf(outfile, "%.2lf -- GPA Max\n", max_gpa);

    fclose(infile);
    fclose(outfile);

    return 0;
}
