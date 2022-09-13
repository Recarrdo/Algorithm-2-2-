//When executing the EXE file, execute it through cmd.

#define _crt_secure_no_warnings
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;
#define size 1100


//define struct------------------------------------------
struct nodes 
{
    int w, ele_IQ, in; //w is elephant's weight and ele_IQ is elephant's IQ, in is index
}arr[size];

int n, dp[size], path[size]; //dp is dp table
int top, result[size];



//define sort method------------------------------------------
int cmp(nodes a, nodes b) 
{

    if (a.w == b.w)
        return a.ele_IQ > b.ele_IQ;

    else return a.w < b.w;
}



//main-------------------------------------------------------------
int main()
{
    int i, j, k, maxL, maxi;
    top = n = 1;
    maxL = maxi = 0;
    arr[0].w = 0, arr[0].ele_IQ = 20000;


    //input----------------------------------------------------
    while (scanf_s("%d%d", &arr[n].w, &arr[n].ele_IQ) != EOF)
    {
       arr[n].in = n, n++;
    }
       

    //define sort method-----------------------------------------------------
    sort(arr + 1, arr + n, cmp); 
    

    //LCS------------------------------------------------------
    for (i = 1; i < n; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            if (arr[i].ele_IQ < arr[j].ele_IQ && dp[i] < dp[j] + 1 && arr[i].w > arr[j].w)
            {
                dp[i] = dp[j] + 1;
                path[i] = j;

                //save the result
                if (dp[i] > maxL) 
                    maxL = dp[i], maxi = i;
            }
        }
    }


    //print result---------------------------------------------
    printf("%d \n",maxL);

        while (maxi != 0) 
        {
            result[top++] = maxi;
            maxi = path[maxi];
        }

    for (i = top - 1; i >= 1; --i)
        printf("%d ",arr[result[i]].in);
}
