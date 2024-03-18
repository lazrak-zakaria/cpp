
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
#include <limits.h>
#include <sstream>

using namespace std;


int main()
{
    int y = 3;
    std::string in;

    while (getline(cin , in))
    {
        if (in == "")
            continue;


        stringstream ss(in);

        
        int n;
        int m;
        int h ;
        ss >> n;

        vector<int> data(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &h);
            data[i] = h;
        }
        scanf("%d", &m);
        sort(data.begin(), data.end());
        vector<int>::iterator it;
        pair<int, int> ans = make_pair(0, INT_MAX);
        for (int i = 0; i < n; ++i)
        {
            int val = m - data[i];
            if (data[i] > m || val < data[i])
                break;
            
            if (val - m < ans.second - ans.first)
            {
                it = lower_bound(data.begin() + i + 1, data.end(), val);
                if (it != data.end() && *it == val)
                    ans.first = data[i], ans.second = val;
            }
        }
        printf("%s%d%s%d%s","Peter should buy books whose prices are " ,ans.first , " and " , ans.second , ".\n");
        printf("\n");

    }
}