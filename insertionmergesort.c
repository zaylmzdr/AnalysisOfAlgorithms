#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define SIZE 100

//insertion ve merge sort bir dizi üzerinde gösterilecek

void insertionSort(int A[],int N){

    int i,j,key;
    for(j = 1 ; j < N;j++){
        key = A[j];
        i = j - 1 ;
        while(i >=0  && A[i]> key){
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }


}

void merge(int A[],int p,int q,int r){

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1+1],R[n2+1];

    for(int i=0;i < n1;i++){
        L[i] = A[p + i];
    }

    for(int j=0;j < n2;j++){
        R[j] = A[q + j + 1];
    }


    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i =0,j=0,key;

    for(key = p ; key <= r;key++){
        if(L[i] <= R[j]){
            A[key] = L[i];
            i++;
        }else{
            A[key] = R[j];
            j++;
        }
    }



}

void mergeSort(int A[],int p,int r){
    if( p < r){
        int q = (r + p ) / 2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);

    }
}

int main()
{
    int i;
    int A[SIZE];




    //diziyi yazdirma
    printf("Siralanmamis dizi:\n");
    for(i =0; i < SIZE; i++){
        A[i] = rand() + 50;
        printf("%d ",A[i]);
    }
    printf("\n");

    clock_t start_time = clock();
    mergeSort(A,0,SIZE-1);
    clock_t end_time = clock();
    double merge_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Siralanmis dizi:\n");
     for(int i =0 ; i < SIZE ;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Merge sort calisma suresi: %f saniye\n",merge_time);

    return 0;
}
