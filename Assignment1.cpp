#include<bits/stdc++.h>
using namespace std;
int res[40000];
int main(){
    memset(res, -1, sizeof(res));
    int j = 0;
    res[0] = 1;
    for(int i = 2;i <= 10000;i++){
        j = 0;
        while(res[j] != -1){
            res[j] = res[j] * i;
            j++;
        }
        for(j = 0;res[j] != -1;j++){
            if(res[j+1] != -1)
                res[j+1] = res[j+1] + res[j]/10;
            else{
                if(res[j]/10 != 0)
                    res[j+1] = res[j]/10;
            }
            res[j] = res[j]%10;
        }
    }
    for(int i = j-1;i >= 0;i--)
        cout<<res[i];
    return 0;
}