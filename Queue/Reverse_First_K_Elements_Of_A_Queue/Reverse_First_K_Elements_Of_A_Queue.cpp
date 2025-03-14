#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q, int &currentIndex, int limit) {
    // Base case: If we have processed 'limit' elements, return
    if (currentIndex == limit) {
        return;
    }
    
    int frontElement = q.front(); // Store the front element
    q.pop(); // Remove the front element
    currentIndex++;

    reverseQueue(q, currentIndex, limit); // Recursive call to reverse remaining elements

    q.push(frontElement); // Push the stored element to the back
}

void restoreOrder(queue<int> &q, int &currentIndex, int remainingElements) {
    // Base case: If we have processed 'remainingElements', return
    if (currentIndex == remainingElements) {
        return;
    }
    
    int frontElement = q.front(); // Store the front element
    q.pop(); // Remove the front element
    currentIndex++;

    q.push(frontElement); // Push the stored element to the back
    restoreOrder(q, currentIndex, remainingElements); // Recursive call to restore order
}

// Function to reverse first 'k' elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    int queueSize = q.size(); // Get the total size of the queue
    int currentIndex = 0; // Initialize index to track recursive calls

    reverseQueue(q, currentIndex, k); // Reverse first 'k' elements
    currentIndex = 0;
    
    restoreOrder(q, currentIndex, queueSize - k); // Restore the order of remaining elements
    
    return q;
}

int main() {
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

int k = 3;

queue<int> modifiedQueue = modifyQueue(q, k);

// Print the modified queue
while (!modifiedQueue.empty()) {
    cout << modifiedQueue.front() << " ";
    modifiedQueue.pop();
}

return 0;
}