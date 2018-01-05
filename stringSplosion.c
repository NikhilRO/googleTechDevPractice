//Given a non-empty string like "Code" return a string like "CCoCodCode".   

#include<stdio.h>
#include<string.h>

void print(char *s, int n){
    for(int i=0; i< n; i++) printf("%c",*(s+i));
}

int main(void){
    char test[100]; //= "Code";
    fgets(test, 100, stdin);
    int iter= strlen(test);
    for(int i=0; i<= iter; i++){
        print(test,i);
    }
    return 0;
}