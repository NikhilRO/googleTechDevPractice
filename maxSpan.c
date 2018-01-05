/* 
Consider the leftmost and righmost appearances of some value in an array. We'll say that the "span" is the number of elements between the two inclusive. A single value has a span of 1. Returns the largest span found in the given array. (Efficiency is not a priority.)
*/

#include<stdio.h>

int maxSpan(int array[], int n){
    if(n <= 0) return 0;
    int span = 0, maxSpan = 0;
    for(int i =0; i< n; i++){
        for(int j= n-1; j > i; j--){
            if(array[j] == array[i]){
                span = j - i + 1; 
                break;
            }
        }
        if(span > maxSpan) maxSpan = span;
    }
    return maxSpan;
}

int main(void){
    int array[]= {1, 2, 1, 1, 3};
    printf("%d\n", maxSpan(array, 5));
    return 0;
}
