#include <iostream>
#include <vector>
using namespace std;

//对数组A[0,...,size-1] 完成希尔排序
void shell_sort(int *A, int size)
{
    for (int delta = size / 2; delta > 0; delta = delta / 2)
    {
        //这里把 0,...,delta-1 当作 %0子列,...,%(delta-1)子列 的第一个元素当作列内有序，不处理
        for (int i = 1 * delta; i <= size - 1; i++)
        {
            int current = A[i];
            int j;
            // j是i所属子列中对应i的前一个元素
            for (j = i - delta; j >= 0 && A[j] > current; j = j - delta)
            {
                A[j + delta] = A[j];
            }
            //此时j这个位置要么越界,要么A[j]<=current,因此要把current放在A[j]的右边
            A[j + delta] = current;
        }
    }
}

// //对数组A[0,...,size-1] 完成直接插入排序
// void insertion_sort(int *A, int size)
// {
//     for (int i = 1; i <= size - 1; i++)
//     {
//         int current = A[i];
//         int j;
//         //有序表A[1,..,i-1]  当前元素A[i]   无序表A[i+1,...]
//         for (j = i - 1; j >= 0 && A[j] > current; j--)
//         {
//             A[j + 1] = A[j];
//         }
//         //此时的状态:
//         //下标         j             j+1           j+2            j+3  ...
//         //        可能j为-1
//         //数据   可能A[j]<=current (>current) == (>current)  <=  (>current)
//         A[j + 1] = current;
//     }
// }

int main(int argc, char const *argv[])
{
    vector<int> array = {3, 2, 6, 5, 8, 6, 22, 5, 778, 9};
    shell_sort(array.begin().base(), array.size());
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}