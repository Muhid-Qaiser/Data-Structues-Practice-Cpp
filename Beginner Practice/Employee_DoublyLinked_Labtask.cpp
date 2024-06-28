#include <iostream>
using namespace std;

class Employee
{
public:
    string id;
    string cnic;
    string joiningdate;
    int salary;
    int bonus;
    Employee *next;
    Employee *prev;

    Employee(string id, string cnic, string joiningdate, int salary, int bonus) : id(id), cnic(cnic), joiningdate(joiningdate), salary(salary), bonus(bonus)
    {
        next = NULL;
        prev = NULL;
    }
};

class Database
{
    Employee *head;

public:
    Database()
    {
        head = NULL;
    }

    bool isEmpty() const { return head; }

    void insert(string id, string cnic, string joiningdate, int salary, int bonus)
    {
        Employee *newEmployee = new Employee(id, cnic, joiningdate, salary, bonus);

        if (!head)
        {
            head = newEmployee;
            newEmployee->next = newEmployee;
            newEmployee->prev = newEmployee;
        }
        else
        {
            newEmployee->next = head;
            newEmployee->prev = head->prev;
            head->prev->next = newEmployee;
            head->prev = newEmployee;
        }
    }

    void display()
    {
        cout << "\nStraight: ";
        Employee *temp = head;

        do
        {
            cout << temp->id << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\nReverse: ";
        temp = head->prev;

        do
        {
            cout << temp->id << " ";
            temp = temp->prev;
        } while (temp != head->prev);
    }

    bool search(string findID)
    {
        Employee *temp = head;
        bool flag = false;

        do
        {
            if (temp->id == findID)
            {
                flag = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (flag)
            cout << temp->id << " " << temp->cnic << endl;
        else
            cout << "ID NOT FOUND" << endl;
        return flag;
    }

    bool remove(string findID)
    {
        Employee *temp = head;
        Employee *temp2 = NULL;
        Employee *prev = head->prev;
        bool flag = false;

        do
        {
            if (temp->id == findID)
            {
                flag = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (flag)
        {
            temp2 = temp;
            prev->next = temp->next;
            temp->next->prev = prev;
            temp = temp->next;
            cout << temp2->id << " " << temp2->cnic << endl;
            temp2->next = NULL;
            temp2->prev = NULL;
            delete temp2;
            return flag;
        }
        else
            cout << "ID NOT FOUND" << endl;
    }
};

int main()
{
    Database db;

    db.insert("1000", "9040", "01/01/2020", 1000, 50);
    db.insert("1001", "9041", "01/01/2020", 1000, 50);
    db.insert("1002", "9042", "01/01/2020", 1000, 50);
    db.insert("1003", "9043", "01/01/2020", 1000, 50);
    db.display();

    cout << endl;
    db.search("1001");

    db.remove("100");
    db.display();

    return 0;
}