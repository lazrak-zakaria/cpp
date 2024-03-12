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
#include <list>
#include <sstream>

using namespace std;


int main()
{
    int t;
    cin >> t;

        // cout << "h";
    while (t--)
    {
        string str;
        int l;
        std::string arr;

        cin >> str >> l >> arr;
        
        arr[0] = ',';
        arr[arr.length() - 1] = ',';

        std::list <string> lst;

        stringstream ss(arr);
        
        string token;
        while (getline(ss, token, ','))
        {
            if (!token.empty())
                lst.push_back(token);
        }
        bool startFront= true;
        for (auto &i : str)
        {
            if (i == 'R')
                startFront = !startFront;
            else if (i == 'D')
            {
                if (lst.empty())
                {
                    cout << "error\n";
                    l = -1;
                    break;
                }

                if (startFront)
                    lst.pop_front();
                else
                    lst.pop_back();
            }
        }

        if (l == -1)
            continue;
        
        if (!startFront)
            lst.reverse();

        auto start = lst.begin();
        auto end = lst.end();
        cout << '[';
        while (start != end)
        {
            cout << *start;
            start++;
            
            if (start != end)
                cout << ',';
        }
        cout << "]\n";
    }
}