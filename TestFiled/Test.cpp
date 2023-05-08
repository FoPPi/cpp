#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cout << "Enter element (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    cout << "Rows with zero elements:" << endl;

    for (int i = 0; i < rows; i++) {
        bool has_zero = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                has_zero = true;
                break;
            }
        }

        if (has_zero) {
            count++;
            cout << i << endl;
        }
    }

    cout << "Total rows with zero elements: " << count << endl;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
