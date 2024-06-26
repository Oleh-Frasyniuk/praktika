#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//друк лист 
void printList(const vector<int>& list) {
    for (int i = 0; i < list.size(); ++i) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << list[i] << " ";
    }
}

int main() {
    vector<int> L1 = { 5, 4, 3, 2, 1 };
    vector<int> L2 = { 8, 6, 7, 9 };

    //cорт L1 за спаданням
    sort(L1.begin(), L1.end(), greater<int>());

    //вставити елементи L2 в L1
    for (int i = 0; i < L2.size(); ++i) {
        auto it = lower_bound(L1.begin(), L1.end(), L2[i], greater<int>());
        L1.insert(it, L2[i]);
    }

    cout << "Changed list L1:" << endl;
    printList(L1);

    return 0;
}
