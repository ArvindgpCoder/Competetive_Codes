#include <iostream>
using namespace std;

const int MAXN = 1000;
int BIT[MAXN];
int N;

void update(int i, int val)
{
    ++i;
    while (i <= N)
    {
        BIT[i] += val;
        i += (i & -i);
    }
}

int query(int i)
{
    ++i;
    int res = 0;
    while (i > 0)
    {
        res += BIT[i];
        i -= (i & -i);
    }
    return res;
}

int main()
{
    N = 8;
    update(3, 5);
    cout << "Sum from start to position 5: " << query(5) << endl;
    return 0;
}
