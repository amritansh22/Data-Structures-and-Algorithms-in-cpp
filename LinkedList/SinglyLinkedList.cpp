#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} * ptr, *head, *tail, *temp;

void insertAtFront();
void insertAtEnd();
void insertAtPos();
void deleteAtFront();
void deleteAtEnd();
void deleteAtPos();
void Traverse();
void Length();
int ele;

int main()
{
    int ch;
    do
    {
        cout << "1) Insert at front\n2) Insert at end " << endl;
        cout << "3) Insert at position\n4) Delete at front" << endl;
        cout << "5) Delete at end\n6) Delete at position" << endl;
        cout << "7) Length\n8) Traverse" << endl;
        cout << "9) Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insertAtFront();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            insertAtPos();
            break;

        case 4:
            deleteAtFront();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            deleteAtPos();
            break;

        case 7:
            Length();
            break;

        case 8:
            Traverse();
            break;

        case 9:
            exit(0);
            break;

        default:
            cout << "Invalid input, Please enter a number b/w 1 to 9." << endl;
        }
    } while (ch != 0);
    return 0;
}

void insertAtFront()
{
    ptr = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the element: ";
    cin >> ele;
    ptr->data = ele;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
        ptr->next = NULL;
        cout << "Inserted successfully.\n"
             << endl;
    }
    else
    {
        ptr->next = head;
        head = ptr;
        cout << "Inserted Successfully.\n"
             << endl;
    }
}

void insertAtEnd()
{
    ptr = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the element: ";
    cin >> ele;
    ptr->data = ele;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
        cout << "Inserted successfully.\n"
             << endl;
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
        cout << "Inserted successfully.\n\n";
    }
}

void insertAtPos()
{

    int loc;
    struct node *prev;
    ptr = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the element: ";
    cin >> ele;
    ptr->data = ele;
    cout << "Enter the location: ";
    cin >> loc;
    if (loc == 0)
    {
        cout << "0th position doesn't exist." << endl;
    }
    else if (loc == 1)
    {
        insertAtFront();
    }
    else
    {
        temp = head;
        for (int i = 1; i <= loc - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        ptr->next = temp;
        prev->next = ptr;
        cout << "Inserted successfully.\n\n";
    }
}

void deleteAtFront()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        ptr = head;
        head = ptr->next;
        cout << "Deleted successfully.\n\n";
        free(ptr);
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        temp = head;
        while (temp->next == NULL)
        {
            ptr = temp;
            temp = ptr->next;
        }
        ptr->next = NULL;
        cout << "Deleted successfully.\n\n";
        free(temp);
    }
}

void deleteAtPos()
{
    int loc;
    cout << "Enter the location: ";
    cin >> loc;
    if (loc == 0)
    {
        cout << "0th position doesn't exist." << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else if (loc == 1)
        {
            deleteAtFront();
        }
        else
        {
            temp = head;
            struct node *prev;
            for (int i = 1; i <= loc - 1; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            cout << "Deleted successfully.\n\n";
            free(temp);
        }
    }
}

void Traverse()
{
    int i = 1;
    temp = head;
    cout << "Postion\t Data" << endl;
    while (temp != NULL)
    {
        cout << i << "\t" << temp->data << endl;
        temp = temp->next;
        i++;
    }
    cout << endl;
}

void Length()
{
    int i, Count = 0;
    temp = head;
    while (temp != NULL)
    {
        Count += 1;
        temp = temp->next;
        i++;
    }
    cout << "Total no. of nodes: " << Count << "\n\n";
}