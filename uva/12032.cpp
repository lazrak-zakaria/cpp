
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


int main()
{
    int n;
    scanf("%d", &n);
    int u = 1;
    while (n--)
    {
        int m;
        int k = 0;
        scanf("%d", &m);

        map<int, pair<int, int> > mp;
        vector<int> all(m);
        for (int i = 0; i < m; ++i)
        {
            int j;
            scanf("%d", &j);
            int dif = j - k;
            if (mp.count(dif))
                mp[dif].first += 1;
            else
                mp[dif].first = 1;

            mp[dif].second = i;
            
            all[i] = dif;
            k = j;
        }
        map<int , pair<int, int>>::iterator it  = --mp.end();
        int ans =  it->second.first > 1 ? it->first + 1 : it->first;
        
        int i = it->second.second + 1;
        int tmpans = ans -1;
        while (i < m)
        {
            if (tmpans < all[i])
            {
                tmpans++;
                ans++;
            }
            else if (tmpans == all[i])
                tmpans--;
            
            ++i;
        }
        printf("Case %d: %d\n", u++, ans );
        /**/
    }
}