#include "HashTable.h"
#include <chrono>
using namespace chrono;


// Uses pivot to partition array and sort around partition
int Partition(int arr[], int high, int low)
{
    int pivot = high;
    int up = high, down = low;

    while(down < up)
    {

        while (arr[down] < arr[pivot])
            down++;

        while (arr[up] > arr[pivot])
            up--;

        if (down < up)
        {
            int temp = arr[up];
            arr[up] = arr[down];
            arr[down] = temp;
        }
    }

    int temp = down;
    down = up;
    up = temp;
    return pivot;
}

// Recursive function that sorts array
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(arr, high, low);
        QuickSort(arr, pivot + 1, high);
        QuickSort(arr, low, pivot - 1);
    }

}


void Heapify(int arr[], int length, int j)
{
    int temp = arr[j];
    int i = 2*j + 1;
    while (i < length) {
        if (i + 1 < length && arr[i] > arr[i + 1]) // choose the least value
            ++i;
        if (temp < arr[i])
        {
            break;
        }
        arr[j] = arr[i];
        j = i; //keep searching
        i = 2*j + 1;
    }
    arr[j] = temp;
}

void HeapSort(int arr[], int length)
{
    if (length <= 0)
        return;
    for (int i = length / 2 - 1; i >= 0; i--) {
        Heapify(arr, length, i);
    }
    for (int i = length - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}



int main()
{
    string userSelection;
    int heapArr[100000];
    int quickArr[100000];
    int optionInput;
    HashTable table;
    HashTable heapTable;
    HashTable quickTable;
    table.buildTable();
    heapTable.buildArray(heapArr);
    heapTable.buildArray(quickArr);


    cout << "[1] Get Covid Data \n[2] Compare Sorting Times\nSelect an option:\n";
    cin >> optionInput;
    if (optionInput == 1)
    {
        cout << "Data from state or county? [type state/county]\n";
        cin >> userSelection;

        if (userSelection == "state" || userSelection == "State")
        {
            string state;
            cout << "Type in the State:\n";
            cin >> state;
            table.searchStates(state);

        }
        else if (userSelection == "county" || userSelection == "County")
        {
            string county;
            cout << "Type in the County:\n";
            cin >> county;
            table.searchCounties(county);
        }
    }
    else if (optionInput == 2)
    {
        auto start = high_resolution_clock::now();
        HeapSort(heapArr,100000);
        auto stop = high_resolution_clock::now();
        auto heapDuration = duration_cast<microseconds>(stop - start);
        cout << "Time of Heap sort: " << heapDuration.count() << " microseconds."<< endl;

        start = high_resolution_clock::now();
        QuickSort(quickArr,0,100000);
        stop = high_resolution_clock::now();
        auto quickDuration = duration_cast<microseconds>(stop - start);
        cout << "Time of Quick sort: " << quickDuration.count() << " microseconds."<< endl;
    }

    return 0;
}

