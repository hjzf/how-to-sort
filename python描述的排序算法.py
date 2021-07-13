def insertion_sort(A):
    n = len(A)
    for i in range(1, n):
        c = A[i]
        j = i-1
        while j >= 0 and A[j] > c:
            A[j+1] = A[j]
            j = j-1
        A[j+1] = c


def shell_sort(A):
    n = len(A)
    delta = int(n/2)
    while delta >= 1:
        for i in range(delta, n):
            c = A[i]
            j = i-delta
            while j >= 0 and A[j] > c:
                A[j+delta] = A[j]
                j = j - delta
            A[j+delta] = c
        delta = int(delta/2)


def bubble_sort(A):
    n = len(A)
    for order_count in range(0, n-1):
        swap = False
        for i in range(0, n-1-order_count):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                swap = True
        if swap == False:
            return


def quick_sort(A):
    def quick_sort_recursive(begin, end):
        if begin >= end:
            return
        pivot = A[begin]
        i = begin
        j = end
        while i < j:
            while i < j and pivot <= A[j]:
                j = j-1
            A[i] = A[j]
            while i < j and A[i] < pivot:
                i = i+1
            A[j] = A[i]
        A[i] = pivot
        quick_sort_recursive(begin, i-1)
        quick_sort_recursive(i+1, end)
    quick_sort_recursive(0, len(A)-1)


def selection_sort(A):
    n = len(A)
    for i in range(0, n):
        min_index = i
        for j in range(i+1, n):
            if A[j] < A[min_index]:
                min_index = j
        if min_index != i:
            A[i], A[min_index] = A[min_index], A[i]


def heap_sort(A):
    def adjust(i, j):
        while True:
            left = (i+1)*2-1
            right = (i+1)*2
            max_index = i
            if left <= j and A[left] > A[max_index]:
                max_index = left
            if right <= j and A[right] > A[max_index]:
                max_index = right
            if max_index != i:
                A[max_index], A[i] = A[i], A[max_index]
                i = max_index
            else:
                return
    n = len(A)
    for i in range(int((n+1)/2)-1, -1, -1):
        adjust(i, n-1)
    for i in range(n-1, 0, -1):
        A[0], A[i] = A[i], A[0]
        adjust(0, i-1)


def merge_sort(A):
    def merge(begin, mid, end):
        if not(begin <= mid and mid+1 <= end):
            return
        left = A[begin:mid+1]
        right = A[mid+1:end+1]
        n1 = len(left)
        n2 = len(right)
        i, j, k = 0, 0, begin
        while i < n1 or j < n2:
            if i < n1 and not j < n2 or i < n1 and left[i] <= right[j]:
                A[k] = left[i]
                i = i+1
            else:
                A[k] = right[j]
                j = j+1
            k = k+1
    n = len(A)
    delta = 1
    while delta < n:
        for i in range(0, n):
            merge(i, min(n-1, i+delta-1), min(n-1, i+2*delta-1))
        delta = delta * 2


A = [3, 5, 4, 3, 5, 6, 7, 4, 6]

selection_sort(A)

print(A)
