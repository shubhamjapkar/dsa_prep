#include <bits/stdc++.h>
using namespace std;

// In this problem we cut cake in many pices after cutting pices we have to find max area we can get from cake

int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);

    verticalCuts.push_back(0);
    verticalCuts.push_back(w);

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int hr = 0;
    int vr = 0;

    for (int i = 0; i < horizontalCuts.size() - 1; i++)
    {
        hr = max(abs(horizontalCuts[i] - horizontalCuts[i + 1]), hr);
    }

    for (int i = 0; i < verticalCuts.size() - 1; i++)
    {
        vr = max(abs(verticalCuts[i] - verticalCuts[i + 1]), vr);
    }

    return (1LL * hr * vr) % 1000000007;
}

int main()
{
}