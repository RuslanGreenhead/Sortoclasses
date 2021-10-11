#include <iostream>
#include "generator.h"
#include "employee.cpp"
#include <time.h>

void BubbleSort(Employee* list, int num_of_items){
    for (int i = num_of_items - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[j] > list[j + 1])
            {
                Employee tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

void SelectSort(Employee* list, int num_of_items){
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

        Employee temp = list[i];
        list[i] = list[min_i];
        list[min_i] = temp;
    }
}

void InsertSort(Employee* list, int num_of_items){
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
}

void ShakerSort(Employee* list, int num_of_items){
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

void HeapSort(Employee* list, long num_of_items){
    long i;
    Employee tmp;

    for(i = num_of_items / 2; i >= 0; i--){
        DownHeap(list, i, num_of_items - 1);
    }

    for(i = num_of_items - 1; i > 0; i--){
        tmp = list[i];
        list[i] = list[0];
        list[0] = tmp;
        DownHeap(list, 0, i - 1);
    }
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
                Employee tmp = list[left];
                list[left] = list[right];
                list[right] = tmp;
                left++;
                right--;
            }
        }while (left <= right);

        QuickSort_base(list, first, right);
        QuickSort_base(list, left, last);
    }
}

void QuickSort(Employee* list, int num_of_items){
    QuickSort_base(list, 0, num_of_items - 1);
}


int main() {
    long double* time_intervals = new long double[6];
    //long double start, stop;

    generate_csv("dataset_1.csv", 1000);
    Employee* my_list = get_array_from_csv("dataset_1.csv", 1000);
    PrintList(my_list, 1000);

    clock_t t1 = clock();
    BubbleSort(my_list, 1000);
    clock_t t2 = clock();

    //PrintList(my_list, 100);
    std::cout << CLOCKS_PER_SEC << std::endl;
    printf("BubbleSort time: %.10lf\n", (t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}