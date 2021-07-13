#include <iostream>
#include <vector>
using namespace std;

//对数组A[begin,...,end] 完成快速排序
void quick_sort(int *A, int begin, int end)
{
    if (begin >= end)
        return;
    int i = begin;
    int j = end;
    int pivot = A[i]; //A[i]的值被保存，所以A[i]这个位置可被覆盖
    while (i < j)
    {
        while (i < j && pivot <= A[j])
        {
            j--;
        }
        //此时的A[j]比pivot小，应该在pivot左边
        A[i] = A[j];//不用慌,A[i]原本的值已经被寄存到pivot中了,A[j]这个位置又可以被别的东西覆盖了
        while (i < j && A[i] < pivot)
        {
            i++;
        }
        //此时的A[i]比pivot大，应该在pivot右边
        A[j] = A[i];
    }
    //此时i==j
    A[i] = pivot;
    quick_sort(A, begin, i - 1);
    quick_sort(A, i + 1, end);
}

int main(int argc, char const *argv[])
{
    vector<int> array = {3, 2, 6, 5, 8, 6, 22, 5, 778, 9};
    quick_sort(array.begin().base(), 0, array.size() - 1);
    for (auto item : array)
    {
        cout << item << "  ";
    }
    return 0;
}
