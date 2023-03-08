#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int i1, int i2){
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

int partition(int array[], int low, int high){

    int piviot = array[high];
    int final_pp = low;


    for(int i = low; i <= high - 1; i++){
        if(array[i] < piviot){
            swap(array,i,final_pp);
            final_pp++;
        }
    }

    swap(array,high,final_pp);
    return final_pp;

}

void quick_sort(int low, int high, int array[]){
    if(high > low){
        int part = partition(array,low,high);
        quick_sort(low,part - 1,array);
        quick_sort(part+1,high,array);
    }   
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

    quick_sort(0,size - 1,array);
    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}