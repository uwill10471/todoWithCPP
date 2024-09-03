#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int i = 0;
class TodoNode
{
private:
    // adding new Todos differet than insertTodos() which is called only through main
    void addNewTodo(TodoNode *head)
    {
        if (head == NULL)
        {
            TodoNode *head = new TodoNode(0, u8"cooking🍽️");
            insertNode("Enter the Todos to add (-1 for exit) -> ", head);
        }
        TodoNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Add Todos (-1 to stop)" << " \n";
        while (true)
        {
            string tempToDo;

            getline(cin, tempToDo);
            if (tempToDo != "-1")
            {
                TodoNode *node = new TodoNode(++i, tempToDo);

                temp->next = node;
                temp = node;
            }
            else
            {
                return;
            }
        }
    }

    void printTodo(TodoNode *head)
    {
        TodoNode *temp = head;
        cout << "Your Todos are :" << endl;
        while (temp != NULL)
        {
            cout << temp->id << " " << temp->strVal << "\n\n";
            temp = temp->next;
        }
        return;
    }

    // update todos
    void updateTodos(TodoNode *head)
    {
        if (head == NULL)
        {
            TodoNode *head = new TodoNode(0, u8"cooking🍽️");
            insertNode("Enter the Todos to add (-1 for exit) -> ", head);
        }
        printTodo(head);
        cout << "\nType the index of Todo you want to update - \n";
        int index;
        cin >> index;
        cin.ignore(); // Ignore the newline character left in the buffer

        int c = 0;
        TodoNode *temp = head;
        while (c != index)
        {
            temp = temp->next;
            c++;
        }

        string updatedStr = "";
        cout << "Type the updated Todo - ";
        getline(cin, updatedStr);
        temp->strVal = updatedStr;
        cout << "\n****Updated Todos****\n\n";
        printTodo(head);
    }
    // removin todo at head
    void removeFirst(TodoNode *&head)
    {
        if (head == NULL)
        {
            return;
        }
        TodoNode *temp = head;
        head = head->next;
        delete temp;
    }

    // removing at a position
    void removeAtPos(TodoNode *&head, int index)
    {
        if (head == NULL)
            return;

        // If the node to be deleted is the first node
        if (head->id == index)
        {
            removeFirst(head);
            return;
        }

        TodoNode *before = head;
        TodoNode *curr = head->next;

        while (curr != NULL && curr->id != index)
        {
            before = curr;
            curr = curr->next;
        }

        if (curr == NULL)
            return; // Node with the given index not found

        before->next = curr->next;
        delete curr;
    }

    // deleting a todo
    void deleteTodos(TodoNode *head)
    {
        printTodo(head);
        cout << "\nType the index of Todo you want to Delete - \n";
        int index;
        cin >> index;
        cin.ignore(); // Ignore the newline character left in the buffer
        if (index == head->id)
        {
            removeFirst(head);
        }
        else
        {
            removeAtPos(head, index);
        }
        cout << "\n****After deletion Todos****\n\n";
        printTodo(head);
    }

public:
    int id;
    string strVal;
    TodoNode *next;

    TodoNode() : strVal("*****"), next(nullptr) {}; // this is used when we define any object

    TodoNode(int id, string s = u8"cooking🍽️")
    {
        this->id = id;
        this->strVal = s;
        this->next = NULL;
    }
    // to Perform operation as Long a use want

    void tillExitPerformOperation(TodoNode *head)
    {
        cout << "Specify the Operation you want to perform :\n";
        cout << "1. Add a new Todo (press 1) \n";
        cout << "2. Read all the Todos (press 2) \n";
        cout << "3. Update a Todo (press 3) \n";
        cout << "4. Delete a Todo (press 4) \n";
        cout << "5. Exit (press 5) \n";
        int input;
        cin >> input;
        for (int i = 0; i < 5; i++)
        {
        }
        switch (input)
        {
        case 1:
            addNewTodo(head);
            break;
        case 2:
            printTodos(head);
            break;
        case 3:
            updateTodos(head);
            break;
        case 4:
            deleteTodos(head);
            break;
        case 5: // Deleting the dynamically allocated nodes to prevent memory leak
            TodoNode *temp;
            while (head != nullptr)
            {
                temp = head;
                head = head->next;
                delete temp;
            }

            cout << "Program execution is finsihed";
            exit(0);

        default:
            cout << "\nChoose correct Value\n\n";
        }
        return;
    }

    // inserting to do until the user type -1;
    void insertNode(string s, TodoNode *head)
    {

        TodoNode *temp = head;
        cout << s << " \n";

        // cin.ignore(); //inoring the \n left by >> operator
        while (true)
        {
            string tempToDo;

            getline(cin, tempToDo);
            if (tempToDo != "-1")
            {
                TodoNode *node = new TodoNode(++i, tempToDo);

                temp->next = node;
                temp = node;
            }
            else
            {
                return;
            }
        }

    } // insert Node finish

    void printTodos(TodoNode *head)
    {
        TodoNode *temp = head;
        cout << "Your Todos are :" << endl;
        while (temp != NULL)
        {
            cout << temp->id << " " << temp->strVal << "\n\n";
            temp = temp->next;
        }
    }
};
int main()
{

    TodoNode TodoHead;
    TodoNode *head = new TodoNode(0, u8"cooking🍽️");
    TodoHead.insertNode("Enter the Todos to add (-1 for exit) -> ", head);

    while (true)
    {
        TodoHead.tillExitPerformOperation(head);
    }

    // Deleting the dynamically allocated nodes to prevent memory leak
    TodoNode *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    cout << "Program execution is finsihed";
}