#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<int,int> > sch;

int getMinPlatform(int n)
{
    int platformcnt = 1, maxcnt = 1;

    for (int i = 0; i < n; i++)
    {
        platformcnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (sch[j].first <= sch[i].first && sch[i].first <= sch[j].second)
                platformcnt++;
        }
        if (platformcnt > maxcnt)
            maxcnt = platformcnt;
    }
    return platformcnt;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int arr, dep;
        cin >> arr >> dep;
        sch.push_back(make_pair(arr, dep));
    }
    cout << getMinPlatform(n) << endl;
    return 0;
}