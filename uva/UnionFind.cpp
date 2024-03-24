
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


/*
    p 
        if p[index] < 0   => means it's a root  && change the sign to get size of the set
*/

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
    UnionFind UF(5);

    printf("total sets = : |%d|\n", UF.numOfSets());


    UF.unionSet(0,1);
    printf("total sets = : |%d|\n", UF.numOfSets());


    UF.unionSet(0,2);
    printf("total sets = : |%d|\n", UF.numOfSets());
    printf("size = : |%d|\n", UF.size(2));

    printf("is same set = |%d|\n", UF.isSameSet(2,1));

    
    UF.unionSet(3,4);
    printf("total sets = : |%d|\n", UF.numOfSets());


    return 0;
}

/*
Fact: Every two points of a tree are joined by a unique path.
Tree:
    V - E = CC

*/