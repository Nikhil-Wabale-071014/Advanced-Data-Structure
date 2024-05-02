#include <iostream>
#define SIZE1 10

using namespace std;

class Hash
{
    struct node
    {
        int song_id;
        string song_name, singer, track, album;
        node *next, *temp;
    };
    node *a[SIZE1];

public:
    Hash()
    {
        for (int i = 0; i < SIZE1; i++)
        {
            a[i] = NULL;
        }
    }
    node *getnode()
    {
        node *temp;
        temp = new node;
        cout << "Enter Song id:" << endl;
        cin >> temp->song_id;
        cout << "Enter singer name:" << endl;
        cin >> temp->singer;
        cout << "Enter Song name:" << endl;
        cin >> temp->song_name;
        cout << "Enter Song track:" << endl;
        cin >> temp->track;
        cout << "Enter Song album:" << endl;
        cin >> temp->album;
        temp->next = NULL;
        return temp;
    }
    void insert()
    {
        int ch;
        node *ptr;
        do
        {
            node *temp = getnode();
            int mod = temp->song_id % SIZE1;

            if (a[mod] == NULL)
            {
                cout << "Inerting data at: " << mod << endl;
                a[mod] = temp;
                ptr = a[mod];
            }

            else
            {
                cout << "Collision Occured !!\n";
                ptr = a[mod];
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr = temp;
                cout << "Data linked and inserted at" << endl;
            }
            cout << "Do you want to insert more\n";
            cin >> ch;
        } while (ch == 1);
    }

    void display()
    {
        node *ptr;
        cout << "Index  \t"
             << "Song ID  \t"
             << "Singer Name  \t"
             << "Song name  \t"
             << "Song Track  \t"
             << "Song Album  \t" << endl;
        for (int i = 0; i < SIZE1; i++)
        {
            ptr = a[i];
            cout << "\n"
                 << i;
            while (ptr != NULL)
            {
                cout << "\t" << ptr->song_id << "\t\t" << ptr->singer << "\t\t" << ptr->song_name << "\t\t" << ptr->track << "\t\t" << ptr->album;
                ptr = ptr->next;
            }
        }
    }

    void search()
    {
        int key;
        node *ptr;
        cout << "Enter the song id to search\n";
        cin >> key;
        int addr = key % SIZE1;
        ptr = a[addr];
        while (ptr != NULL && ptr->song_id != key)
        {
            ptr = ptr->next;
        }
        cout << "Data found : " << ptr->song_id << endl;
        
    }
};

int main(void)
{
    Hash obj;
    int ch, choice;
    do
    {
        cout << "Menu\n";
        cout << "1.Insert\n";
        cout << "2.Display\n";
        cout << "3.Search\n";
        cout << "Enter your choice\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.search();
            break;
        }
        cout << "Do you want to continue(1/0)\n";
        cin >> choice;
    } while (choice == 1);
}