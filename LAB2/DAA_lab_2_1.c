#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, FILE *outputFile) {
    if (decimal > 0) {
        decimalToBinary(decimal / 2, outputFile);
        fprintf(outputFile, "%d", decimal % 2);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid value for 'n'. It should be a positive integer.\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[2], "r");
    FILE *outputFile = fopen(argv[3], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int decimalNum;
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &decimalNum) != 1) {
            printf("Error reading from the input file.\n");
            break;
        }
        fprintf(outputFile, "The binary equivalent of %d is ", decimalNum);
        decimalToBinary(decimalNum, outputFile);
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
