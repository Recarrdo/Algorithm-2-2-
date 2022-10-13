/*
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

#include <stdio.h>
#include <math.h>


float x[SIZE], y[SIZE]; //Array to store x and y coordinates
int base[SIZE]; //calculation table

int main()
{
    int count = 1;
    int minp; //Store minimum point
    int cycle; //The value that determines how many turns is stored
    float disx, disy; //distance between x points and distance between y points
    float edge, min; // weight(가중치) and min vaule
    float result = 0; //result
    base[0] = 1;

    scanf("%d", &cycle); //Enter the number of turns

    for (int i = 0; i < cycle; i++) //Code to input x,y coordinates
    {
        scanf("%f %f", &x[i], &y[i]);
    }
 
    while (count < cycle) //prim's algorithm
    {
        min = -1.0; //Minimum Initialization

        for (int i = 0; i < cycle; i++)
        {
            if (base[i])
            {
                for (int j = 0; j < cycle; j++)
                {
                    if (!base[j])
                    {
                        disx = x[i] - x[j];
                        disy = y[i] - y[j];
                        edge = sqrt(disx * disx + disy * disy);

                        if (edge < min || min == -1.0)
                        {
                            minp = j;
                            min = edge;
                        }
                    }
                }
            }
        }

        result += min;
        base[minp] = 1;
        count++;
    }

    printf("%.2f \n", result); //print result

    return 0;
}

*/