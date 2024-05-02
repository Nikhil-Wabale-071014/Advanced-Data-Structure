#include <iostream>
using namespace std;

struct node
{
    node *temp, *next;
    int fuel = 0;
    string city1, city2;
};

node *getnode()
{
    node *temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}

node *create()
{
    string a[10];
    int arr_fuel[10];
    int no_of_city;
    node *temp = getnode();
    cout << "Enter the takeoff city name \n";
    cin >> temp->city1;
    cout << "Enter the no of cities connected to : " << temp->city1 << endl;
    cin >> no_of_city;
    for (int i = 0; i < no_of_city; i++)
    {
        cout << "Enter the name of cities\n";
        cin >> a[i];
        temp->city2 = a[i];
        cout << "Enter the fuel :" << endl;
        cin >> arr_fuel[i];
        temp->fuel = arr_fuel[i];
        temp = a[i+1];
    }
    return temp;
}

void display(node *ptr)
{
    cout << "TakeoffCity\t"
         << "Connected cities\t"
         << "Fuel\n";
    while (ptr != NULL)
    {
        cout << ptr->city1 << "\t\t" << ptr->city2 << "\t\t" << ptr->fuel << "\n";
        ptr = ptr->next;
    }
}

int main(void)
{
    node *head = create();
    display(head);
}