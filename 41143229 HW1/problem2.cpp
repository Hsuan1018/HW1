#include <iostream>
#include <vector>
using namespace std;

void generatePowerset(const vector<int>& S, vector<vector<int>>& powerset, vector<int>& subset, int index) {
    if (index == S.size()) {
        powerset.push_back(subset);
        return;
    }

    // ���]�t��e����
    generatePowerset(S, powerset, subset, index + 1);

    // �]�t��e����
    subset.push_back(S[index]);
    generatePowerset(S, powerset, subset, index + 1);

    // �^���A������e�����H�i��U�@�����N
    subset.pop_back();
}


/*  ��l�Ƥ@�ӪŪ������M�l���A
    �ե� generatePowerset �}�l���k�C   */

vector<vector<int>> powerset(const vector<int>& S) {
    vector<vector<int>> powerset;
    vector<int> subset;
    generatePowerset(S, powerset, subset, 0);
    return powerset;
}

//�D�{��
int main() {
    vector<int> S = { 4, 5, 6 }; // �w�q�ܽd���X
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