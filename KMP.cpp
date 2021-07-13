#include <iostream>
using namespace std;
int KMP(const char *s, const char *p)
{
    int n1 = 0;
    while (s[n1] != '\0')
        n1++;
    int n2 = 0;
    while (p[n2] != '\0')
        n2++;
    int *next = new int[n2];
    next[0] = -1;
    int j = -1;
    int i = 0;
    while (i < n2 - 1)
    {
        if (j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            // next[i]=j;//next数组
            if (p[i] != p[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
        {
            j = next[j];
        }
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    delete[] next;
    if (j == n2)
        return i - n2;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    cerr << KMP("abcddbggdd", "bggd") << endl;
    return 0;
}