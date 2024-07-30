#include <iostream>
using namespace std;

// ���J�Ҩ�ưj��
int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return 0;
}
//�D�{��
int main() {
    int m, n;
    cout << "��Jm�Pn���� ";
    cin >> m >> n;
    int result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}