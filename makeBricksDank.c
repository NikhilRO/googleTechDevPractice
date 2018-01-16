/* 
We want to make a row of bricks that is goal inches long. We have a number of small bricks (1 inch each) and big bricks (5 inches each). Return true if it is possible to make the goal by choosing from the given bricks. This is a little harder than it looks and can be done without any loops. See also: Introduction to MakeBricks. 

Except, now you have n bricks.
*/

#include <stdio.h>

// bn = # of each brick, bs = size of bricks, n= number of different types of brick = array length of bs and bn
int makeBricks(int *bn, int *bs, int n, int goal){
    if(goal == 0) return 1;
    for(int i=0; i < n; i++){
        if(bs[i] == 0) return makeBricks(bs, bn, n, goal);
    }
    if(small == 0 && big == 0) return 0;
    if(small == 0) return makeBricks(small, big-1, goal-5);
    if(big == 0) return makeBricks(small-1, big, goal-1);
    return  makeBricks(small-1,big,goal-1) ? 1 : (makeBricks(small,big-1, goal-5) ? 1 : 0);
}

int main(void){
    int bn[] = {};
    int bs[] = {};
    int n = ;
    int goal = ;
    printf("%d\n", makeBricks(bn, bs, n, goal));
    return 0;
}
