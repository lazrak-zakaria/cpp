
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
using namespace std;


typedef struct hum
{
    int me;
    int angry = 0;
} hum;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        int p, c;
        scanf("%d%d", &p, &c);
        vector<int> pr;
        vector<int> cs;
        
        for (int i = 0; i < p; ++i)
        {
            int in;
            scanf("%d", &in);
            pr.push_back(in);


        }
        // cout << "\n";

        for (int i = 0; i < c; ++i)
        {
            int in;
            scanf("%d", &in);
            cs.push_back(in);
            // printf("%d ", in);

        }

        if (!p)
        {
            getchar();
            pr.push_back(0);
            p = 1;
        }
        if (!c)
            getchar();


        vector<int> pp = pr;
        vector<int> cc = cs;

        sort(pr.begin(), pr.end());
        sort(cs.begin(), cs.end());


        vector<hum> ans(p+c);
        int i = 0;
        for ( ; i < p; ++i)
        {
            int pAngry = pr.end() - upper_bound(pr.begin() + i, pr.end(), pr[i]);
            int cAngry = lower_bound(cs.begin(), cs.end(), pr[i]) - cs.begin();
            ans[i].me = pr[i];
            ans[i].angry = pAngry + cAngry;
        
        }

        for ( int j = 0; j < c; ++j)
        {
            int pAngry = pr.end() - upper_bound(pr.begin(), pr.end(), cs[j]);
            int cAngry = lower_bound(cs.begin(), cs.end(), cs[j]) - cs.begin(); 
            ans[i + j].me = cs[j];
            ans[i + j].angry = pAngry + cAngry;
        }

        int price = 0, angry = p;


        for (i = 0; i < p + c; ++i)
        {
            if ((ans[i].angry < angry)
                || (ans[i].angry == angry && ans[i].me < price))
            {
                price = ans[i].me;
                angry = ans[i].angry;
            }
        }



        printf("%d %d\n", price, angry);

    }
}