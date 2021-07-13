#include <iostream>
#include <vector>
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

//将有序表A[begin,..,mid]和有序表A[mid+1,...,end]合并
void merge(int *A, int begin, int mid, int end);

//对数组A[begin,...,end] 完成归并排序
void merge_sort(int *A, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    merge_sort(A, begin, mid);
    merge_sort(A, mid + 1, end);
    merge(A, begin, mid, end);
}

//对数组A[begin,...,end] 完成归并排序(非递归算法)
void merge_sort_no_recursive(int *A, int begin, int end)
{
    int n = end - begin + 1;
    for (int delta = 1; delta < n; delta = delta * 2)
    {
        for (int i = begin; i < n; i = i + delta * 2)
        {
            merge(A, i, min(end, i + delta - 1), min(end, i + 2 * delta - 1));
        }
    }
}

void merge(int *A, int begin, int mid, int end)
{
    //检验传入参数的有效性，顺便debug
    //正确的大小关系:begin<=mid<mid+1<=end
    if (!(begin <= mid && mid + 1 <= end))
    {
        cerr << "begin  is  " << begin << endl;
        cerr << "mid  is  " << mid << endl;
        cerr << "end  is  " << end << endl;
        cerr << "Parameter Error ! " << endl;
        return;
    }
    // 复制元素
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int *left = new int[n1];
    int *right = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = A[begin + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = A[mid + 1 + j];
    }
    //开始打擂;
    int i = 0;
    int j = 0;
    int k = begin;
    while (i < n1 || j < n2)
    {
        //化简后
        if (i < n1 && (!(j < n2) || left[i] <= right[j]))
        {
            A[k++] = left[i++];
        }
        else
        {
            A[k++] = right[j++];
        }
        //化简前
        // if (i < n1 && j < n2)
        // {
        //     if (left[i] <= right[j])
        //     {
        //         A[k++] = left[i++];
        //     }
        //     else
        //     {
        //         A[k++] = right[j++];
        //     }
        // }
        // else if (i < n1)
        // {
        //     A[k++] = left[i++];
        // }
        // else if (j < n2)
        // {
        //     A[k++] = right[j++];
        // }
    }
    delete[] left;
    delete[] right;
}

int main(int argc, char const *argv[])
{
    vector<int> array = {3, 2, 6, 5, 8, 6, 22, 5, 778, 9};
    merge_sort_no_recursive(array.begin().base(), 0, array.size() - 1);
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}