/* 
Return an array that contains the sorted values from the input array with duplicates removed.
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int a[], int n){
    if(n <= 1) return;

    int m =0;
    for(int i = 1; i < n; i++){
        if(a[0] >= a[i]){
            m++;
            swap(a+i, a+m);
        } 
    }
    swap(a, a+m);
    quicksort(a, m);
    quicksort(a+m+1, n-m-1);
}

void mergesort(int a[], int n){
    if (n <= 1) return;
    mergesort(a, n/2);
    mergesort(a+n/2, n-n/2);

    int i=0, j=0;
    while(i < n/2 && j < n-n/2){
        if(*(a+i) < *(a+n/2+))
    }
}

int main(void){
    int array[]= {2,2,3,3,7, 1, -8, 9, 0};
    int size= sizeof(array)/sizeof(int);
    quicksort(array, size);
    for(int i=0; i < size; i++) printf("%d \t", a[i]);
    return 0;
}