
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


using namespace std;

int main()
{
    int n;
    cin >> n;
    
    char a[4];
    std::string all[101];

    int leftPos[101] = {};
    int rightPos[101] = {};
    int lPos = -200;
    int rPos = 0;
    for (int i = 0; i < n ; ++i)
    {
        scanf("%s", a);
        all[i] = a;
        if (all[i] != "?")
            lPos = i;
        leftPos[i] = lPos;
    }

    rPos = 200;
    for (int i = n - 1; i >= 0 ; --i)
    {
        if (all[i] != "?")
            rPos = i;

        rightPos[i] = rPos;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int p;
        cin >> p;
        // cout << "------------------------>" << p << "\n";

        p--;

        // There will be at least one name not equal to ‘?’
        if (rightPos[p] == 200 || leftPos[p] == -200)
        {
            if (rightPos[p] == 200)
            {
                for (int j = 0; j < p - leftPos[p] ; ++j)
                {
                    cout << "right of ";
                }
                cout << all[leftPos[p]] << "\n";
            }
            else
            {
                for (int j = 0; j < rightPos[p] - p; ++j)
                {
                    cout << "left of ";
                }
                cout << all[rightPos[p]] << "\n";
            }
            continue;
        }
        
        if (rightPos[p] == leftPos[p])
            cout << all[p] << "\n";
        else if (rightPos[p] - p == p - leftPos[p])
            cout << "middle of "<< all[leftPos[p]] <<" and " << all[rightPos[p]] << "\n";
        else if (rightPos[p] - p < p - leftPos[p])
        {
            for (int j = 0; j < rightPos[p] - p; ++j)
            {
                cout << "left of ";
            }
            cout << all[rightPos[p]] << "\n";
        }
        else if (rightPos[p] - p > p - leftPos[p])
        {
            for (int j = 0; j < p - leftPos[p] ; ++j)
            {
                cout << "right of ";
            }
            cout << all[leftPos[p]] << "\n";
        }
    }

    return 0;
}

// a 4 5 6 
// b 4 7 8 1
// c 4 7 3
