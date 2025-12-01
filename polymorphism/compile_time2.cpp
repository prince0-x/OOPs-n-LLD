// operator overloading 
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

class Matrix {
public:
    vector<vector<long long>> mat;
    int size;

    Matrix(int n) {
        size = n;
        mat.assign(n, vector<long long>(n, 0));
    }

    static Matrix identity(int n) {
        Matrix I(n);
        for (int i = 0; i < n; i++) I.mat[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
        return result;
    }

    
    Matrix operator^(long long power) const {
        Matrix result = Matrix::identity(size);
        Matrix base = *this;

        while (power > 0) {
            if (power & 1) result = result * base;
            base = base * base;
            power >>= 1;
        }

        return result;
    }
};

long long fibonacci(long long n) {
    if (n == 0) return 0;
    Matrix F(2);
    F.mat = {{1, 1}, {1, 0}};

    Matrix result = F ^ (n - 1);
    return result.mat[0][0];
}

int main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;
    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
