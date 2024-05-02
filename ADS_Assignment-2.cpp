#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    node *temp, *next, *new_node;
    string name;
    int age, mob_no;
    long long int donation_amt;
} a[10];

node *get_node()
{
    node *temp;
    temp = new node;
    temp = temp->next;
    return temp;
}

node *create_node()
{
    node *head, *temp, *new_node;
    string ch;
    bool flag = true;
    string name1;
    int age1, mob_no1;
    int donation_amt1;

    do
    {
        new_node = get_node();
        cout << "Enter the name of Donor : ";
        cin >> name1;
        cout << endl;

        cout << "Enter the Donor age : ";
        cin >> age1;
        cout << endl;

        cout << "Enter the Donor mobile number : ";
        cin >> mob_no1;
        cout << endl;

        cout << "Enter the Donation amount : ";
        cin >> donation_amt1;
        cout << endl;

        if (new_node == NULL)
        {
            cout << "Memory not allocated..";
        }
        else
        {
            new_node->name = name1;
            new_node->donation_amt = donation_amt1;
            new_node->mob_no = mob_no1;
            new_node->age = age1;
        }
        if (flag == true)
        {
            head = new_node;
            temp = head;
            flag = false;
        }
        else
        {
            temp = temp->next;
            temp = new_node;
        }
        cout << "Do you want to continue y or n\n";
        cin >> ch;
    } while (ch == "y");
    cout << "The singly linklist is created\n";
    
    return temp;
}

void display(node *h)
{
    node *temp = h;
    cout << "-----------------------------------------------------\n";
    cout << "Name\tAge\tMobile_no\tDonation_amount\n";
    cout << temp->name << "\t" << temp->age << "\t" << temp->mob_no << "\t" << temp->donation_amt << "\n";
    cout << "-----------------------------------------------------\n";
}

int main()
{
    node *temp;
    temp = create_node();
    display(temp);

    return 0;
}