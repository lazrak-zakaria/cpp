
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
    int T;
    string in;
    
    cin >> T;
    getchar();
    getline(cin , in);
    
    while(T--)
    {
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
            cout << n << " " << m << " " << p << " " << c << "\n";
            
        }

        


    }
}