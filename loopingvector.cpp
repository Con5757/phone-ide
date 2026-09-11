#include <iostream>
#include <vector>

using namespace std;

vector<int> items = { 1, 2, 3, 4, 5 };

int main() {
    // item loop
    for (auto item : items) {
        cout << item << endl;
    }

    // index loop
    for (int i = 0; i < items.size(); i++) {
        cout << items[i] << endl;
    }

    return 0;
}