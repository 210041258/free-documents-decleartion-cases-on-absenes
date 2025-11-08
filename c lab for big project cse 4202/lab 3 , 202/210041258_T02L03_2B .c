#include<stdio.h>
int BinarySearch(int * array, int low, int high, int target);
int count(int arr[], int n, int x);

int main()
{
    int n,x,i;
    scanf("%d %d",&n,&x);
    int array[n];
    if(((1<=n)&&(n<=100000))&&((1<=x)&&(x<=(100000))))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&array[i]);
            if(!((1<=array[i])&&(array[i]<=(100000))))
            {
                return 0;
            }
        }
    }
    int low=0,high =n-1 ;
    int sum ;
    sum = count(array,n,x);
    printf("%d",sum);
    return 0;
}


int count(int arr[], int n, int x)
{
    int ind = BinarySearch(arr,0, n - 1, x);

    // If element is not present
    if (ind == -1)
        return 0;

    // Count elements on left side.
    int sum = 1;
    int low = ind - 1;
    while (low >= 0 && arr[low] == x)
        sum++, low--;

    // Count elements on right side.
    int high = ind + 1;
    while (high < n && arr[high] == x)
        sum++, high++;

    return sum;
}



int BinarySearch(int * array, int low, int high, int target)
{
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(array[mid]==target)
        {
            return mid;
        }
        else if(array[mid]<target)
        {
            low = mid +1 ;
        }
        else
        {
            high = mid-1;
        }
    }
    return 0;
}
