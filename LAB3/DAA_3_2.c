#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return 0;
}

int main() {
    int choice, n, i, comparisons = 0;
    int *arr, *sorted_arr;
    FILE *in_file, *out_file;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    do {
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                in_file = fopen("inAsce.dat", "r");
                out_file = fopen("outInsAsce.dat", "w");
                break;
            case 2:
                in_file = fopen("inDesc.dat", "r");
                out_file = fopen("outInsDesc.dat", "w");
                break;
            case 3:
                in_file = fopen("inRand.dat", "r");
                out_file = fopen("outInsRand.dat", "w");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                continue;
        }

        fscanf(in_file, "%d", &n);
        arr = (int *)malloc(n * sizeof(int));
        sorted_arr = (int *)malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            fscanf(in_file, "%d", &arr[i]);
        }

        printf("Before Sorting:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        insertion_sort(arr, n);

        for (i = 0; i < n; i++) {
            sorted_arr[i] = arr[i];
        }

        fprintf(out_file, "%d\n", n);
        for (i = 0; i < n; i++) {
            fprintf(out_file, "%d ", sorted_arr[i]);
        }
        fprintf(out_file, "\n");

        comparisons = n - 1;
        printf("After Sorting:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", sorted_arr[i]);
        }
        printf("\n");
        printf("Number of Comparisons: %d\n", comparisons);
        if (comparisons == 0) {
            printf("Scenario: Best Case\n");
        } else if (comparisons == n * (n - 1) / 2) {
            printf("Scenario: Worst Case\n");
        } else {
            printf("Scenario: General Case\n");
        }

        free(arr);
        free(sorted_arr);
        fclose(in_file);
        fclose(out_file);
    } while (choice != 4);

    return 0;
}

