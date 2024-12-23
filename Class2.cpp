#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Majority Element Function
int majorityElement(const vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
        if (countMap[num] > (n / 2)) {
            return num;
        }
    }
    return -1;
}

// Unique Element Function
int uniqueElement(const vector<int>& nums) {
    unordered_map<int, int> countMap;

    // Count occurrences of each number
    for (int num : nums) {
        countMap[num]++;
    }

    // Find the number with exactly one occurrence
    for (const auto& pair : countMap) {
        if (pair.second == 1) {
            return pair.first;
        }
    }

    return -1; // No unique element found
}

// Node Class for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Helper Function for Sorted Array to BST
Node* sortedArrayToBSTHelper(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBSTHelper(arr, start, mid - 1);
    root->right = sortedArrayToBSTHelper(arr, mid + 1, end);

    return root;
}

// Sorted Array to BST Function
Node* sortedArrayToBST(vector<int>& arr) {
    int n = arr.size();
    return sortedArrayToBSTHelper(arr, 0, n - 1);
}

// Inorder Traversal Function
void printInorder(Node* node) {
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Pascal's Triangle Function
void pascalTriangle(int row) {
    vector<int> prev;

    for (int i = 0; i < row; i++) {
        vector<int> curr;
        curr.push_back(1);

        for (int j = 1; j < prev.size(); j++) {
            curr.push_back(prev[j - 1] + prev[j]);
        }

        if (i > 0) curr.push_back(1);

        string spaces(row - i - 1, ' ');
        cout << spaces;
        for (int num : curr) {
            cout << num << " ";
        }
        cout << endl;

        prev = curr;
    }
}

// Remove Duplicates Function
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            ++k;
        }
    }

    return k;
}

// Circular Queue Class
class MyCircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }

    // Inserts an element into the circular queue
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    // Deletes an element from the circular queue
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    // Gets the front item from the queue
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[front];
    }

    // Gets the last item from the queue
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[rear];
    }

    // Checks whether the circular queue is empty or not
    bool isEmpty() {
        return size == 0;
    }

    // Checks whether the circular queue is full or not
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    // Majority Element Section
    int n;
    cout << "Enter the size of the array --> ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array -->" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int majorityResult = majorityElement(nums);
    if (majorityResult != -1)
        cout << "The majority element is " << majorityResult << endl;
    else
        cout << "No majority element found" << endl;

    // Unique Element Section
    int uniqueResult = uniqueElement(nums);
    if (uniqueResult != -1)
        cout << "UNIQUE ELEMENT: " << uniqueResult << endl;
    else
        cout << "No UNIQUE ELEMENT found" << endl;

    // Sorted Array to BST Section
    vector<int> sortedNums = { 1, 2, 3, 4, 5, 6, 7 };
    Node* root = sortedArrayToBST(sortedNums);
    cout << "Inorder Traversal of the BST:" << endl;
    printInorder(root);
    cout << endl;

    // Pascal's Triangle Section
    int row;
    cout << "Enter row for Pascal's triangle: ";
    cin >> row;
    pascalTriangle(row);

    // Remove Duplicates Section
    vector<int> duplicateNums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int k = removeDuplicates(duplicateNums);
    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; ++i) {
        cout << duplicateNums[i] << " ";
    }
    cout << endl;

    // Circular Queue Section
    MyCircularQueue myCircularQueue(3);
    cout << myCircularQueue.enQueue(1) << endl;
    cout << myCircularQueue.enQueue(2) << endl;
    cout << myCircularQueue.enQueue(3) << endl;
    cout << myCircularQueue.enQueue(4) << endl;
    cout << myCircularQueue.Rear() << endl;
    cout << myCircularQueue.isFull() << endl;
    cout << myCircularQueue.deQueue() << endl;
    cout << myCircularQueue.enQueue(4) << endl;
    cout << myCircularQueue.Rear() << endl;

    return 0;
}
