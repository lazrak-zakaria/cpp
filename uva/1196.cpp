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
#include <limits.h>
using namespace std;

int memo[10001];

int LIS(int i, vector<pair<int ,int> > &v)
{
    int &ans = memo[i];
    if (ans != -1)
        return ans;
    ans = 1;
    for (int j = 0; j < i; ++j)
        if (v[j].second <= v[i].second) 
            ans = max(ans, LIS(j, v) + 1);
    return ans;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (!n)
            break;
        vector<pair<int, int> > vec (n);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < n; ++i)
        {
            int l,m;
            scanf("%d%d", &l, &m);
            vec[i] = make_pair(l,m);
        }
        sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int , int > &b){
            if (a.first == b.first)
                return a.second < b.second;

            return (a.first < b.first);
        });
        vec.push_back({INT_MAX,INT_MAX});

        printf("%d\n", LIS(n, vec) - 1);

    }
    printf("*\n");
}