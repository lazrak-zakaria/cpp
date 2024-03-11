
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
#include <utility>

using namespace std;

int cmp(pair<int, int>& f, pair<int, int>& s){

        int ff = f.first;
        int ss = s.first;

        int im = f.second;
        int jm = s.second;

        if (im < jm)
            return true;
        if (im > jm)
            return false;


        bool isFirstOdd = ff % 2;
        bool isSecondOdd = ss % 2;

        if (isFirstOdd && !isSecondOdd)
            return true;
        
        if (!isFirstOdd && isSecondOdd)
            return false;
        
        if (isFirstOdd && isSecondOdd) // return larger number
            return ff > ss;
        
        return ff < ss; //even return smaller;

        
    }

int main()
{
    int n, m;



    
    while (true)
    {
        cin >> n >> m;
        if (!n && !m)
            break;
        vector< pair<int, int> > a;
        for (int i = 0; i < n; ++i)
        {
            int j;
            cin >> j;

            a .push_back ({j, j % m});
        }
        
        sort(a.begin(), a.end(), cmp );

        while (! is_sorted(a.begin(), a.end(), cmp))
        {
            // cout << '-';
            sort(a.begin(), a.end() + n, cmp );
        }
        
        cout << n << " " << m << "\n";
        for (int i = 0; i < n; ++i)
        {
            cout << a[i].first << "\n";
        }
    }
    cout << "0 0\n";

}