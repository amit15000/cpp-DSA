#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertInHeap(int key)
    {
        size += 1;
        int index = size;
        arr[index] = key;

        while (index > 1)
        {

            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteInHeap()
    {
        // deletion root se

        // replace last element with root
        arr[1] = arr[size];

        // remove last elemet
        size--;
        int index = 1;
        while (index < size)
        {
            int leftChild = size * 2;
            int rightChild = size * 2 + 1;

            if (index < size && arr[index] > arr[leftChild])
            {
                swap(arr[index], arr[leftChild]);
                index = leftChild;
            }
            else if (index < size && arr[index] < arr[rightChild])
            {
                swap(arr[index], arr[rightChild]);
            }
            else
            {
                return;
            }
        }
    }
};

void insertInHeap(Heap &h)
{
    int key;
    cin >> key;
    while (key != -1)
    {
        h.insertInHeap(key);
        cin >> key;
    }
}
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftindex = 2 * i;
    int rightindex = 2 * i + 1;

    if (leftindex <= size && arr[largest] < arr[leftindex])
    {
        largest = leftindex;
    }
    if (rightindex <= size && arr[largest] < arr[rightindex])
    {
        largest = rightindex;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    int n = size;
    while (n > 1)
    {
        swap(arr[n], arr[1]);
        n--;

        heapify(arr, n, 1);
    }
}

void printArr(int arr[], int n)
{

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Heap h;
    // insertInHeap(h);
    // h.printHeap();
    // h.deleteInHeap();
    // h.printHeap();

    // heapyfi
    int arr[] = {-1, 4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(int) - 1;

    // heap creation
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "After Heapify :";
    printArr(arr, n);

    // heapSort
    heapSort(arr, n);
    cout << "After Heapsort :";
    printArr(arr, n);
}
