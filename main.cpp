#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cmath>

using namespace std;

clock_t tic, toc;

void zahlenAusgeben(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void swap(int arr[], int p1, int p2)
{ // Zwei Elemente aus einem Array tauschen
    if (p1 == p2)
        return;
    int temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

void sort(int zahlen[], int groesse)
{
    // Array sortieren
    for (int i = 0; i < groesse - 1; i++)
    {
        int minIndex = i;
        for (int k = i + 1; k < groesse; k++)
        {
            if (zahlen[k] < zahlen[minIndex])
                minIndex = k;
        }
        swap(zahlen, i, minIndex);
    }
}

int main()
{
    srand(time(NULL));
    int groesse = 1;

    while (groesse != 0)
    {
        cout << "Anzahl an Zahlen eingeben\n:";
        cin >> groesse;

        int zahlen[groesse]; // Array deklarieren

        // Array füllen
        for (int i = 0; i < groesse; i++)
        {
            zahlen[i] = rand();
        }

        // zahlenAusgeben(zahlen, groesse);

        tic = clock();
        sort(zahlen, groesse);
        toc = clock();

        cout << "Rechenzeit fuer N = " << groesse << ": " << (toc - tic) / (double)CLOCKS_PER_SEC << endl;

        // zahlenAusgeben(zahlen, groesse);
    }

    return 0;
}