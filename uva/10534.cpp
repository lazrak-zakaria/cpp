
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


void LIS(vector<int> &v, vector<int> &ans)
{

    int k = 0;
    vector<int> ls (v.size());
    for (int i = 0; i < v.size(); ++i)
    {
        int pos = lower_bound(ls.begin(), ls.begin() + k, v[i]) - ls.begin();
        
        ls[pos] = v[i];
        if (pos == k)
            k++;
        ans[i] = pos + 1;
    }
}

void LDS(vector<int> &v, vector<int> &ans)
{

    int k = 0;
    vector<int> ls (v.size());
    for (int i = v.size()-1; i > -1; --i)
    {
        int pos = lower_bound(ls.begin(), ls.begin() + k, v[i]) - ls.begin();
        
        ls[pos] = v[i];
        if (pos == k)
            k++;
        ans[i] = pos+1;
    }
    
}


int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        vector<int> data(n);
        for (int i = 0; i < n; ++i)
        {
            int d;
            scanf("%d", &d);
            data[i] = d;
        }
        vector<int> ls(n);
        vector<int> ld(n);

        LIS(data, ls);
        LDS(data, ld);

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ls[i] <= ld[i])
                ans = max(ans, (ls[i]-1)*2 + 1);
            else
                ans = max(ans, (ld[i]-1)*2 + 1);
        }
        printf("%d\n", ans);

    }
}