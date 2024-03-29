#include <iostream>

template <typename T>
void bubble_sort(T* arr, int length) {
    bool swap;
    for (int i = 0; i < length - 1; i++) {
        swap = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
}

template <typename T>
void print_arr(T* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

template <typename T>
T* get_rand_nums(int n) {
    srand(time(0));
    T* numbers = new T[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = rand() % 10000 + 1;
    }

    return numbers;
}

int main()
{
    int length = 50;
    int* A = get_rand_nums<int>(length);
    print_arr(A, length);
    bubble_sort(A, length);
    print_arr(A, length);
    delete[] A;
}
