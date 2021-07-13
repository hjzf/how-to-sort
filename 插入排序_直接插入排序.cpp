#include <iostream>
#include <vector>
using namespace std;

//对数组A[0,...,size-1] 完成直接插入排序
void insertion_sort(int *A, int size)
{
    //这里的下标之所以从1开始，是因为0号元素只有一个，天然有序
    for (int i = 1; i <= size - 1; i++)
    {
        int current = A[i];
        int j;
        //有序表A[1,..,i-1]  当前元素A[i]   无序表A[i+1,...]
        for (j = i - 1; j >= 0 && A[j] > current; j--)
        {
            A[j + 1] = A[j];
        }
        //此时的状态:
        //下标         j             j+1           j+2            j+3  ...
        //        可能j为-1
        //数据   可能A[j]<=current (>current) == (>current)  <=  (>current)
        A[j + 1] = current;
    }
}

//直接插入排序 为我们提供了一种 "相邻挪移，最后插入" 的思路

int main(int argc, char const *argv[])
{
    vector<int> array = {3, 2, 6, 5, 8, 6, 22, 5, 778, 9};
    insertion_sort(array.begin().base(), array.size());
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}