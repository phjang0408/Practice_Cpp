#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> first(n), second(n), rank(n,1);
    for(int i =0; i < n ;i++){
        cin >> first[i] >> second[i];
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n;j++){
            if(first[i] < first[j] && second[i] < second[j]){
                rank[i]++;
            }
        }
    }
    for(auto x:rank){
        cout << x << " ";
    }
}