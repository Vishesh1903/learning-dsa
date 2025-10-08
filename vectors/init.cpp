#include <iostream>

using namespace std;

int main()
{

    vector<int> *vp = new vector<int>(); // dynamic
    vector<int> v;                       // static

    v.push_back(19);
    v.push_back(20);
    v.push_back(21);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl; // never use square bracket to initialize

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    v.pop_back();

    cout << endl;
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    delete vp;

    return 0;
}