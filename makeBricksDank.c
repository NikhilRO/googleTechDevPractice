/* 
We want to make a row of bricks that is goal inches long. We have a number of small bricks (1 inch each) and big bricks (5 inches each). Return true if it is possible to make the goal by choosing from the given bricks. This is a little harder than it looks and can be done without any loops. See also: Introduction to MakeBricks. 

Except, now you have n bricks.
*/

#include <stdio.h>

// s= source, t = target
int * duplicateArray(int * s, n){
    int *t = malloc(n*sizeof(int));
    while(n--) *(t+n) = *(s+n);
    return t;
}

// bn = # of each brick, bs = size of bricks, n= number of different types of brick = array length of bs and bn
int makeBricks(int *bn, int *bs, int n, int goal){
    if(goal == 0) return 1;

    for(int i=0; i < n; i++){
        int * d = duplicateArray(bn);
        if(d[i] != 0){
            d[i]--;
            return makeBricks(bs, d, n, goal - bs[i]);
        }
        free(d);
    }
    free(bn);
    return 0;
}

int main(void){
    int bn[] = {2, 1, 1};
    int bs[] = {1, 2, 5};
    int n = 3;
    int goal = 8;
    printf("%d\n", makeBricks(duplicateArray(bn), bs, n, goal));
    return 0;
}
