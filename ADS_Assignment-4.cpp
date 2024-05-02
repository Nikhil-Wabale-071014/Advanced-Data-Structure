#include <iostream>
using namespace std;
struct node
{
    node *temp, *left, *right;
    string name, id;
    int salary;
};

node *getnode()
{
    node *temp;

    temp = new node;
    cout << "Enter the name of Employee\n";
    cin >> temp->name;
    cout << "Enter the Employee salary\n";
    cin >> temp->salary;
    cout << "Enter the Employee ID\n";
    cin >> temp->id;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *create()
{
    node *temp, *New, *root = NULL;

    int choice;

    do
    {
        New = getnode();

        if (root == NULL)
        {
            root = New;
            cout << "Inserted at root node.....\n";
        }

        else
        {
            temp = root;
            while (true)
            {

                if (New->salary < root->salary)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = New;
                        cout << "Employee data inserted at left.. \n";
                        break;
                    }

                    else
                    {
                        temp = temp->left;
                    }
                }

                else
                {
                    if (New->salary > root->salary)
                    {
                        if (temp->right == NULL)
                        {
                            temp->right = New;
                            cout << "Employee Data inserted at right..\n";
                            break;
                        }

                        else
                        {
                            temp = temp->right;
                        }
                    }
                }
            }
        }
        cout << "Do you want to continue\n";
        cin >> choice;

    } while (choice == 1);
    return root;
}

node *insert(node *root)
{
    node *New, *temp;
    int c;
    do
    {
        New = getnode();

        if (New->salary < root->salary)
        {
            if (temp->left == NULL)
            {
                temp->left = New;
                break;
            }

            else
            {
                temp = temp->left;
            }
        }

        else
        {
            if (New->salary > root->salary)
            {
                if (temp->right == NULL)
                {
                    temp->right = New;
                    break;
                }

                else
                {
                    temp = temp->right;
                }
            }
        }

        cout << "Do you want to continue(1 or 0)\n";
        cin >> c;
    } while (c == 1);
    return root;
}

void minimum_salary(node *temp)
{

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    cout << "Name:" << temp->name << "\t"
         << "Salary:" << temp->salary << "\t"
         << "ID:" << temp->id << endl;
}

void maximum_salary(node *temp)
{

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    cout << "Name:" << temp->name << "\t"
         << "Salary:" << temp->salary << "\t"
         << "ID:" << temp->id << endl;
}

node *delete_all(node *temp)
{
//     temp = NULL;
//     if (temp->left != NULL)
//         delete_all(temp->left);
//     if (temp->right != NULL)
//         delete_all(temp->right);
    delete temp;
    return NULL;
}

node *find_employee(node *temp, int key)
{
    if (temp == NULL)
    {
        return NULL;
    }

    if (temp->salary == key)
    {
        cout << "Data found..\n";
        cout << "Name:" << temp->name << "\t"
             << "Salary:" << temp->salary << "\t"
             << "ID:" << temp->id << endl;
    }
    if (key < temp->salary)
        find_employee(temp->left, key);
    else
        find_employee(temp->right, key);
}


node* delete_specific_data(node *temp,int key)
{

}
void inorder_display(node *temp)
{
    if (temp == NULL)
    {
        cout << "Empty Tree\n";
        return;
    }

    else
    {
        if (temp->left != NULL)
            inorder_display(temp->left);
        cout << "Name:" << temp->name << "\t"
             << "Salary:" << temp->salary << "\t"
             << "ID:" << temp->id << endl;
        if (temp->right != NULL)
            inorder_display(temp->right);
    }
}

void preorder_display(node *temp)
{
    if (temp == NULL)
    {
        cout << "Empty Tree\n";
        return;
    }

    else
    {
        cout << "Name:" << temp->name << "\t"
             << "Salary:" << temp->salary << "\t"
             << "ID:" << temp->id << endl;
        if (temp->left != NULL)
            inorder_display(temp->left);
        if (temp->right != NULL)
            inorder_display(temp->right);
    }
}

void postorder_display(node *temp)
{
    if (temp == NULL)
    {
        cout << "Empty Tree\n";
        return;
    }

    else
    {
        if (temp->left != NULL)
            inorder_display(temp->left);
        if (temp->right != NULL)
            inorder_display(temp->right);

        cout << "Name:" << temp->name << "\t"
             << "Salary:" << temp->salary << "\t"
             << "ID:" << temp->id << endl;
    }
}
int main(void)
{
    node *root = create();
    int choice, ch;
    do
    {
        cout << "Menu\n";
        cout << "1.Insert data.\n";
        cout << "2.Employes with minimum salary.\n";
        cout << "3.Employes with maxmium salary.\n";
        cout << "4.Delete all record.\n";
        cout << "5.Find employee data.\n";
        cout << "6.Delete individual employee data.\n";
        cout << "7.Inorder display.\n";
        cout << "8.Preorder display.\n";
        cout << "9.Postoder display.\n";

        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            minimum_salary(root);
            break;
        case 3:
            maximum_salary(root);
            break;
        case 4:
            root = delete_all(root);
            if (root == NULL)
                cout << "Record deleted Successfully..\n";
            break;
        case 5:
            int x;
            cout << "Enter the salary to search\n";
            cin >> x;
            find_employee(root, x);
            break;
        case 6:
            int r;
            cout<<"Enter the salary to delete the data\n";
            cin>>r
            delete_specific_data(root,r);
            break;
        case 7:
            inorder_display(root);
            break;
        case 8:
            preorder_display(root);
            break;
        case 9:
            postorder_display(root);
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
        cout << "Do you want to continue\n";
        cin >> ch;
    } while (ch == 1);
}