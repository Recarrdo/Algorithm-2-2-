/*
input
rabbbit

banana

babgbag

result

3
3
5
*/

#define _CRT_SECURE_NO_WARNINGS

//------------------------------------------>Download header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //------------------------------------------> valuable
    char str1[10], str2[10]; //input string array
    int lenS, lenT; //Length of S & T
    int DP[100][100]; //DP table

    
    //------------------------------------------> Input Strings
    printf("Input: S: ");
    scanf("%s", str1);

    printf("       T: ");
    scanf("%s", str2);    
    
    //------------------------------------------> Checking lengh of S & T strings
    lenS = strlen(str2);
    lenT = strlen(str1);


    //------------------------------------------> Set basic value of Dp table
    for (int i = 0; i < lenS + 1; i++)
     {
        for (int j = 0; j < lenT + 1; j++)
        {
            DP[i][j] = 0;
        }
     }
            
    //------------------------------------------> making Dp table
    for (int i = 1; i < lenS + 1; i++)
    {
        for (int j = 1; j < lenT + 1; j++)
        {
            if (i == 1)
                if (str2[i - 1] == str1[j - 1])
                    DP[i][j] = DP[i][j - 1] + 1;

                else
                    DP[i][j] = DP[i][j - 1];

            else if (str2[i - 1] == str1[j - 1] && str2[i - 1] != '\0')
                DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];

            else
                DP[i][j] = DP[i][j - 1];
        }

    }

    //------------------------------------------> Print result
    printf("Output: %d", DP[lenS][lenT]);

    return 0;
}