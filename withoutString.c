/*
Given two strings, base and remove, return a version of the base string where all instances of the remove string have been removed (not case sensitive). You may assume that the remove string is length 1 or more. Remove only non-overlapping instances, so with "xxx" removing "xx" leaves "x".
*/

#include<stdio.h>
#include<string.h>

int main(void){
    char s[]= "Hello there";
    char r[]= "l";
    char *t= r;

    for(int i=0; *(s+i); i++){
        if(*(s+i) == *t) t++;
        
        if(!*t){
            int moveBack= strlen(r);
            int j= i+1;
            for(;*(s+j); j++){
                s[j-moveBack] = s[j];
            }
            s[j-moveBack]= '\0';
            t = r;
            i= i-moveBack;
        } 
    }
    printf("%s\n", s);
    return 0;
}