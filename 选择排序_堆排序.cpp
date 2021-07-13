#include <iostream>
#include <vector>
using namespace std;

//最大堆调整算法：
//对于A[i,...,n],若A[i]的左子树A[2*i]、右子树A[2*i+1]都分别是最大堆，但以A[i]为根的树不是最大堆
//将以A[i]为根的树调整成最大堆
void adjust(int *A, int i, int n);

// 对列表 A[1,...,size]完成堆排序
void heap_sort(int *A, int size)
{
    int i, j, temp;
    //1.建堆
    for (i = size / 2; i >= 1; i--)
    {
        adjust(A, i, size); //将A[i,...,size]调整成最大堆
    }
    //2.排序
    for (j = size; j >= 2; j--)
    {
        temp = A[1];
        A[1] = A[j];
        A[j] = temp;
        adjust(A, 1, j - 1); //将A[1,...,j-1]调整成最大堆
        //此时A[1]是A[1,...,j-1]中的最大值
    }
}

void adjust(int *A, int i, int n)
{
    int left, right, max_index, temp;
    while (true)
    {
        left = i * 2;
        right = i * 2 + 1;
        max_index = i;
        //left<=n 代表着存在左子树
        if (left <= n && A[left] > A[max_index])
        {
            max_index = left;
        }
        if (right <= n && A[right] > A[max_index])
        {
            max_index = right;
        }
        //此时 max_index 保存着 A[i]、A[left]、A[right]这三个元素中最大值的下标
        if (max_index != i)
        {
            temp = A[max_index];
            A[max_index] = A[i];
            A[i] = temp;
            // adjust(A, max_index, n);//这是递归算法,注意去掉while(true){}
            i = max_index; //这是非递归算法，注意加上while(true){}
        }
        else
        {
            break;
        }
    }
}

//堆排序中,调整算法有两种思路:"相邻交换"(来源于冒泡排序)和"相邻挪移，最后插入"(来源于直接插入排序)的思路

int main(int argc, char const *argv[])
{
    vector<int> array = {99999999, 3, 2, 6, 5, 8, 6, 22, 5, 778, 9};
    heap_sort(array.begin().base(), array.size() - 1); //注意:array[0]这个元素不参与排序
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}
