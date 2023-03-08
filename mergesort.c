#include <stdio.h>
#include <stdlib.h>

void merge_swap(int low, int mid, int high, int array[]){

    int size1 = mid - low + 1;
    int size2 = high - mid;
    int size3 = size1 + size2;

    int temp1[size1];
    int temp2[size2];
    int final[size3];

    int ct1 = 0, ct2 = 0;

    for(int i = 0 ; i < size1 ; i++){
        temp1[i] = array[low + i];
    }

    for(int i = 0 ; i < size2 ; i++){
        temp2[i] = array[mid + 1 + i];
    }

    for(int i = 0; i < size3; i++){

        if(ct1 < size1 && ct2 < size2){

            if(temp1[ct1] < temp2[ct2]){
                final[i] = temp1[ct1];
                ct1++;
            }

            else{
                final[i] = temp2[ct2];
                ct2++;
            }
        }

        else if(ct1 < size1){
            final[i] = temp1[ct1];
            ct1++;
        }

        else{
            final[i] = temp2[ct2];
            ct2++;            
        }
    }

    for(int i = 0; i < size3; i++){
        array[low + i] = final[i]; 
    }
}


void merge_sort(int low, int high, int array[]){

    if(low >= high){return;}

    int mid = (low + high - 1)/2;

    merge_sort(low, mid, array);
    merge_sort(mid + 1, high,array);

    merge_swap(low,mid,high,array);


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

    merge_sort(0,size - 1,array);

    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }

    printf("\n");

    return 0;
}