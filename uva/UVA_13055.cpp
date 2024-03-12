
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
#include <stack>

using namespace std;


int main()
{
    int n;
    cin >> n;

    stack <string> stk;

    while (n--)
    {
        string q;
        cin >> q;
        if (! strncmp("Sleep", q.c_str(), 5))
        {
            cin >> q;
            stk.push(q);
        }
        else if (q == "Test")
        {
            if (stk.empty())
                cout << "Not in a dream\n";
            else
                cout << stk.top() << "\n";
        }
        else if (q == "Kick" && ! stk.empty())
            stk.pop();
    }
     
}