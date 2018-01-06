/*
Write a function that replaces the words in `raw` with the words in `code_words` such that the first occurrence of each word in `raw` is assigned the first unassigned word in `code_words`.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char **encode(char ** r, char ** c, int n){
    char **ans = malloc(sizeof(int)*(2*n));
    for(int i=0; i < n; i++) ans[i] = "0";    

    int index=0;
    for(int i=0; i < n; i++){
       if(ans[i] == "0"){
           for(int j=i; j < n; j++) if(!strcmp(r[j], r[i])) ans[j] = c[index];
           index++;
       }
    }

    return ans;
}

int main (void){
    int n = 10;
    char* raw[]= {"a", "b", "a", "c", "d", "d", "l", "c", "b", "b"};
    char* code[]= {"1", "2", "3", "4", "5", "6", "7"};

    char ** ans = encode(raw, code, n);
    for(int i = 0; i < n; i++) printf("%s ,", ans[i]);
    free(ans);
    return 0;
}