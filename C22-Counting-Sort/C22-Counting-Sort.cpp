// C22-Counting-Sort.cpp 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void showVector(vector<int> v, string caption = "") {
    cout << caption << "  ";
    //for (auto val : v) cout << val << "  ";
    for (int i = 0; i < v.size(); i++) {
        cout << i << ":" << v[i] << ", ";
    }
    cout << endl;
}


int main()
{
    vector<int> v{ 2,4,5, 2, 1, 8, 3, 2, 5 };
    showVector(v, "Original");

    int maxValue = v[0];
    for (auto num : v) if (num > maxValue) maxValue = num;

    vector<int> vfreq(maxValue+1, 0 );
    showVector(vfreq, "vfreq");

    for (auto i : v) { vfreq[i]++; }
    showVector(vfreq, "Count ");

    for (int i = 1; i < vfreq.size(); i++) {
        vfreq[i] += vfreq[i - 1];
    }
    showVector(vfreq, "Accum");

    vector<int> vnew(v.size());
    for (int i = v.size() - 1; i >= 0; i--) {
        //showVector(vfreq, "\nvfreq");
        int val = v[i];
        int pos = vfreq[val] - 1;
        vnew[pos] = val;
        //cout << "val: " << val << " pos: " << pos << endl;
        //showVector(vnew, "vnew");
        vfreq[val]--;
    }

    showVector(vnew, "Sorted ");
    cout << "\nAll done!\n";
}
