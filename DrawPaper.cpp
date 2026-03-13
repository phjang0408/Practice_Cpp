#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Myclass
{
public:
    int a;
    string s;
    bool operator==(const Myclass &other) const
    {
        return other.a == a && other.s == s;
    }
};

int main()
{
    vector<Myclass> ar = {
        {3, "a"},
        {2, "b"},
    };
    auto it = find(ar.begin(), ar.end(), Myclass{3, "a"});
}