#include <stdio.h>

void prefixSum(int arr[], int n, int prefixSum[]) {
  prefixSum[0] = arr[0];
  
  for(int i=1; i<n; i++) {
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }
}

int main() {
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int prefixSum1[n];
    
    prefixSum(arr, n, prefixSum1);
    
    for(int i=0; i<n; i++) {
        printf("%d ", prefixSum1[i]); 
    }
    
    return 0;
}
