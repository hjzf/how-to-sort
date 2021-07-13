#include <iostream>
#include <vector>
using namespace std;

//对数组A[0,...,size-1] 完成冒泡排序
void bubble_sort(int *A, int size)
{
    for (int ordered_count = 0; ordered_count <= size - 2; ordered_count++)
    {
        bool swap = false;
        for (int j = 0; j <= size - 2 - ordered_count; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swap = true;
            }
        }
        //提前结束,实际的趟数可能小于n
        if (swap == false)
            return;
    }
}

//冒泡排序为我们提供了一种 "相邻交换" 的思路

int main(int argc, char const *argv[])
{
    vector<int> array = {3, 2, 6, 5, 8, 6, 22, 5, 778, 9, 33, 45, 6, 88, 5, 3, 2, 66, 78, 5};
    bubble_sort(array.begin().base(), array.size());
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}