#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

    
#include <iostream>

#include <bits/stdc++.h>
#include "SLinkedList.h"
using namespace std;

class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
//! Cho phép lớp Polynomial truy cập vào thành viên riêng tư của Term.
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
//! Toán tử so sánh hai thuật ngữ
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
//! Toán tử xuất để in thuật ngữ ra màn hình
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
//! Danh sách các thuật ngữ của đa thức, sử dụng lớp SLinkedList.
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};




#endif // POLYNOMIAL_H