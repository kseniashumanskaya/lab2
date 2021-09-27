
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int size;
    cout << "enter the size of the array:" << endl;
    cin >> size;
    double* arr = new double[size];
    cout << " enter 0 if you want to fill the array with random numbers and 1 - from consol" << endl;
    int array_filling_option;
    cin >> array_filling_option;
    if (array_filling_option == 0) {
        srand(time(0));
        for (int i = 0; i < size; i++) {
            arr[i] = (float)(rand() % 10000 - 5000) / 100;
            cout << arr[i] << "\t";
            cout << arr + i << endl;
        }
    }
    else {
        cout << "enter array elements:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
            cout << arr + i << endl;
        }
    }

    for (int i = 1; i < size - 1; i++)
    {
        if ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))
            cout << i + 1 << " : local min = " << arr[i] << endl;
    }
    double min = arr[0];
    int number_of_min_element = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            number_of_min_element = i;
        }
    }
    double sum = 0;
    for (int i = number_of_min_element + 1; i < size; i++)
        sum += arr[i];
    cout << "sum = " << sum << endl;

    for (int j = 0; j < size; j++)
        for (int i = 0; i < size - 1; i++)
            if (abs(arr[i]) > abs(arr[i + 1]))
                swap(arr[i], arr[i + 1]);

    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;

    delete[] arr;
}
