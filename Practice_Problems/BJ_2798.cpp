#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, highest = 0;
    cin >> n >> m;
    vector<int> cards(n);
    for(int &x : cards){
        cin >> x;
    }
    for (int i = 0; i < cards.size() - 2; i++)
    {
        for (int j = i + 1; j < cards.size() - 1; j++)
        {
            for (int k = j + 1; k < cards.size(); k++)
            {
                int tmp_sum = cards[i] + cards[j] + cards[k];
                if (tmp_sum <= m && tmp_sum > highest)
                {
                    highest = tmp_sum;
                }
            }
        }
    }
    cout << highest;
}