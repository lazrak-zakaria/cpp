
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
    int mustBe = 0;
    for (int i = 0; i < 10; ++i)
        mustBe |= 1 << i;

    bool b = false;

    while (true)
    {
        int n;
        cin >> n;

        if (!n)
            break;

        if (b) cout << "\n";

        int ok = false;
        int d;
        for (int i = 1234; i <= 98765 / n; ++i)
        {
            d = i * n;

            int bitFlag =  (i <= 9999);

            int t = i , td = d;
            while (t || td)
            {
                if (t)
                    bitFlag |= 1 << (t % 10);
                if (td)
                    bitFlag |= 1 << (td % 10);
                
                t /= 10;
                td /= 10;
            }
            // cerr << mustBe << "\n";
            if (bitFlag == mustBe)
            {
                cout << d << " / " << ((i <= 9999) ? "0" : "")<< i << " = " <<  n << "\n";
                ok = true;
            }
        }

        b = true;
        if (!ok)
            cout << "There are no solutions for "<< n <<".\n";
    }
    return 0;
}