/* 
We want to make a row of bricks that is goal inches long. We have a number of small bricks (1 inch each) and big bricks (5 inches each). Return true if it is possible to make the goal by choosing from the given bricks. This is a little harder than it looks and can be done without any loops. See also: Introduction to MakeBricks
*/

#include <stdio.h>

int makeBricks(int small, int big, int goal){
    if(goal == 0) return 1;
    if(small == 0 && big == 0) return 0;
    if(small == 0) return makeBricks(small, big-1, goal-5);
    if(big == 0) return makeBricks(small-1, big, goal-1);
    return makeBricks(small-1,big,goal-1) ? 1 : (makeBricks(small,big-1, goal-5) ? 1 : 0);
}

int main(void){
    printf("%d\n", makeBricks(3, 1, 8));
    return 0;
}
