#include<stdio.h>

int BinarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}
 
int main(){
    int arr[] = {1,35,52,56,644,73,1203,225,44};
    int size = sizeof(arr)/sizeof(int);
    int element = 35; // Write the element which you want to search
    int searchIndex = BinarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}
