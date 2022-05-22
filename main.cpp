
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int len = 0;
    int arr[100];
    string str;
    int para1, para2;

    while (1)
    {
        try
        {
            cin >> str;
            int v = stoi(str);
            arr[len++] = v;
        }
        catch (...)
        {
            break;
        }
    }
    cin >> para1 >> para2;

    LinkedList ll(arr, len);
    
    if (str == "AF")
    {
        ll.addFront(para1);
    }

    if (str == "AE")
    {
        ll.addEnd(para1);
    }

    if (str == "AP")
    {
        ll.addAtPosition(para1, para2);
    }

    if (str == "S")
    {
        ll.search(para1);
    }

    if (str == "DF")
    {
        ll.deleteFront();
    }

    if (str == "DE")
    {
        ll.deleteEnd();
    }

    if (str == "DP")
    {
        ll.deletePosition(para1);
    }

    if (str == "GI")
    {
        ll.getItem(para1);
    }

    ll.printItems();
}
