#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float mean = 0.5;

// Define the transformation function for exponential distribution
float exponential_distribution(float x) {
    return -mean * log(1 - x);
}

int main() {
    float x;
    FILE* fp;

    // Open the file for writing
    fp = fopen("Q_4_Exponential_Numbers.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate and transform random numbers
    printf("Random Numbers in exponential Distribution are:\n");
    for (int i = 0; i < 10000; i++) {
        // Generate a uniform random number between 0 and 1
        x = (float)rand() / RAND_MAX;

        // Transform the uniform random number to an exponential random number
        float exponential_number = exponential_distribution(x);

        // Write the exponential random number to the file
        fprintf(fp, "%f\n", exponential_number);

        // Print the exponential random number to the console
        printf("%f\n", exponential_number);
    }

    // Close the file
    fclose(fp);

    return 0;
}
