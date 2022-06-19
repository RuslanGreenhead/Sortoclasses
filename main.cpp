#include <iostream>
#include "generator.h"
#include "employee.cpp"
#include <chrono>

double BubbleSort(Employee* list, int num_of_items){
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = num_of_items - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[j] > list[j + 1])
            {
                list[j] = list[j] ^ list[j + 1];
                list[j + 1] = list[j] ^ list[j + 1];
                list[j] = list[j] ^ list[j + 1];
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return elapsed.count() * 1e-9;
}

double SelectSort(Employee* list, int num_of_items){
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_of_items - 1; i++)
    {
        int min_i = i;
        for (int j = i + 1; j < num_of_items; j++)
        {
            if (list[j] < list[min_i])
            {
                min_i = j;
            }
        }

        list[i] = list[i] ^ list[min_i];
        list[min_i] = list[i] ^ list[min_i];
        list[i] = list[i] ^ list[min_i];
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return elapsed.count() * 1e-9;
}

double InsertSort(Employee* list, int num_of_items){
    auto start = std::chrono::high_resolution_clock::now();

    int i, j;
    Employee value;

    for(i = 1; i < num_of_items; i++)
    {
        value = list[i];
        for (j = i - 1; j >= 0 && list[j] > value; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = value;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return elapsed.count() * 1e-9;
}

double ShakerSort(Employee* list, int num_of_items){
    auto start = std::chrono::high_resolution_clock::now();

    int left, right, i;
    left = 0;
    right= num_of_items - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (list[i - 1] > list[i]) {
                swap(list[i - 1], list[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (list[i - 1] > list[i]) {
                swap(list[i - 1], list[i]);
            }
        }
        right--;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return elapsed.count() * 1e-9;
}

void DownHeap(Employee* list, long k, long n){
    long child;
    Employee new_elem = list[k];

    while(k <= n / 2){
        child = 2 * k;
        if( child < n && list[child] < list[child+1]){
            child++;
        }
        if( new_elem >= list[child]){
            break;
        }
        list[k] = list[child];
        k = child;
    }
    list[k] = new_elem;
}

double HeapSort(Employee* list, long num_of_items){
    auto start = std::chrono::high_resolution_clock::now();

    long i;

    for(i = num_of_items / 2; i >= 0; i--){
        DownHeap(list, i, num_of_items - 1);
    }

    for(i = num_of_items - 1; i > 0; i--){
        list[i] = list[i] ^ list[0];
        list[0] = list[i] ^ list[0];
        list[i] = list[i] ^ list[0];
        DownHeap(list, 0, i - 1);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return elapsed.count() * 1e-9;
}

void QuickSort_base(Employee* list, int first, int last){
    if (first < last){
        int left = first, right = last;
        Employee middle = list[(left + right) / 2];

        do{
            while (list[left] < middle) left++;
            while (list[right] > middle) right--;
            if (left <= right)
            {
                list[left] = list[left] ^ list[right];
                list[right] = list[left] ^ list[right];
                list[left] = list[left] ^ list[right];
                left++;
                right--;
            }
        }while (left <= right);

        QuickSort_base(list, first, right);
        QuickSort_base(list, left, last);
    }
}

double QuickSort(Employee* list, int num_of_items){
    auto start = std::chrono::high_resolution_clock::now();

    QuickSort_base(list, 0, num_of_items - 1);

    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return elapsed.count() * 1e-9;
}

Employee* CopyList(Employee* list, long n){
    auto* res = new Employee[n];
    for(int i = 0; i < n; i++){
        res[i] = list[i];
    }
    return res;
}

int main() {
    generate_csv("dataset_1.csv", 50000);
    Employee* my_list = get_array_from_csv("dataset_1.csv", 50000);

    for(int i = 1; i <= 10; i++){
        printf("SelectSort time (%d): %lf seconds.\n", 5000 * i, SelectSort(CopyList(my_list, 5000 * i), 5000 * i));
    }

    std::cout << std::endl;

    for(int i = 1; i <= 10; i++){
        printf("HeapSort time (%d): %lf seconds.\n", 5000 * i, HeapSort(CopyList(my_list, 5000 * i), 5000 * i));
    }

    return 0;
}