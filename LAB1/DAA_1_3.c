#include<stdio.h>
void prob(int arr[], int n)
{
    int totdup=0;
    int mostrepeating=arr[0];
    int maxcount=1;
    for(int i=0;i<n;i++)
    {
        int currentcount=1;
        for(int j=j+1;j<n;j++){
        if(arr[i]==arr[j]){
            totdup++;
            currentcount++;
        }
    }
    if(currentcount>maxcount){
        maxcount=currentcount;
        mostrepeating=arr[i];
    }
}
printf("no of dup - %d\n", maxcount);
printf("most repeating ele - %d", mostrepeating);
}
int main()
{
    int n;
printf("Enter number of  element:");
    scanf("%d", &n);
printf("Enter %d value:",n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);

    }
    prob(arr,n);
    return 0;
}
