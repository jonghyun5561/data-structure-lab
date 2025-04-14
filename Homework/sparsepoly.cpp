#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Term {
    double coef;
    int exp;
};

using Polynomial = vector<Term>;

// ����ڿ��� ���׽� �Է¹ޱ�
Polynomial inputPoly(char name) {
    Polynomial poly;
    int n;
    cout << name << " ���� ������ �Է��ϼ���: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        double coef;
        int exp;
        cout << i + 1 << "�� ° ���� ����� ������ �Է��ϼ��� (��:��� ����): ";
        cin >> coef >> exp;
        poly.push_back({ coef, exp });
    }
    return poly;
}

// ���׽� ���
void printPoly(const Polynomial& poly, string name) {
    cout << name << ": ";
    for (size_t i = 0; i < poly.size(); ++i) {
        cout << poly[i].coef << "x^" << poly[i].exp;
        if (i != poly.size() - 1) cout << " + ";
    }
    cout << endl;
}

// ���׽� ����
Polynomial addPolynomials(Polynomial A, Polynomial B) {
    Polynomial result;
    // ���� �������� ���ϰ�, ���� ������ �״�� �߰�
    while (!A.empty() && !B.empty()) {
        if (A.back().exp == B.back().exp) {
            result.push_back({ A.back().coef + B.back().coef, A.back().exp });
            A.pop_back(); B.pop_back();
        }
        else if (A.back().exp > B.back().exp) {
            result.push_back(A.back());
            A.pop_back();
        }
        else {
            result.push_back(B.back());
            B.pop_back();
        }
    }
    // ���� �� ó��
    while (!A.empty()) {
        result.push_back(A.back());
        A.pop_back();
    }
    while (!B.empty()) {
        result.push_back(B.back());
        B.pop_back();
    }

    // ���� ����
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    Polynomial A = inputPoly('A');
    printPoly(A, "Poly A");

    Polynomial B = inputPoly('B');
    printPoly(B, "Poly B");

    Polynomial C = addPolynomials(A, B);
    printPoly(C, "Poly C");

    return 0;
}
