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

    int m;
    for(int i = 1; i < n; i++){
        if(a[1] < a[i])
    }

    quicksort(a, m);
    quicksort(a+m+1, n-m )
}

int main(void){

    return 0;
}