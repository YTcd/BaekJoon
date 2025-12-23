#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

struct MinHeap
{
    int size = 0;
    vector<int> vec;

    MinHeap()
    {
        vec.push_back(0);
    }

public:
    void insert(int number)
    {
        vec.push_back(number);
        size++;
        int index = size;
        if (index == 1)
        {
            return;
        }

        while (vec[index / 2] > number)
        {
            if (index == 1)
            {
                break;
            }

            int temp = vec[index / 2];
            vec[index / 2] = number;
            vec[index] = temp;
            index = index / 2;
        }
    }

public:
    int pop()
    {
        if (size == 0)
        {
            return 0;
        }

        int minNum = vec[1];
        vec[1] = vec[size];
        vec.pop_back();
        size--;

        int index = 1;
        while (true)
        {
            int leftChildIndex = index * 2;
            int rightChildIndex = index * 2 + 1;

            if (leftChildIndex > size)
            {
                break;
            }

            if (rightChildIndex > size)
            {
                if (vec[leftChildIndex] < vec[index])
                {
                    int temp = vec[leftChildIndex];
                    vec[leftChildIndex] = vec[index];
                    vec[index] = temp;
                    index = leftChildIndex;
                }
                else
                {
                    break;
                }
            }
            else
            {
                int smallerIndex = vec[leftChildIndex] > vec[rightChildIndex] ? rightChildIndex : leftChildIndex;
                int biggerIndex = vec[leftChildIndex] < vec[rightChildIndex] ? rightChildIndex : leftChildIndex;

                if (vec[smallerIndex] < vec[index])
                {
                    int temp = vec[smallerIndex];
                    vec[smallerIndex] = vec[index];
                    vec[index] = temp;
                    index = smallerIndex;
                }
                else if (vec[biggerIndex] < vec[index])
                {
                    int temp = vec[biggerIndex];
                    vec[biggerIndex] = vec[index];
                    vec[index] = temp;
                    index = biggerIndex;
                }
                else
                {
                    break;
                }
            }
        }

        return minNum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;

    int count;
    cin >> count;

    MinHeap minHeap;
    for (int i = 0; i < count; i++)
    {
        int number;
        cin >> number;
        if (number == 0)
        {
            result.push_back(minHeap.pop());
        }
        else
        {
            minHeap.insert(number);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
};