#include<stdio.h>
int LinearSearch(int * array, int low, int high, int target);
int BinarySearch(int * array, int low, int high, int target);
void sortthearaay(int* array,int n);
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int array[n];
    int low = 0;
    int high =n-1;
    int i =0;
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    sortthearaay(array,n);
    if((BinarySearch(array,low,high,k))&&(LinearSearch(array,low,high,k))){
        printf("Found");
    }
    else{
        printf("Not Found");
    }
    return 0;
}


void sortthearaay(int* array,int n){
    int i,j,temp;
    for(i=1;i<n;++i)

        for(j=0;j<(n-i);++j)

            if(array[j]>array[j+1]) //Bubble sort in c using array logic

            {

                temp=array[j];

                array[j]=array[j+1];

                array[j+1]=temp;

            }
}





int LinearSearch(int * array, int low, int high, int target){
    int x;
    for(x=0;x<=high;x++){
        if(array[x]==target){
            return x;
        }
    }
    return 0;
}

int BinarySearch(int * array, int low, int high, int target){
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(array[mid]==target){return mid;}
        else if(array[mid]<target){low = mid +1 ;}
        else{high = mid-1;}
    }

    return 0;
}
