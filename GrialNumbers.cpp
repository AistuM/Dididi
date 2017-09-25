#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

void Grial(int a[], int n,int m)//全排列
{
    if (n == m)
    {
        int number = 0;
        for (int i = 0; i < m; i++)
        {
            number = number * 10 + a[i];
        }
        res.push_back(number);
    }
    else
    {
        for (int i = n; i < m; i++)
        {
            std::swap(a[i],a[n]);
            Grial(a,n+1,m);
            std::swap(a[i],a[n]);
        }
    }
}

int main()
{
    int n, i;
    cin >> n;
    int numbers[n];

    for(i = 0; i < n; ++i)
        cin >> numbers[i];

    bool possible[n];

    for(i = 0; i < n; ++i)
    {
        int curNum = numbers[i];
        possible[i] = false;
        int num[7];
        int j = 0;
        while(curNum)   //拆分
        {
            num[j] = curNum % 10;
            curNum /= 10;
            j++;
        }
        int k = j;  //位数

        Grial(num, 0, k);   //排列

        vector<int>::iterator iter;
        for(iter = res.begin(); iter != res.end(); iter++)
        {
            if((*iter) % numbers[i] == 0 && (*iter) != numbers[i])
            {
                possible[i] = true;
                break;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(possible[i])
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}


