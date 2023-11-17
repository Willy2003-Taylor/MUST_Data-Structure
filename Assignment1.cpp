#include<bits/stdc++.h>
using namespace std;
void factorial(int n){
    vector<int> result;
    result.push_back(1);
    for(int i = 2; i <= n; i++){
        int carry = 0;
        for(int j = 0; j < result.size(); j++){
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        while(carry){
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    for(int i = result.size() - 1; i >= 0; i--)
        cout<<result[i];
    
}
int main(){
    int n = 10000;
    factorial(n);
    return 0;
}
