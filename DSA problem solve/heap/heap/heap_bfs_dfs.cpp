#include <bits/stdc++.h>
using namespace std;

int maxHeap[100];
int minHeap[100];
int maxN = 0;
int minN = 0;

void insertMax(int value)
{
    int index = maxN;
    maxHeap[index] = value;
    maxN = maxN + 1;

    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(maxHeap[parent] < maxHeap[index])
        {
            swap(maxHeap[parent], maxHeap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void insertMin(int value)
{
    int index = minN;
    minHeap[index] = value;
    minN = minN + 1;

    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(minHeap[parent] > minHeap[index])
        {
            swap(minHeap[parent], minHeap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void deleteMax()
{
    if(maxN == 0)
    {
        return;
    }

    maxHeap[0] = maxHeap[maxN - 1];
    maxN = maxN - 1;

    int index = 0;

    while(true)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if(leftChild < maxN)
        {
            if(maxHeap[leftChild] > maxHeap[largest])
            {
                largest = leftChild;
            }
        }

        if(rightChild < maxN)
        {
            if(maxHeap[rightChild] > maxHeap[largest])
            {
                largest = rightChild;
            }
        }

        if(largest == index)
        {
            break;
        }

        swap(maxHeap[index], maxHeap[largest]);
        index = largest;
    }
}

void deleteMin()
{
    if(minN == 0)
    {
        return;
    }

    minHeap[0] = minHeap[minN - 1];
    minN = minN - 1;

    int index = 0;

    while(true)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if(leftChild < minN)
        {
            if(minHeap[leftChild] < minHeap[smallest])
            {
                smallest = leftChild;
            }
        }

        if(rightChild < minN)
        {
            if(minHeap[rightChild] < minHeap[smallest])
            {
                smallest = rightChild;
            }
        }

        if(smallest == index)
        {
            break;
        }

        swap(minHeap[index], minHeap[smallest]);
        index = smallest;
    }
}

int graph[10][10];
int visited[10];
int n = 4;

void bfs(int start)
{
    int queue[10];
    int front = 0;
    int rear = 0;

    visited[start] = 1;
    queue[rear] = start;
    rear = rear + 1;

    while(front < rear)
    {
        int current = queue[front];
        front = front + 1;

        cout << current << " ";

        for(int v = 0; v < n; v++)
        {
            if(graph[current][v] == 1)
            {
                if(visited[v] == 0)
                {
                    visited[v] = 1;
                    queue[rear] = v;
                    rear = rear + 1;
                }
            }
        }
    }
}

void dfs(int start)
{
    int stack[10];
    int top = -1;

    top = top + 1;
    stack[top] = start;

    while(top != -1)
    {
        int current = stack[top];
        top = top - 1;

        if(visited[current] == 0)
        {
            visited[current] = 1;
            cout << current << " ";

            for(int v = n - 1; v >= 0; v--)
            {
                if(graph[current][v] == 1)
                {
                    if(visited[v] == 0)
                    {
                        top = top + 1;
                        stack[top] = v;
                    }
                }
            }
        }
    }
}

int main()
{
    insertMax(10);
    insertMax(30);
    insertMax(20);

    insertMin(10);
    insertMin(30);
    insertMin(20);

    cout << "Max Heap: ";
    for(int i = 0; i < maxN; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;

    cout << "Min Heap: ";
    for(int i = 0; i < minN; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;

    deleteMax();
    deleteMin();

    cout << "after deleting max: ";
    for(int i = 0; i < maxN; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;

    cout << "after deleting min element: ";
    for(int i = 0; i < minN; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            graph[i][j] = 0;
        }
    }

    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    for(int i = 0; i < 10; i++)
    {
        visited[i] = 0;
    }

    cout << "BFS: ";
    bfs(0);
    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        visited[i] = 0;
    }

    cout << "DFS: ";
    dfs(0);
    cout << endl;

    return 0;
}
