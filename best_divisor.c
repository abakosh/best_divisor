/* This is a simple code to find the best ratio you can get of 
 *  two integers to acheive a specific ratio.
 *  a/b = closest number to the defined number MY_NUMBER
 *  a and b are limited between 1 and 255 , you can adjust the 
 *  for loop value if you want to change the pool for a and b
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MY_NUMBER   0.7321f /* any ratio you want to acheive in float or integer format */

int main(int argc, char **argv)
{
    double mynum = MY_NUMBER;
    char * ptr;
    if(argc == 1)
    {
        /* No parameters were passed, continue with  MY_NUMBER*/
    }
    else if (argc == 2)
    {
        strtod(argv[1], &ptr);
        if( *ptr != 0 )
        {
            printf("The argument is not a number");
            exit(1);
        }
        mynum = strtod(argv[1], &ptr);
    }
    else
    {
        printf("too many arguments, run with no args or with the number you want\n");
        exit(1);
    }
    double ab;
    double best_a = 1.0;
    double best_b = 1.0;
    double best  = 1.0;
    
    for(int a =1;a<256;a++)
    {
        for(int b =1;b<256;b++)
        {
            ab = (double)a/(double)b;
            if(fabs(mynum-ab)< fabs(mynum-best))
            {
                best = ab;
                best_a = a;
                best_b = b;
            }
        }
    }
    printf("a=%.1f,b=%.1f,val=%.4f\n",best_a,best_b,best);

    return 0;
}
