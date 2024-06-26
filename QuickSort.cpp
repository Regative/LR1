#include <iostream>
#include <cstdlib>

template<typename T>
void print_arr(T* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}
//Эта функция принимает массив arr и его длину length и выводит элементы массива на экран.
template<typename T>
int separation(T* list, int start, int end) {
    T pivot = list[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (list[j] <= pivot) {
            i += 1;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i + 1], list[end]);
    return i + 1;
}
//Функция separation разделяет массив на две части относительно опорного элемента
template<typename T>
int random_separation(T* arr, int start, int end) {
    int random_index = start + rand() % (end - start);
    std::swap(arr[random_index], arr[end]);
    return separation(arr, start, end);
}
//random_separation выбирает случайный элемент и передает его в функцию separation
template<typename T>
void quick_sort(T arr[], int start, int end) {
    if (start < end) {
        int sep = random_separation(arr, start, end);
        quick_sort(arr, start, sep - 1);
        quick_sort(arr, sep + 1, end);
    }
    else {
        return;
    }
}
//Рекурсивная функция быстрой сортировки, которая выбирает опорный элемент, разделяет массив на две части и рекурсивно вызывает себя для каждой из этих частей.
template<typename T>
T* get_rand_nums(int n) {
    T* numbers = new T[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = rand() % 10000 + 1;
    }

    return numbers;
}
//get_rand_nums создает массив случайных чисел типа T и возвращает указатель на этот массив.
int main()
{
    int length = 50;
    int* A = get_rand_nums<int>(length);
    print_arr(A, length);
    quick_sort(A, 0, length - 1);
    print_arr(A, length);
    delete[] A;
}
