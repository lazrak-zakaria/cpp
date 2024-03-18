
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


int main()
{
    bool e = false;
    while (true)
    {
        int n;
        cin >> n;
        if (!n)
            break;
        if (e)
            cout << "\n";
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i <= n - 6; ++i)
        {
            for (int j = i + 1; j <= n - 5; ++j)
            {
                for (int k = j + 1; k <= n - 4; ++k)
                {
                    for (int l = k + 1; l <= n - 3; ++l)
                    {
                        for (int z = l + 1; z <= n - 2; ++z)
                        {
                            for (int x = z + 1; x <= n - 1 ; ++x)
                                cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << " " << a[z] << " " << a[x] << "\n";
                        }
                    }
                }
            }
        }
        e = true;
    }
}