#include <stdio.h>
#include <stdlib.h>

struct item {
  int profit;
  int weight;
};

void swap(struct item *a, struct item *b) {
  struct item temp = *a;
  *a = *b;
  *b = temp;
}

int partition(struct item items[], int low, int high) {
  int pivot = items[high].profit;
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (items[j].profit >= pivot) {
      i++;
      swap(&items[i], &items[j]);
    }
  }

  swap(&items[i + 1], &items[high]);
  return i + 1;
}

void quickSort(struct item items[], int low, int high) {
  if (low < high) {
    int pi = partition(items, low, high);
    quickSort(items, low, pi - 1);
    quickSort(items, pi + 1, high);
  }
}

int fractionalKnapsack(struct item items[], int n, int capacity) {
  // Sort the items in non-increasing order of profit/weight ratio.
  quickSort(items, 0, n - 1);

  int profit = 0;
  float taken[n];
  for (int i = 0; i < n; i++) {
    if (items[i].weight <= capacity) {
      taken[i] = 1.0;
      profit += items[i].profit;
      capacity -= items[i].weight;
    } else {
      taken[i] = (float)capacity / items[i].weight;
      profit += items[i].profit * taken[i];
      break;
    }
  }

  // Print the output.
  printf("Item No\tProfit\t\tWeight\t\tAmount to be taken\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%.2f\n", i + 1, items[i].profit, items[i].weight, taken[i]);
  }

  printf("Maximum profit: %.2f\n", profit);

  return profit;
}

int main() {
  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  struct item items[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the profit and weight of item no %d: ", i + 1);
    scanf("%d %d", &items[i].profit, &items[i].weight);
  }

  int capacity;
  printf("Enter the capacity of knapsack: ");
  scanf("%d", &capacity);

  int profit = fractionalKnapsack(items, n, capacity);

  return 0;
}

