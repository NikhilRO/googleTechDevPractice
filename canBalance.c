/*
Given a non-empty array, return true if there is a place to split the array so that the sum of the numbers on one side is equal to the sum of the numbers on the other side.
*/

#include <stdio.h>
int isBalanced(int a[], int n){
    int sum = 0, forwardSum= 0; 

    for(int i=0; i < n; i++) sum += a[i];

    for(int i=0; i < n; i++){
        forwardSum += a[i];
        if(forwardSum == sum - forwardSum) return 1;
    }
    return 0;
}

int main(void){
    int array[] = {1, 1, 1, 2, 1};

    printf("%d\n", isBalanced(array,5));

    return 0;
}