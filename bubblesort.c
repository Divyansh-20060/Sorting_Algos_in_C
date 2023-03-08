#include <stdio.h>

void compare_swap(int* i1, int* i2){
    if(*i1 > *i2){
        int temp = *i1;
        *i1 = *i2;
        *i2 = temp;
    }
}

void bubble_sort(int array[], int size){

    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            compare_swap(&array[j],&array[j+1]);
        }
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

    bubble_sort(array,size);
    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}