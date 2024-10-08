#include <iostream>

#include <cmath>
using namespace std;
int main()
{
    unsigned int n;
    cin >> n;
    int *b = new int[n];                //Создаем массив с массами супа
    int s=0;

    for (int i=0; i<n; i++){
        b[i] = i+1;
     }

     for(int i=0; i<n-1; i++) {       //сортируем массив по убыванию
        for( int j=i+1; j<n; j++){
            if(b[i]<b[j])
            {
                int t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
     }
    int l = (n/2)+1;                  // длина массивов для масс пети и маши, столько точно хватит в любом случае
    int *mm = new int[l];             // массив с Машиными весами
    int *mp = new int[l];             // массив с Петиными весами
    int m=0;                          // Суммарная масса Маши
    int p=0;                          // Сумарная масса Пети
    int sm=0;                         // сколько чаше перелито Маше
    int sp=0;                         // Сколько чашек перелито Пете
    
    for (int i=0; i<n;)              //Распределяем массы среди Маши и Пети.
    {
        if (m>p)                    //Маше, если у нее больше или столько же сколько и у Пети
        {                           //Пете, если у него меньше чем у Маши
            p = p + b[i];
            mp[sp]=b[i];
            sp++;
            i++;
        }
        else                        //Решила просто использовать код из лаб 3, благодаря этому осуществляю требуемый вывод 
        {
            m = m +b[i];
            mm[sm] = b[i];
            sm++;
            i++;
        }
    }



    if (m!=p){                          // Условия для требуемого вывода
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        cout << sp << endl;
        for (int i=0; i<sp; i++){
            cout << mp[i] << " ";
        }
        cout << endl;
        cout << sm << endl;
        for (int i=0; i<sm; i++){
            cout << mm[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

