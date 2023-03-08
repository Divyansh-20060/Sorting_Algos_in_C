#include <stdio.h>

void swapper(int array[], int i1, int i2){
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

int find_smallest(int low,int array[], int size){
    int smallest = array[low];
    int smallest_i = low;
    for(int i = low; i < size; i++){
        if(array[i] < smallest){
            smallest = array[i];
            smallest_i = i;
        }
    }

    return smallest_i;
}

void selectionsort(int array[], int size){
    
    int small_i = 0;

    for(int i = 0; i< size; i++){
        small_i = find_smallest(i, array,size);
        swapper(array,i,small_i);
    }
    return;
}

int main(){

    int size;

    printf("Enter Size: \n");
    scanf("%d",&size);

    int array[size];
    printf("enter elements: \n");
    for(int i = 0 ; i < size; i++){
        scanf("%d",&array[i]);
    }

    selectionsort(array,size);

    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }

    printf("\n");

    return 0;
}