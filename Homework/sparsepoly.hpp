#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct Term {
    int coef;
    int exp;
};

class SparsePoly {
public:
    void addTerm(int coef, int exp);
    SparsePoly operator+(const SparsePoly& rhs) const;
    void print() const;

private:
    vector<Term> terms;
};
