/*
    TO-DOs: 
    1) Implementation of arrays sorting algorith
    2) Proper memory management
    3) Displaying Tree in proper format
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class for data structures
class DataStructure {
public:
    virtual void display() const = 0;
    virtual void performOperations() = 0;
};

// Array class
class Array : public DataStructure {
private:
    int a[100];
    int n;

public:
    Array() : n(0) {}

    // function to display an array (print array method)
void display() const override {
    if (n == 0) {
        cout << "\n Array is Empty....\n\n";
        return;
    }

    cout << "\n Current Array is : \n";
    cout << "\n\t[ ";

    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << ", ";
    }

    cout << a[n - 1] << " ]\n\n";

    cout << " Size of Array: " << n << "\n\n";
}


    void performOperations() override {
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
                case 5:  //all sorting related stuff
                    sortOperation();
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 6);
    }


private:
    //for quick sort
    int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        //searching element greateer than pivot
        while (A[i] <= pivot)
        {
            i++;
        }

        //searching element lesser than pivot
        while (A[j] > pivot)
        {
            j--;
        }

        // swaping A[i] with A[j]
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;  
}

    // all array sorting related opeerations
    void sortOperation() {
        int choice;
        do {
            cout << "\n\n Sorting Algorithms ::\n";
            cout << " 1 : Bubble Sort\n 2 : Merge Sort \n 3 : Quick Sort\n 4 : Selection Sort\n 5 : Count Sort\n 5 : Back to Main Menu\n";
            cout << "\n Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    bubbleSort();
                    break;
                case 2:
                    mergeSort();
                    break;
                case 3:
                    quickSort(a, 0 , n-1);
                    display();
                    break;
                case 4:
                    selectionSort();
                    break;
                case 5:
                    countSort();
                    break;
                case 6: //goes back to main menu
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        } while (choice != 5);
    }

        /* 
            sorting algorithms 
        */
    void bubbleSort() {

        int temp;
        int isSorted=0;
        clock_t tStart = clock();
        for(int i=0;i<n-1;i++){
            isSorted=1;
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    temp= a[j];
                    a[j] = a[j+1];
                    a[j+1]= temp;
                    isSorted=0;
                }
        }
        if(isSorted){
            break;
        }

        display();
        cout << " Time taken for Bubble sort : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

    }
    }
    void mergeSort() {
        // will implement
    }
    
    void quickSort(int A[],  int low ,int high) {
        int partitionIndex; // Index of pivot after partition
        clock_t tStart = clock();

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);  // sort left subarray 
        quickSort(a, partitionIndex + 1, high); // sort right subarray
    }

    cout << " Time taken for Quick sort : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

    }
    void selectionSort() {

    }
    void countSort() {

    }


    void createArray() {
        cout << "\n Enter the number of elements in array : ";
        cin >> n;
        cout << "\n Enter the elements : \n\n";

        clock_t tStart = clock();

        for (int i = 0; i < n; i++) {
            cout << "\n Enter element " << i + 1 << " : ";
            cin >> a[i];
        }

        cout << "\n\n";
        cout << " Time taken in Creation of Array : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
        cout << "\n";
    }

    void insertElement() {
        if (n == 100) {
            cout << "\n Size Allocated to array is Full....\n\n";
            return;
        }

        int arrayPos, elem;
        cout << "\n Enter position where you want to insert element : ";
        cin >> arrayPos;

        if (arrayPos > n) {
            cout << "Invalid Position....";
            return;
        }

        cout << "\n\n Enter the value to be inserted : ";
        cin >> elem;

        clock_t tStart = clock();

        for (int i = n - 1; i >= arrayPos; i--) {
            a[i + 1] = a[i];
        }

        a[arrayPos] = elem;
        n = n + 1;

        cout << "\n Element Inserted Successfully !!!";
        cout << "\n\n";
        cout << " Time taken in Insertion : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";

        cout << "\n";
    }

    void deleteElement() {
        if (n == 0) {
            cout << "\n Array is Empty.... Element can not be Deleted.\n\n";
            return;
        }

        int arrayPos;
        cout << "\n Enter a valid position to delete an Element from Array : ";
        cin >> arrayPos;

        if (arrayPos > n) {
            cout << "\n Given Position is Invalid...Element can not be deleted. ";
            return;
        }

        clock_t tStart = clock();

        for (int i = arrayPos; i < n - 1; i++) {
            a[i] = a[i + 1];
        }

        n = n - 1;

        cout << "\n Element Deleted Successfully !!!";
        cout << "\n Deleted Element is : " << a[arrayPos];

        cout << "\n\n";
        cout << " Time taken in Deleting : " << static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC << "s\n";
        cout << "\n";

        display();
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

        cout << "［" << s[0] << "］|";
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
                    display();
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
            cout << "［" << node->data << "］--";
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