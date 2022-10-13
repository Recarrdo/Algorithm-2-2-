
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct city
{
    char name[100];
    int position;
};

struct edge
{
    int start, end;
    int time;
};
int findPosition(struct city*, char*);

int main()
{
    int N, size, cases, nt, te, nowtime, freP;
    int pretime = 0, nowP = 0, allsize = 0;
    char fre[100], now[100];

    scanf("%d", &N);

    struct city* city;
    struct edge* edge;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &size);

        city = (struct city*)malloc(sizeof(struct city) * size);

        for (int i = 0; i < N; i++)
        {
            scanf("%s", &(city[i].name));
            city[i].position = i;
        }

        scanf("%d", &size);

        size = allsize;

        edge = (struct edge*)malloc(sizeof(struct edge) * allsize);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &cases);

            for (int j = 0; j < cases; j++)
            {
                scanf("%d %s", &nt, now);

                nowtime = pretime;
                freP = nowP;
                nowP = findPosition(city, now);
                nowtime = (nt / 100) * 60 + nt % 100;
            }
        }
    }
}
int findPosition(struct city* city, char* name)
{
    int size = sizeof(city) / sizeof(struct city), i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(city[i].name, name) == 0)
            return i;
    }
}
