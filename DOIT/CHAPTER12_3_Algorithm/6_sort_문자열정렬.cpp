#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

void PrintVector(const string &title, const vector<string> &v)
{
    cout << "[" << title << "]\n";
    for (auto x : v)
    {
        cout << x << " - ";
    }
    cout << "\n\n";
    return;
}

int main()
{
    vector<string> words = {"apple", "banana", "kiwi", "pear", "orange", "grapes", "Banana", "123"};

    // 1. 기본 정렬(사전순, 오름차순)
    vector<string> v1 = words;
    sort(v1.begin(), v1.end());
    PrintVector("1. 기본형 - 사전순 정렬", v1);

    // 2. 길이 순 정렬 (길이가 짧은 순서대로, 같으면 사전순)
    vector<string> v2 = words;
    sort(v2.begin(), v2.end(), [](const string &a, const string &b)
         {
             if (a.length() != b.length())
             {
                 return a.length() < b.length(); // 길이 우선 비교
             }
             return a < b; // 길이가 같으면, 사전순 비교
         });
    PrintVector("2. 람다형 - 길이순 비교 후 사전순 비교", v2);

    // 3. 내림차순 정렬(사전의 역순)
    vector<string> v3 = words;
    sort(v3.begin(), v3.end(), std::greater<string>());
    PrintVector("3. greater함수 - 내림차순", v3);

    return 0;
}