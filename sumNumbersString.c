/*
Given a string, return the sum of the numbers appearing in the string, ignoring all other characters. A number is a series of 1 or more digit chars in a row. (Note: Character.isDigit(char) tests if a char is one of the chars '0', '1', .. '9'. Integer.parseInt(string) converts a string to an int.)
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char *s= "2a12b33";
    int number = 0, sum = 0;

    for(int i=0; *(s+i); i++){ //s[i]
        // printf("%d\n", s[i]- '0');
        if(s[i] -'0' < 10){
             number *= 10;
             number += s[i] - '0';
             printf("%d\n", number);
        } else {
            sum += number;
            number = 0;
        }
    }   
    sum += number;
    number = 0;

    printf("%d\n", sum);

    return 0;
}