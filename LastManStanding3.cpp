// LastManStanding3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class LinkNode
{
public: int data;
      LinkNode* next;
      LinkNode(int data)
      {
          // Set node value
          this->data = data;
          this->next = NULL;
      }
};
// Define Circular List
class CircularList
{
public: LinkNode* head;
      LinkNode* rear;
      CircularList()
      {
          this->head = NULL;
          this->rear = NULL;
      }
      // Add node in circular linked list
      void addNode(int data)
      {
          LinkNode* node = new LinkNode(data);
          if (this->head == NULL)
          {
              // First node of linked list
              this->head = node;
          }
          else
          {
              // Add new node at last position
              this->rear->next = node;
          }
          // Connect the first node to the last
          node->next = this->head;
          // Get new last node
          this->rear = node;
      }
};
class JosephusCircle
{
public:
    // Implement josephus circle in circular linked list
    void josephusPosition(int size, int n)
    {
        if (n <= 0)
        {
            return;
        }
        if (n == 1)
        {
            // Base case
            cout << " Josephus Position " << size << " \n";
            return;
        }
        CircularList cll = CircularList();
        // Construct linked list
        for (int i = 1; i <= size; ++i)
        {
            cll.addNode(i);
        }
        // Define some auxiliary variables
        LinkNode* auxiliary = cll.head;
        LinkNode* back = cll.head;
        int counter = 0;
        cll.head = NULL;
        cll.rear = NULL;
        // Execute loop until when more than one node in linked list
        while (auxiliary->next != auxiliary)
        {
            // Used to find n-th node
            counter = 1;
            while (counter != n)
            {
                // Get current node
                back = auxiliary;
                // Visit to next node
                auxiliary = auxiliary->next;
                counter++;
            }
            // Segregating n-th position node
            back->next = auxiliary->next;
            delete auxiliary;
            // Visit to next node
            auxiliary = back->next;
        }
        cout << "\n Size : " << size << " N : " << n << " \n";
        // Display last remaining node
        cout << " Josephus Position " << auxiliary->data << " \n";
        cll.head = auxiliary;
        cll.rear = auxiliary;
    }
};
int main()
{
    JosephusCircle task = JosephusCircle();
    // Number of element in circle
    int size = 10;
    int n = 4;
    task.josephusPosition(size, n);
    n = 6;
    task.josephusPosition(size, n);
    return 0;
}