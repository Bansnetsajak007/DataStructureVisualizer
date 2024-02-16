/*
    (yeslai ek din majaley basharw garxu)
    (banauna chai babal nai banauxuu
    )
    TO-DOs: 
    1) Implementation of arrays sorting algorith
    2) Proper memory management
    3) Displaying Tree in proper format

    sorting algorithms should not make change on original array
    time of every algorithm should be calculated effectively 

    will see this
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

// Base class for data structures
class DataStructure {
public:
    virtual void display() const = 0;
    virtual void performOperations() = 0;
};

// Array class
#include <iostream>
#include <ctime>

using namespace std;


class Array : public DataStructure {
private:
    vector<int> a;
    public:
    
    template<typename ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last) {
    if (first == last) {
        // If the range is empty, return last
        return last;
    }

    ForwardIterator max_it = first;
    ++first;

    // Iterate through the range to find the maximum element
    while (first != last) {
        if (*first > *max_it) {
            // If the current element is greater than the current max, update max_it
            max_it = first;
        }
        ++first;
    }

    return max_it;
}

    void display() const {
        if (a.empty()) {
            cout << "\n Array is Empty....\n\n";
            return;
        }

        cout << "\n Current Array is : \n";
        cout << "\n\t[ ";

        for (size_t i = 0; i < a.size() - 1; i++) {
            cout << a[i] << ", ";
        }

        cout << a[a.size() - 1] << " ]\n\n";

        cout << " Size of Array: " << a.size() << "\n\n";
    }

    void performOperations() {
        int choice;
        do {
            cout << "\n\n Array Operations ::\n";
            cout << " 1 : Create Array\n 2 : Display\n 3 : Insert\n 4 : Delete Element\n 5 : Sorting Options\n 6 : Back to Main Menu\n";
            cout << "\n Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createArray();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    insertElement();
                    break;
                case 4:
                    deleteElement();
                    break;
                case 5:
                    selectionSort();
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 6);
    }

private:
    void createArray() {
        size_t size;
        cout << "\n Enter the number of elements in array : ";
        cin >> size;
        a.resize(size);

        cout << "\n Enter the elements : \n\n";

        for (size_t i = 0; i < size; i++) {
            cout << "\n Enter element " << i + 1 << " : ";
            cin >> a[i];
        }

        cout << "\n\n";
    }

    void insertElement() {
        int elem;
        cout << "\n Enter the value to be inserted : ";
        cin >> elem;
        a.push_back(elem);

        cout << "\n Element Inserted Successfully !!!";
        cout << "\n\n";
    }

    void deleteElement() {
        if (a.empty()) {
            cout << "\n Array is Empty.... Element can not be Deleted.\n\n";
            return;
        }

        size_t arrayPos;
        cout << "\n Enter a valid position to delete an Element from Array : ";
        cin >> arrayPos;

        if (arrayPos >= a.size()) {
            cout << "\n Given Position is Invalid...Element can not be deleted. ";
            return;
        }

        a.erase(a.begin() + arrayPos);

        cout << "\n Element Deleted Successfully !!!";

        cout << "\n\n";

        display();
    }

    void selectionSort() {
        clock_t tStart = clock();

        for (size_t i = 0; i < a.size() - 1; i++) {
            size_t min_index = i;
            for (size_t j = i + 1; j < a.size(); j++) {
                if (a[j] < a[min_index]) {
                    min_index = j;
                }
            }
            swap(a[i], a[min_index]);
        }

        cout << " Time taken for Selection sort : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
    }
};



// Node class for Linked List
class Node {
public:
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// Linked List class
class LinkedList : public DataStructure {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void display() const override {
        bool flag = true;

        clock_t tStart = clock();

        if (!head) {
            cout << "\n Linked list is Empty.....\n";
        } else {
            cout << "\n\n │ Current Linked List │\n\n\n";
            cout << "\n    ";

            Node* ptr = head;
            while (ptr != nullptr) {
                if (ptr->next) {
                    if (flag) {
                        cout << "Head --->〔 " << ptr->data << "|● 〕" << "--->";
                    } else {
                        cout << "〔 " << ptr->data << "|● 〕" << "--->";
                    }
                } else {
                    cout << "〔 " << ptr->data << "|● 〕---> NULL";
                }

                flag = false;
                ptr = ptr->next;
            }

            cout << "\n\n\n\n\n";
            cout << " Time taken for Traversal : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
        }
    }

    void performOperations() override {
        int choice;
        do {
            cout << "\n\n Linked List Operations ::\n";
            cout << " 1 : Visualise\n 2 : Insert\n 3 : Delete\n 4 : Search\n 5 : Back to Main Menu\n";
            cout << "\n Enter your choice of Operation : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    display();
                    break;
                case 2:
                    insertElement();
                    break;
                case 3:
                    deleteElement();
                    break;
                case 4:
                    searchElement();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 5);
    }

private:
    void insertElement() {
        int value;
        cout << "\n Enter Node Element: ";
        cin >> value;

        clock_t tStart = clock();

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "\n Element Inserted Successfully !!!";
        cout << "\n\n";
        cout << " Time taken in Insertion : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    void deleteElement() {
        if (!head) {
            cout << "\n Linked list is Empty.... Element can not be Deleted.\n\n";
            return;
        }

        int value;
        cout << "\n Enter Element to be Deleted: ";
        cin >> value;

        clock_t tStart = clock();

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (!current) {
            cout << "\n Element not found in Linked List.\n\n";
            return;
        }

        if (previous) {
            previous->next = current->next;
        } else {
            head = current->next;
        }

        delete current;

        cout << "\n Element Deleted Successfully !!!\n\n";
        cout << " Time taken in Deleting : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    void searchElement() const {
        if (!head) {
            cout << "\n Linked list is Empty....\n\n";
            return;
        }

        int value;
        cout << "\n Enter Element to be Searched: ";
        cin >> value;

        clock_t tStart = clock();

        Node* current = head;
        int position = 0;

        while (current != nullptr && current->data != value) {
            current = current->next;
            position++;
        }

        if (!current) {
            cout << "\n Element not found in Linked List.\n\n";
        } else {
            cout << "\n Element found at position: " << position << "\n\n";
        }

        cout << " Time taken in Searching : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
    }
};

// Stack class
class Stack : public DataStructure {
private:
    int s[100];
    int top;

public:
    Stack() : top(-1) {}

    void display() const override {
        if (top == -1) {
            cout << "\n Stack is Empty....\n\n";
            return;
        }

        cout << "\n\n Current Stack is : \n";
        cout << "\n\n\t-------------------------";
        cout << "\n\t|  ";

        for (int i = top; i > 0; i--) {
            cout << "［" << s[i] << "］|\n\t|  ";
        }

        cout << "(" << s[0] << ")|";
        cout << "\n\t-------------------------";
        cout << "\n\n\n\n";
    }

    void performOperations() override {
        int choice;
        do {
            cout << "\n\n Stack Operations ::\n";
            cout << " 1 : Display\n 2 : Push\n 3 : Pop\n 4 : Peek\n 5 : Back to Main Menu\n";
            cout << "\n Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    display();
                    break;
                case 2:
                    push();
                    break;
                case 3:
                    pop();
                    break;
                case 4:
                    peek();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 5);
    }

private:
    void push() {
        if (top == 99) {
            cout << "\n Size Allocated to Stack is Full....\n\n";
            return;
        }

        int value;
        cout << "\n Enter value to be Pushed : ";
        cin >> value;

        clock_t tStart = clock();

        top = top + 1;
        s[top] = value;

        cout << "\n Element Pushed Successfully !!!";
        cout << "\n\n";
        cout << " Time taken in Pushing : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    void pop() {
        if (top == -1) {
            cout << "\n Stack is Empty.... Element can not be Popped.\n\n";
            return;
        }

        clock_t tStart = clock();

        cout << "\n Element Popped is : " << s[top];
        top = top - 1;

        cout << "\n\n";
        cout << " Time taken in Popping : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    void peek() const {
        if (top == -1) {
            cout << "\n Stack is Empty....\n\n";
            return;
        }

        cout << "\n Topmost Element in Stack is : " << s[top] << "\n\n";
    }
};

// Queue class
class Queue : public DataStructure {
private:
    int q[100];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    void display() const override {
        if (front == -1) {
            cout << "\n Queue is Empty....\n\n";
            return;
        }

        cout << "\n\n Current Queue is : \n";
        cout << "\n\n\t-------------------------";
        cout << "\n\t|  ";

        for (int i = front; i <= rear; i++) {
            cout << "［" << q[i] << "］|\n\t|  ";
        }

        cout << "\n\t-------------------------";
        cout << "\n\n\n\n";
    }

    void performOperations() override {
        int choice;
        do {
            cout << "\n\n Queue Operations ::\n";
            cout << " 1 : Display\n 2 : Enqueue\n 3 : Dequeue\n 4 : Front Element\n 5 : Back to Main Menu\n";
            cout << "\n Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    display();
                    break;
                case 2:
                    enqueue();
                    break;
                case 3:
                    dequeue();
                    break;
                case 4:
                    frontElement();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 5);
    }

private:
    void enqueue() {
        if (rear == 99) {
            cout << "\n Size Allocated to Queue is Full....\n\n";
            return;
        }

        int value;
        cout << "\n Enter value to be Enqueued : ";
        cin >> value;

        clock_t tStart = clock();

        if (front == -1) {
            front = 0;
        }

        rear = rear + 1;
        q[rear] = value;

        cout << "\n Element Enqueued Successfully !!!";
        cout << "\n\n";
        cout << " Time taken in Enqueuing : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    void dequeue() {
        if (front == -1) {
            cout << "\n Queue is Empty.... Element can not be Dequeued.\n\n";
            return;
        }

        clock_t tStart = clock();

        cout << "\n Element Dequeued is : " << q[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }

        cout << "\n\n";
        cout << " Time taken in Dequeuing : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    void frontElement() const {
        if (front == -1) {
            cout << "\n Queue is Empty....\n\n";
            return;
        }

        cout << "\n Front Element in Queue is : " << q[front] << "\n\n";
    }
};

// Binary Search Tree (BST) Node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) class
class BinarySearchTree : public DataStructure {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void printTree(TreeNode* root , int indent = 0) {
        if(root != nullptr)  {
            if(root->right) printTree(root->right, indent + 4);
            if(indent) cout << setw(indent) << ' ';
            if (root->right) cout << " /\n" << setw(indent) << ' ';
            cout << root->data << "\n ";
            if (root->left) {
                cout << setw(indent) << ' ' << " \\\n";
                printTree(root->left, indent + 4);
        }
        }
    }

    void display() const override {
        if (!root) {
            cout << "\n Binary Search Tree is Empty....\n\n";
            return;
        }

        cout << "\n\n Binary Search Tree (In-order Traversal) ::\n";
        cout << "\n\n\t";

        clock_t tStart = clock();
        inOrderTraversal(root);
        cout << "\n\n";

        cout << " Time taken for Traversal : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
    }

    void performOperations() override {
        int choice;
        do {
            cout << "\n\n Binary Search Tree (BST) Operations ::\n";
            cout << " 1 : Insert\n 2 : Delete\n 3 : Search\n 4 : Display\n 5 : Back to Main Menu\n";
            cout << "\n Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertNode();
                    break;
                case 2:
                    deleteNode();
                    break;
                case 3:
                    searchNode();
                    break;
                case 4:
                    printTree(root);
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 5);
    }

private:
    void inOrderTraversal(TreeNode* node) const {
        if (node) {
            inOrderTraversal(node->left);
            cout << "(" << node->data << ")--";
            inOrderTraversal(node->right);
        }
    }

    void insertNode() {
        int value;
        cout << "\n Enter Node Element to be Inserted in BST : ";
        cin >> value;

        clock_t tStart = clock();

        root = insertRecursive(root, value);

        cout << "\n Element Inserted Successfully !!!";
        cout << "\n\n";
        cout << " Time taken in Insertion : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    void deleteNode() {
        if (!root) {
            cout << "\n Binary Search Tree is Empty.... Element can not be Deleted.\n\n";
            return;
        }

        int value;
        cout << "\n Enter Node Element to be Deleted from BST : ";
        cin >> value;

        clock_t tStart = clock();

        root = deleteRecursive(root, value);

        cout << "\n Element Deleted Successfully !!!";
        cout << "\n\n";
        cout << " Time taken in Deletion : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        display();
    }

    TreeNode* deleteRecursive(TreeNode* node, int value) {
        if (!node) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }

        return node;
    }

    TreeNode* findMin(TreeNode* node) const {
        while (node->left) {
            node = node->left;
        }

        return node;
    }

    void searchNode() const {
        if (!root) {
            cout << "\n Binary Search Tree is Empty....\n\n";
            return;
        }

        int value;
        cout << "\n Enter Node Element to be Searched in BST : ";
        cin >> value;

        clock_t tStart = clock();

        if (searchRecursive(root, value)) {
            cout << "\n Element found in BST.\n\n";
        } else {
            cout << "\n Element not found in BST.\n\n";
        }

        cout << " Time taken in Searching : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
    }

    bool searchRecursive(TreeNode* node, int value) const {
        if (!node) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
};

int main() {
    int choice;
    DataStructure* dataStructure = nullptr;

    do {
        cout << "\n\n Data Structure Menu ::\n";
        cout << " 1 : Array\n 2 : Linked List\n 3 : Stack\n 4 : Queue\n 5 : Binary Search Tree\n 6 : Exit\n";
        cout << "\n Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                dataStructure = new Array();
                dataStructure->performOperations();
                delete dataStructure;  //proper memory management
                break;
            case 2:
                dataStructure = new LinkedList();
                dataStructure->performOperations();
                delete dataStructure;
                break;
            case 3:
                dataStructure = new Stack();
                dataStructure->performOperations();
                delete dataStructure;
                break;
            case 4:
                dataStructure = new Queue();
                dataStructure->performOperations();
                delete dataStructure;
                break;
            case 5:
                dataStructure = new BinarySearchTree();
                dataStructure->performOperations();
                delete dataStructure;
                break;
            case 6:
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 6);

    cout << "\n Exiting Program....\n";

    return 0;
}