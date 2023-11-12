/*Implementation of 
sequential, binary and block search algorithm */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int sequential_search(vector<int>& arr, int index){
    int nums = arr.size();
    for(int i = 0; i < nums; i++)
        if(i == index)
            return arr[i];
    return -1;
}

int binary_search_closed(vector<int>& arr, int val){
    int left = 0;
    int right = arr.size();
    int mid;
    while(left <= right){
        mid = (left + right)/2;
        if(arr[mid] > val)
            right = mid - 1;
        else left = mid + 1;
    }
    return mid;
}
/*interval [L, R]*/

int binary_search_open(vector<int>& arr, int val){
    int left = 0;
    int right = arr.size();
    int mid;
    while(left < right){
        mid = (left + right)/2;
        if(arr[mid] > val)
            right = mid;
        else left = mid + 1;
    }
    return mid;
}
/*interval [L, R)*/

/*Since the boundary limitation depends on the given interval
We will divide the interval into two cases*/

int block_search(vector<int>& arr, int n, int val){
    vector<int> maxm_arr;
    int size = sqrt(n);
    int maxm = -1000;
    int index;
    /*We choose the case that the block size is the square root of
    the number of all elements as an example*/

    /*The maxmima in the previous block must be less than
    the minima in the next block*/

    int current_left = 0, current_right = size - 1;

    /*Find the maxima in each block divided*/
    for(int i = 1; i <= (n/size); i++){
        for(int j = current_left; j <= current_right; j++)
            if(arr[j] > maxm) maxm = arr[j];
        maxm_arr.push_back(maxm);

        current_left += size;
        current_right += size;
        maxm = -1000;
    }
    
    current_left = 0, current_right = size - 1;

    /*If the target value is greater than the maxima in the current block
    it means that the value does not exist in the current block
    so that we should move to the next one*/

    for(int i = 0; i < (n/size); i++){
        if(val > maxm_arr[i]){
            current_left += size;
            current_right += size;

            for(int j = current_left; j <= current_right; j++)
                if(val == arr[j]) return j;
        }

        else break;
    }
    /*If not, it indicates that the target value exists in the current block*/
    for(int j = current_left; j <= current_right; j++)
        if(val == arr[j]) index = j; 

    return index;
}
int main(){
    vector<int> a = {5, 3, 8, 2, 1, 4};
    int index, res1;
    scanf("%d", &index);
    res1 = sequential_search(a, index);
    cout<<res1;

    vector<int> num = {1, 2, 3, 4, 5, 8};
    int val, res2, res3;
    scanf("%d", &val);
    res2 = binary_search_closed(num, val);
    cout<<res2;

    vector<int> arr = {1, 4, 8, 7, 9, 11};
    int target;
    int n = arr.size();
    scanf("%d",&target);
    int res3 = block_search(arr, n, target);
    cout<<res3;

    return 0;
}