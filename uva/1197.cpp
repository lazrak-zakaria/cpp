
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


class UnionFind
{
    private:
        vector<int> p;
        int N;
    
    public:
        UnionFind(int n = 0) : p(n, -1) , N(n)
        {}

        int find(int x) //find root
        {
            if (p[x] < 0)
                return x;
            p[x] = find(p[x]);
            return p[x];
        }

        bool unionSet(int x, int y)
        {
            x = find(x);
            y = find(y);
            if (x == y) // in the same set
                return false;
            
            if (p[x] > p[y])
                swap(x, y);

            p[x] += p[y];
            p[y] = x;
            N--;
        
            return true;
        }

        int size(int x)
        {
            return (p[find(x)] * -1);
        }

        bool isSameSet(int x, int y)
        {
            return (find(x) == find(y));
        }

        int numOfSets()
        {
            return N;
        }

};


int main()
{

    while (true)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (!n && !m)
            return 0;
        UnionFind uf(n);
        while (m--)
        {
            int r;
            scanf("%d", &r);
            int i = 0;
            int t;
            while (i < r)
            {
                if (!i)
                    scanf("%d", &t);
                else
                {
                    int j;
                    scanf("%d", &j);
                    uf.unionSet(j,t);
                    t = j;
                }
                ++i;
            }
        }
        printf("%d\n", uf.size(0));
    }
}