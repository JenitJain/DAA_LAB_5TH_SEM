#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
  int id;
  char *name;
  int age;
  int height;
  int weight;
};

void read_data(struct person *people, int n) {
  for (int i = 0; i < n; i++) {
    printf("Id: ");
    scanf("%d", &people[i].id);
    printf("Name: ");
    scanf("%s", people[i].name);
    printf("Age: ");
    scanf("%d", &people[i].age);
    printf("Height: ");
    scanf("%d", &people[i].height);
    printf("Weight(pound): ");
    scanf("%d", &people[i].weight);
  }
}

void min_heapify(struct person *people, int i, int n) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && people[left].age < people[smallest].age) {
    smallest = left;
  }

  if (right < n && people[right].age < people[smallest].age) {
    smallest = right;
  }

  if (smallest != i) {
    struct person temp = people[i];
    people[i] = people[smallest];
    people[smallest] = temp;

    min_heapify(people, smallest, n);
  }
}

void build_min_heap(struct person *people, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    min_heapify(people, i, n);
  }
}

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct person *people = malloc(sizeof(struct person) * n);

  read_data(people, n);

  build_min_heap(people, n);

  int choice;
  while (1) {
    printf("\nMAIN MENU (HEAP)\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on the age\n");
    printf("3. Create a Max-heap based on the weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Insert a new person into the Min-heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        read_data(people, n);
        break;
      case 2:
        build_min_heap(people, n);
        break;
      case 3:
        // Not implemented
        break;
      case 4:
        printf("Weight of the youngest student: %d\n", people[0].weight);
        break;
      case 5:
        // Not implemented
        break;
      case 6:
        // Not implemented
        break;
      case 7:
        exit(0);
      default:
        printf("Invalid choice!\n");
        break;
    }
  }

  free(people);

  return 0;
}

