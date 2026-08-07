#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int best = 1, current = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            current++;
        else
            current = 1;

        best = max(best, current);
    }

    cout << best << endl;
    return 0;
}