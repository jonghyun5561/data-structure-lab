#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Term {
    double coef;
    int exp;
};

using Polynomial = vector<Term>;

// 사용자에게 다항식 입력받기
Polynomial inputPoly(char name) {
    Polynomial poly;
    int n;
    cout << name << " 항의 개수를 입력하세요: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        double coef;
        int exp;
        cout << i + 1 << "번 째 항의 계수와 차수를 입력하세요 (예:계수 차수): ";
        cin >> coef >> exp;
        poly.push_back({ coef, exp });
    }
    return poly;
}

// 다항식 출력
void printPoly(const Polynomial& poly, string name) {
    cout << name << ": ";
    for (size_t i = 0; i < poly.size(); ++i) {
        cout << poly[i].coef << "x^" << poly[i].exp;
        if (i != poly.size() - 1) cout << " + ";
    }
    cout << endl;
}

// 다항식 덧셈
Polynomial addPolynomials(Polynomial A, Polynomial B) {
    Polynomial result;
    // 같은 차수끼리 더하고, 없는 차수는 그대로 추가
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
    // 남은 항 처리
    while (!A.empty()) {
        result.push_back(A.back());
        A.pop_back();
    }
    while (!B.empty()) {
        result.push_back(B.back());
        B.pop_back();
    }

    // 차순 정렬
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
