#include <iostream>
#include <vector>
using namespace std;

void generatePowerset(const vector<int>& S, vector<vector<int>>& powerset, vector<int>& subset, int index) {
    if (index == S.size()) {
        powerset.push_back(subset);
        return;
    }

    // 不包含當前元素
    generatePowerset(S, powerset, subset, index + 1);

    // 包含當前元素
    subset.push_back(S[index]);
    generatePowerset(S, powerset, subset, index + 1);

    // 回溯，移除當前元素以進行下一次迭代
    subset.pop_back();
}


/*  初始化一個空的冪集和子集，
    調用 generatePowerset 開始遞歸。   */

vector<vector<int>> powerset(const vector<int>& S) {
    vector<vector<int>> powerset;
    vector<int> subset;
    generatePowerset(S, powerset, subset, 0);
    return powerset;
}

//主程式
int main() {
    vector<int> S = { 4, 5, 6 }; // 定義示範集合
    vector<vector<int>> result = powerset(S);

    cout << "{ ";
    for (const auto& subset : result) {
        cout << "{";
        for (int elem : subset) {
            cout << elem << " ";
        }
        cout << "} ";
    }
    cout << "}" << endl;

    return 0;
}