#include <iostream>
#include <array>
using namespace std;
class Person
{
public:
    int height;
    int weight;
    int rank = 1;
};
int main()
{
    array<Person, 50> People;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> People[i].weight >> People[i].height;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (People[i].weight < People[j].weight && People[i].height < People[j].height)
            {
                People[i].rank++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << People[i].rank << " ";
    }
}