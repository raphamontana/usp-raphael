/*  ===========================================*/
/*  Raphael Montanari         n° USP: 5890010  */
/*  Sort! Sort!! and Sort!!!        UVa 11321  */
/*  ===========================================*/


#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


int m;

/*  Verifica se t1 eh maior do que t2 */
bool compara(const int& t1, const int& t2)
{
    int a1 = t1 % m;
    int a2 = t2 % m;
    if (a1 > a2)
         return true;
    if (a1 < a2)
         return false;
    if (t1 % 2)                //  t1 eh um numero impar
    {
        if (t2 % 2)
             return (t1 < t2); //  t2 eh um numero impar
        else return false;         //  t2 eh um numero par
    }
    else                       //  t1 eh um numero par
    {
        if (t2 % 2)
             return true;         //  t2 eh um numero impar
        else return (t1 > t2); //  t2 eh um numero par
    }
}




int main()
{
    int n;
    vector<int> v;
    int i, aux;

    while (scanf("%d %d", &n, &m) != EOF)
    {
         printf("%d %d\n", n, m);
         if ((n == 0) && (m == 0))
              break;
         for (i = 0; i < n; i++)
         {
              scanf("%d", &aux);
              v.push_back(aux);
         }
         stable_sort(v.begin(), v.end(), compara);
         for (i = n-1         ; i >= 0; i--)
              printf("%d\n", v[i]);
         v.clear();
    }
    return 0;
}
