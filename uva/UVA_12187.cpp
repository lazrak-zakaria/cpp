
#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <cstring>

using namespace std;

bool input(int *n, int *r, int *c, int *k)
{
    scanf("%d", n);
    scanf("%d", r);
    scanf("%d", c);
    scanf("%d", k);
    

    if (*r == 0 && *n == 0 && *c == 0 && *k == 0)
        return 0;
    return 1;
}


int main()
{
    int  n , r , c, k;
    int h = 4;
    while (input(&n, &r, &c, &k))
    {    
        // cout << n  << ' ' << r  << ' ' << c  << ' ' << k  << '\n' ;
        // h--;
        // if (!h )exit(1);
        int a[100][100];
        int b[100][100];
        for (int i= 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                scanf("%d", &a[i][j]);
                b[i][j] = a[i][j];
            }
        }
        n--;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (k--)
        {
            for (int i= 0; i < r; ++i)
            {


                for (int j = 0; j < c; ++j)
                {

                    for (int x = 0; x < 4; ++x)
                    {
                        if (i + dr[x] < 0 || i + dr[x] >=  r)
                            continue;
                        if (j + dc[x] < 0 || j + dc[x] >= c)
                            continue;
                        // cout << a[i + dr[x]][j + dc[x]] << "----" << a[i][j] << "\n";

                        if (a[i][j] == n && a[i + dr[x]][j + dc[x]] == 0)
                            b[i + dr[x]][j + dc[x]] = a[i][j];
                        else if (a[i + dr[x]][j + dc[x]] == a[i][j] + 1)
                            b[i + dr[x]][j + dc[x]] = a[i][j];
                    }

                }
            }
            memcpy(a, b, sizeof(a));


        }
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    printf("%d", a[i][j]);
                    if (j != c - 1)
                        printf (" ");
                }
                printf ("\n");
            }
            // printf ("\n");


    }


    return 0;
}

// 0 1 2 0
// 1 0 2 0
// 0 1 2 0
// 0 1 2 2



