/*
Your input is a compressed string of the format number[string] and the decompressed output form should be the string written number times. For example:

The input 3[abc]4[ab]c would be output as abcabcabcababababc
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * getString(){
    int size = 10;
    char * m = malloc(size*sizeof(char));
    for(int i=0; i < size; i++) *(m+i) = 0;
    
    char c; int i = 0;
    scanf("%c", &c);
    for(i; c != '\n' && c != ' '; ++i){
        *(m+i) = c;
        scanf("%c", &c);
        if(i + 2 == size) m = realloc(m, (size*=2)*sizeof(char)); // 2 to make sure there is later space for '\0' . alternatively, realloc again later
    }
    *(m+i) = '\0';

    return realloc(m, (i+2)*sizeof(char));
}

char * insertString(char * a, int n1, char * s, int n2){


    return a;
}

char * decompression (char * a, int len){
    char * outstr;
    int outlen = 0, number = 0, tempstr = 0; //length of output string
    for(int j = 0; j < len; j++){
        if(*(i+j) <= '9' && *(i+j) >= '0'){
            number *= 10; 
            number += (*(i+j) - '0');
        } else if (*(i+j) == '[') {
            
        } else if (*(i+j) == '[') {
            
        } else {

        }
    }
    return outstr;
}


int main (void){
    char * i; //better way to initialize? yes, create a function
    i = getString();
    int len = (int) strlen(i);
    printf("%s %d", i, len);
    char * o = decompression(i, len);
    printf("%s", o);
    free(i);
    free(o);
    return 0;
}