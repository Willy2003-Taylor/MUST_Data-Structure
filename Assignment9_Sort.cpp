#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selection_sort(vector<int>& arr, int n){
    int index_record;
    for(int i = 0; i < n; i++){
        index_record = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[index_record])
                index_record = j;
        }
        if(index_record != i)
            swap(arr[i], arr[index_record]);
    }
}

void insertion_sort(vector<int>& arr, int n){
    int tmp, prev;
    for(int i = 1; i < n; i++){
        tmp = arr[i];
        prev = i - 1;

        while(prev >= 0 && arr[prev] > tmp){
            arr[prev + 1] = arr[prev];
            prev--;
        }
            
        arr[prev + 1] = tmp;
    }
}

void bubble_sort(vector<int>& arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> sub1;
    vector<int> sub2;
    int n1 = mid - left + 1;
    int n2 = right - mid + 1;

    for(int i = 0; i < n1; i++)
        sub1.push_back(arr[i + left]);
    for(int i = 0; i < n2; i++)
        sub2.push_back(arr[i + mid + 1]);
    
    int i = 0, j = 0;
    int tmp = left;

    while(i < n1 && j < n2){
        if(sub1[i] <= sub2[j]){
            arr[tmp] = sub1[i];
            i++;
        }
        else{
            arr[tmp] = sub2[j];
            j++;
        }
        tmp++;
    }

    while(i < n1){
        arr[tmp] = sub1[i];
        i++;
        tmp++;
    }
    while(j < n2){
        arr[tmp] = sub2[j];
        j++;
        tmp++;
    }
}

void merge_sort(vector<int>& arr, int left, int right){
    if(left < right){
    int mid = (left + right) / 2;
    merge_sort(arr,left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
    }
}

void shell_sort(vector<int>& arr, int n){
    int gap = n / 2;
    int tmp;
    while(gap > 0){
        for(int i = gap; i < n; i++){
            tmp = arr[i];
            int j;
            
            for(j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                    arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
        gap /= 2;
    }
}

void quick_sort(vector<int>& arr, int left,int right){
    int i=left,j=right;
    int pivot=arr[(left+right)/2];
    do{
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;

        if(i<=j){
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }while(i<=j);

    if(j>=left) quick_sort(arr, left, j);
    if(i<=right) quick_sort(arr, i, right);
}


int main(){
    vector<int> arr1 = {64, 25, 12, 22, 11};
    vector<int> arr2 = {7, 4, -2, 19, 13, 6};
    vector<int> arr3 = {23, 38, 22, 45, 23, 67, 31, 15, 41};
    vector<int> arr4 = {9, 13, 8, 2, 5, 13, 7, 1, 15, 11};
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    int n4 = arr4.size();

    selection_sort(arr1, n1);
    for(int i = 0; i < n1; i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    insertion_sort(arr2, n2);
    for(int i = 0; i < n2; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    bubble_sort(arr3, n3);
    for(int i = 0; i < n3; i++)
        cout<<arr3[i]<<" ";
    cout<<endl;
    merge_sort(arr3, 0, n3 - 1);
    for(int i = 0; i < n3; i++)
        cout<<arr3[i]<<" ";
    cout<<endl;

    shell_sort(arr4, n4);
    for(int i = 0; i < n4; i++)
        cout<<arr4[i]<<" ";
    cout<<endl;

    quick_sort(arr4, 0, n4 - 1);
    for(int i = 0; i < n4; i++)
        cout<<arr4[i]<<" ";
    cout<<endl;
    return 0;
}