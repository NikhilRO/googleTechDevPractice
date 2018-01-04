#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// For example, given the input of S = "abppplee" and D = {"able", "ale", "apple", "bale", "kangaroo"} the correct output would be "apple"

int isSubsequence(char *s, char *d){
    while(*d){
        if(!*s) return 0;
        if(*d == *s) d++;
        s++;
    }
    return 1;
}


int main(void){
    char *s= "abppplee";
    char *array[5]= {"able", "ale", "apple", "bale", "kangaroo"}; //might not be able to change it 
    int maxIndex=-1;

    for(int i = 0; i<5; i++){
        if(isSubsequence(s, array[i])){
            if(maxIndex == -1) maxIndex = i;
            if(strlen(array[maxIndex]) <= strlen(array[i])) maxIndex = i;
        }
    }
    printf("%s\n", array[maxIndex]);
    return 0;
}

