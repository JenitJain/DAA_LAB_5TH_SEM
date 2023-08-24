#include <stdio.h>

void EXCHANGE(int *p, int *q) {
  int temp = *p;
  *p = *q;
  *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
  for (int i = 0; i < p2 - 1; i++) {
    EXCHANGE(p1 + i, p1 + i + 1);
  }
}

int main() {
int n;
printf("Enter size of array");
scanf("%d",&n);
  int A[n], N;

  printf("Enter an array A of size %d: ",n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  printf("Before ROTATE: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  N = sizeof(A) / sizeof(A[0]);
  ROTATE_RIGHT(A, 5);

  printf("After ROTATE: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}

