#include<stdio.h>
int BinarySearch(int * array, int low, int high, int target);

int main()
{
    int n;
    scanf("%d",&n);
    int z =(n/10)+1;
    int tf[z];
    int x;
    for(x=0;x<z;x++){
        scanf("%c",&tf[x]);
    }
    int swas=0;
    int low =0 ,high =n-1;
    int c = BinarySearch(tf,low,high,84);
    while(BinarySearch(tf,low,high,84)){swas++;
    printf("Alarm turned on after %d minutes",swas);}
    if(!swas){ printf("The alarm never turned on");}
    return 0;
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
