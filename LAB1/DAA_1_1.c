#include<stdio.h>
void prob(int arr[], int n){
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n;j++)
        {
            int temp;
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            
            }
        }
    }
    printf("second samllest -%d\n", arr[1]);
    printf("second largest -%d \n", arr[n-2]);
}
int main()
{
    int n;
printf("Enter number of values: ");

    scanf("%d", &n);
printf("\nEnter values:");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
        prob(arr,n);
        return 0;
    }
