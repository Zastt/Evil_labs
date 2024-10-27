#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

double performCalculation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b != 0) return a / b;
        else {
            cout << "error: division by zero!" << endl;
            exit(1);
        }
    default:
        cout << "invalid operation!" << endl;
        exit(1);
    }
}

void extractExpression(const string& expr, vector<double>& values, vector<char>& ops) {
    stringstream ss(expr);
    double val;
    char op;

    ss >> val;
    values.push_back(val);

    while (ss >> op) {
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "error: invalid operation!" << endl;
            exit(1);
        }
        ops.push_back(op);

        ss >> val;
        values.push_back(val);
    }
}

int main() {
    string expr;

    cout << "enter the expression: ";
    cin >> expr;

    vector<double> values;
    vector<char> ops;

    extractExpression(expr, values, ops);

    vector<double> calc_values;
    vector<char> calc_ops;

    calc_values.push_back(values[0]);

    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '*' || ops[i] == '/') {
            double intermediate_result = performCalculation(calc_values.back(), values[i + 1], ops[i]);
            calc_values.back() = intermediate_result;
        }
        else {
            calc_values.push_back(values[i + 1]);
            calc_ops.push_back(ops[i]);
        }
    }

    double final_result = calc_values[0];
    for (int i = 0; i < calc_ops.size(); ++i) {
        final_result = performCalculation(final_result, calc_values[i + 1], calc_ops[i]);
    }

    cout << "final result: " << final_result << endl;

    return 0;
}
