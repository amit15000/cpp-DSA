#include <iostream>
using namespace std;
class Heap
{
private:
    /* data */
public:
    int arr[100];
    int size;

    Heap()
    {
        size = -1;
    }
    void createHeap()
    {
        int data;
        cin >> data;
        while (data != -1)
        {
            insertInHeap(data);
            cin >> data;
        }
    }
    void insertInHeap(int data)
    {
        size += 1;
        int index = size;
        arr[index] = data;
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
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
};
void printHeap(int arr[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}
void deleteFromHeap(int arr[], int &size)
{
    arr[0] = arr[size--];
    heapify(arr, size, 0);
}

int main()
{
    // Heap h;
    // h.createHeap();
    // h.printHeap();

    // heapify ALgorithm

    int arr[] = {12, 4, 6, 20, 14, 10, 11, 15, 10, 11};

    int size = sizeof(arr) / sizeof(int) - 1;
    cout << "Given Array : ";
    printHeap(arr, size);
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    cout << "After Heapify : ";
    printHeap(arr, size);

    // delete from heap ==>root ==>arr[0] ko delete karna hai

    deleteFromHeap(arr, size);
    cout << "After Delete : ";
    printHeap(arr, size);
    deleteFromHeap(arr, size);
    cout << "After Delete : ";
    printHeap(arr, size);
}