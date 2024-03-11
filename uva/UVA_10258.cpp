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

typedef struct user
{
    int n;
    int m;
    int p;
    int pbf[9];

    int solved;
    bool exist;

    user ()
    {
        memset(this, 0, sizeof(*this));
    }
} user ;

// if first arg goes before the second return true
bool cmp(user &a, user &b)
{
    if (a.m > b.m)
        return true;
    else if (a.m < b.m)
        return false;
    
    
    if (a.p < b.p)
        return true;
    else if (a.p > b.p)
        return false;
    
    return (a.n < b.n) ;
}



int main()
{
    int T;
    string in;

    cin >> T;
    getchar();
    getline(cin , in);
    
    while(T--)
    {
        vector<user> u(100);
        vector<user> answer;

        while (true)
        {
            in = "";
            getline(cin , in);
            if (in.empty())
                break;
            stringstream ss(in);
            int n, m, p;
            char c;

            ss >> n >> m >> p >> c;
            // cout << n << " " << m << " " << p << " " << c << "\n";

            --n;

            u[n].exist = true ;
            u[n].n = n;
            if (! ((1 << m) & u[n].solved) )
            {
                if (c == 'I')
                {
                    u[n].pbf[m - 1] += 20;
                }
                else if (c == 'C')
                {
                    u[n].p += p + u[n].pbf[m - 1];
                    u[n].solved  = ((1 << m) | u[n].solved);
                    u[n].m++ ;
                }
                //else do nothing
            }
        }

        for (auto &i : u)
        {
            if (i.exist)
                answer.push_back(i);
        }

        sort(answer.begin(), answer.end(), cmp);

        
        for (auto &i : answer)
            cout << i.n + 1 << ' ' << i.m << ' ' << i.p << "\n";
        
        if (T)
            cout << "\n";
    }
}


