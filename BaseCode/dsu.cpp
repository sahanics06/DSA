#include<bits/stdc++.h>

using namespace std;


class dsu
{
    vector<int>rank, parent;

public:

    dsu(int n)
    {
        rank.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int a)
    {
        if(a==parent[a])
            return a;
        return parent[a] = find(parent[a]);
    }
    void connect(int a, int b)
    {
        int ta = find(a);
        int tb = find(b);
        if(ta==tb)
            return;
        if(rank[ta]>rank[tb])
        {
            parent[tb] = ta;
        }
        else if(rank[tb]>rank[ta])
        {
            parent[ta] = tb; 
        }
        else
        {
            parent[ta] = tb;
            rank[tb]++;
        }
    }
};

    int main()
    {
        dsu obj(8);
        obj.connect(1,2);
        obj.connect(1,3);
        obj.connect(3,8);
        obj.connect(4,5);
        obj.connect(5,6);
        obj.connect(1,2);
        cout<<obj.find(8)<<"   "<<obj.find(7)<<endl;
        obj.connect(8,7);
        cout<<obj.find(8)<<"   "<<obj.find(7)<<endl;

        return 0;
    }
