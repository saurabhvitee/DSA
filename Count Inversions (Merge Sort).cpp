
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int low, int mid, int high){
    // tempoarary vector
    vector<int> temp;
    int count = 0;
    int i=low,j = mid+1;

    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            temp.push_back(a[i]);
            i++;
        }else{
            temp.push_back(a[j]);
            j++;
            count += (mid-i+1);
        }
    }

    while(i <= mid){
        temp.push_back(a[i]);
        i++;
    }

    while(j <= high){
        temp.push_back(a[j]);
        j++;
    }

    for(int i=low; i<= high; i++){
        a[i] = temp[i-low];
    }


    return count;

}

int mergeSort(vector<int> &a, int low, int high){
    int count = 0;

    if(low >= high){
        return count;
    }

    int mid = (low+high)/2;

    count += mergeSort(a, low, mid);
    count += mergeSort(a, mid+1, high);
    count += merge(a, low, mid, high);
    return count;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();

    int count = mergeSort(a, 0, n-1);

    cout << count << endl;

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}


