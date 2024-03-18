
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
    while (true)
    {
        int n, m;
        scanf("%d%d",&n, &m);
        if (!n && !m)
            break;

        vector< vector<int> > data(n,vector<int>(m));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int h;
                scanf("%d", &h);
                data[i][j] = h;
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int ans = 0;
            int l,u;
            scanf("%d%d", &l, &u);
            
            for (int i = 0; i < n; ++i)
            {
                vector<int>::iterator it = lower_bound(data[i].begin(), data[i].end(), l);

                if (it != data[i].end() && *it <= u)
                {
                    int k = i;
                    for (int t = int(it - data[i].begin()); t < m && k < n && data[k][t] <= u; ++t)
                        k++;


                    ans = max(ans, k - i);
                }
            }
            cout << ans << "\n";
        }
        cout << "-\n";
    }
}