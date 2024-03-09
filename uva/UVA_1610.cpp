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
    int n;
    while (true)
    {
        cin >> n;
        if (!n)
            return 0;

        vector <string> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        

        sort(a.begin(), a.end());

        int s = n / 2;
        int f = s - 1 ;
        string answer;

        string &first = a[f];
        string &second = a[s];

        size_t fsize = first.size();
        size_t sSize = second.size();

        // int stop = fsize.size() > sSize.size() ? fsize.size() : sSize.size();

        
        int i = 0; 
        if (fsize < sSize)
        {
            while (i < fsize)
            {
                if (first[i] == second[i])
                    answer.push_back(first[i]);
                else
                {
                    if ( i + 1 == fsize)
                        answer.push_back(first[i]);
                    else 
                        answer.push_back(first[i] + 1);
                    break;
                }
                
                ++i;
            }
        }

        if (sSize <= fsize)
        {
            while (i < fsize)
            {
                
            }
        }

        cout << answer << "\n";
    }
}

// abbc
// abbcj

// abcx
// abdxm

// abbd
// abbf


/*

generate a string


zizo
fred
fredie
fredif
fredze
ziz




abcddro  
abcde

*/

