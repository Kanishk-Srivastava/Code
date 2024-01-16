#include <iostream>
#include <vector>
#include <string>
using namespace std;

int find_boundary(vector<bool> arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int boundary_index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr.at(mid))
        {
            boundary_index = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << arr[boundary_index] << endl;
    return boundary_index;
}

int main()
{
    vector<bool> boolVector;
    string input;
    while (cin >> input && input != "stop")
    {
        if (input == "true")
        {
            boolVector.push_back(true);
        }
        else if (input == "false")
        {
            boolVector.push_back(false);
        }
        else
        {
            cout << "Invalid input. Please enter 'true', 'false', or 'stop'." << endl;
        }
    }

    cout <<find_boundary(boolVector);
}