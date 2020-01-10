#include<bits/stdc++.h>
using namespace std;
#define MAX 100
struct Graph;
struct Graph
{
    int n; //so dinh
    int a[MAX][MAX];    //phan tu ma tran ke
    char label[MAX][20];  //nhan
};
int maudinh[MAX];
FILE *f;
bool ReadGraph(Graph &g, char *name)
{
    f = fopen(name,"rt");
    if(f == NULL)
    {
        g.n = 0;
        return false;
    }
    fscanf(f,"%d",&g.n);
    for (int k = 1; k <= g.n; ++k)
        fscanf(f,"%s",&g.label[i]);
    for (int i = 1; i <= g.n; ++i)
        for (int j = 1; j <= g.n; ++j )
            fscanf(f,"%d",&g.a[i][j]);
    f.close(f);
    return true;
}
void Tomau()
{
    maudinh[1] = 1;
    for (int i = 2; i <= n; i++ )
    {
        maudinh[i] = 1;
        j=1;
        //
        for (int j = 1; j <= i-1; j++ )
            if (g.a[i][j]!= 0 && maudinh [i] == maudinh[j])
                maudinh [i]++;
        for (int j = 1; j <= n; j++ )
            if (g.a[i]a[j]!=0 && maudinh [i] == maudinh[j])
            ///
    }
}
int dembac(Graph g)
{
    for(int i = 1; i<=n; i++)
    {
        int dem = 0;
        for(int j = 1; j<=n ;j++)
            if(g.a[i][j] == 1)
                dem = +g.a[i][j];
    }
}

main()
{
    Graph g;
    char city;
    ReadGraph(g,city);
    Tomau();
    for ( int i = 1; i <= n; i++ )
    printf("\nDinh %d to mau %d ",i,maudinh);
    getch();
}