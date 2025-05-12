#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // Making this problem little complex, dropping last n zeroes from nums1
        //nums1.resize(nums1.size()-n);

        int len = n+m;

        int gap = len/2 + len%2;

        // cout << m <<  " " << n << endl;

        while(gap > 0){

            int left = 0;
            int right = left + gap;

            while(right < len){
                cout << "gap " << gap << endl;

                if(left < m && right < m){

                    if(nums1[left] > nums2[right]){
                        cout << "case-1 " << nums1[left] << " " << nums2[right] << endl;
                        swap(nums1[left], nums2[right]);
                    }

                }

                if(left < m && right >= m){

                    if(nums1[left] > nums2[right-m]){
                        cout << "case-2 " << nums1[left] << " " << nums2[right-m] << endl;
                        swap(nums1[left], nums2[right-m]);
                    }

                }

                if(left >= m && right >= m){

                    if(nums1[left-m] > nums2[right-m]){
                        cout << "case-3 " << nums1[left-m] << " " << nums2[right-m] << endl;
                        swap(nums1[left-m], nums2[right-m]);
                    }
                }

                left++;
                right++;
            }

            if (gap == 1){
                break;
            }

            gap = gap/2 + gap%2;
            cout << endl;
            cout << "changing gap =========================== " << endl;

        }
        
    }

int main() {
    int m, n;
    cin >> m;
    vector<int> nums1(m);

    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    
    cin >> n;
    vector<int> nums2(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);


    for (int num : nums1) {
        cout << num << " ";
    }

    for (int num : nums2) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
