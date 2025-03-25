#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue using recursion
void reverseQueue(queue<int> &q, int &index, int size) {
    if (index == size) {
        return;
    }
    int temp = q.front(); // Store the front element
    q.pop(); // Remove the front element
    index++;
    reverseQueue(q, index, size); // Recursive call
    q.push(temp); // Push the stored element to the back
}
void rev(queue<int>&q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    rev(q);
    q.push(temp);
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int size = q.size(); // Get the size of the queue
    int index = 0; // Initialize index to 0
 //   reverseQueue(q, index, size); // Call the function to reverse the queue
    rev(q);
    while (!q.empty()) {
        cout << q.front() << " "; // Print the front element
        q.pop(); // Remove the front element
    }
}