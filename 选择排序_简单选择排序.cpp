#include <iostream>
#include <vector>
using namespace std;

//对数组A[0,...,size-1] 完成简单选择排序
void selection_sort(int *A, int size)
{
    int min_index, temp, i, j;
    for (j = 0; j < size - 1; j++)
    {
        //1.挑选
        min_index = j; //min_index用于保存最小值对应的下标
        for (i = j + 1; i < size; i++)
        {
            if (A[i] < A[min_index])
            {
                min_index = i;
            }
        }
        //此时, min_index保存着A[j+1,...,size-1]这些元素中最小值的下标
        //2.交换：把A[min_index]放到j号位置
        if (min_index != j)
        {
            temp = A[j];
            A[j] = A[min_index];
            A[min_index] = temp;
        }
    }
}

// //对数组A[0,...,size-1] 完成简单选择排序
// void selection_sort_old(int *A, int size)
// {
//     int min_value, min_index, temp, i, j;
//     for (j = 0; j < size - 1; j++)
//     {
//         //1.挑选
//         min_value = 99999; //把99999当作无穷大
//         min_index = -1;    //min_index用于保存min_value对应的下标
//         for (i = j; i < size; i++)
//         {
//             if (A[i] < min_value)
//             {
//                 min_value = A[i];
//                 min_index = i;
//             }
//         }
//         //此时, min_index保存着A[j,...,size-1]这些元素中最小值的下标
//         //2.交换：把min_value放到j号位置
//         temp = A[j];
//         A[j] = A[min_index];
//         A[min_index] = temp;
//     }
// }

//简单选择排序:在选择完毕后，如果采用的是 "交换" 操作，则不稳定
//                         如果采用的是 "相邻挪移，最后插入"操作，则稳定

int main(int argc, char const *argv[])
{
    vector<int> array = {3, 2, 6, 5, 8, 6, 22, 5, 778, 9};
    selection_sort(array.begin().base(), array.size());
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}
