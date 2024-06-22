#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class point
{
public:
    int x, y;
    point(int a, int b)
    {
        x = a;
        y = b;
    }

    bool operator<(const point& other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

set<point> convexHull; // Use a set instead of a vector

int onWhichSide(point a, point b, point c)
{
    int val = ((c.y - b.y) * (b.x - a.x)) - ((c.x - b.x) * (b.y - a.y));
    if (val == 0)
        return 0;
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
}

int getDist(point a, point b, point c)
{
    return abs((c.y - b.y) * (b.x - a.x) - (c.x - b.x) * (b.y - a.y));
}

void quickHullAlgo(vector<point>& Points, int n, point a, point b, int sameside)
{
    int indx = -1;
    int maxDist = -1;
    for (int i = 0; i < n; i++)
    {
        int tempMax = getDist(a, b, Points[i]);
        if (onWhichSide(a, b, Points[i]) == sameside)
        {
            if (tempMax > maxDist)
            {
                indx = i;
                maxDist = tempMax;
            }
        }
    }

    if (indx == -1)
    {
        convexHull.insert(a);
        convexHull.insert(b);
        return;
    }

    quickHullAlgo(Points, n, Points[indx], a, -onWhichSide(Points[indx], a, b));
    quickHullAlgo(Points, n, Points[indx], b, -onWhichSide(Points[indx], b, a));
}

void print(vector<point>& allPoints)
{
    if (allPoints.size() < 3)
        return;

    int max = 0, min = 0;
    int n = allPoints.size();
    for (int i = 1; i < n; i++)
    {
        if (allPoints[i].x > allPoints[max].x)
            max = i;
        if (allPoints[i].x < allPoints[min].x)
            min = i;
    }

    convexHull.clear();

    quickHullAlgo(allPoints, n, allPoints[max], allPoints[min], 1);
    quickHullAlgo(allPoints, n, allPoints[max], allPoints[min], -1);

    for (const point& element : convexHull)
    {
        cout << element.x << " " << element.y << endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    int n;
    vector<point> allPoints;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        point p(x, y);
        allPoints.push_back(p);
    }
    print(allPoints);
    return 0;
}