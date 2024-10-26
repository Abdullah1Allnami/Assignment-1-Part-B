#include <iostream>
#include <vector>
using namespace std;

int fibonacci_dynamic_programming(int n) {
    vector<int> fibo(n + 1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
}


vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    return {
                {a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1]},
                {a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1]}
    };
}

vector<vector<long long>> matrix_pow(vector<vector<long long>>& matrix, int n) {
    if (n == 0) {
        return {{1, 0}, {0, 1}}; // Identity matrix
    }
    if (n == 1) {
        return matrix;
    }

    vector<vector<long long>> half = matrix_pow(matrix, n / 2);
    vector<vector<long long>> result = multiply(half, half);

    if (n % 2 != 0) {
        result = multiply(result, matrix);
    }

    return result;
}


long long fibonacci_divide_conquer(int n) //second way using divide & conquer
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    vector<vector<long long>> matrix = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = matrix_pow(matrix, n - 1);

    return result[0][0]; // we do it because use this way fibonacci number will be in the top right
}


int fibonacci(int n) //first way using basic recursion
{
    if (n <= 0)
        return 0;
    if ( n == 1 || n == 2)
        return 1;
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}



int main()
{
    int n = 10;
    cout << "Hello World!" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl<< fibonacci_divide_conquer(5);
    cout<<endl<<fibonacci_dynamic_programming(6);

    return 0;

}