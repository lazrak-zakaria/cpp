
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
#include <sstream>
#include <bitset>

using namespace std;


int main()
{

    int n;
    scanf("%d", &n);
    while(n--)
    {
        char d[10];
        int e  = 0;
        bitset<26> s;
        while(scanf("%s", d))
        {
            if (d[0] == '*')
            {
                int co = 0;
                int all = 0;
                char dd[100];
                scanf("%s", dd);
                int i = -1;
                while (dd[++i])
                    if (dd[i] != ',')
                    {
                        if (! s.test(dd[i] - 'A'))
                            co++;
                        all++;
                    }
                printf("There are %d tree(s) and %d acorn(s).\n", all - e - co, co);
                break;
            }


            int a = d[1] - 'A';
            int b = d[3] - 'A';
            e++;
            s.set(a);
            s.set(b);
        }


    }
}