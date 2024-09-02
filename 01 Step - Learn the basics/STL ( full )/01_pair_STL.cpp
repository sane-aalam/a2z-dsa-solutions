#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
    cout << "Start of code ->" << endl;

    // Example-1
    pair<int, int> p;
    p.first = 1;
    p.second = 13;
    cout << p.first << " " << p.second << endl;

    // Example-2
    pair<int, string> p1;
    p1 = make_pair(11, "cpp STL master");
    cout << p1.first << endl;
    cout << p1.second << endl;

    // Example-3
    // consider we want to return the pair of the maximum element in the vector
    int first_maximum_element = 111;
    int second_maximum_element = 222;
    pair<int, int> p2;
    p2.first = first_maximum_element;
    p2.second = second_maximum_element;
    return p2;


    // Example-4 
    vector<pair<int,int>> visitedArray;
    int row = 1;
    int col = 2;
    visitedArray.push_back({row,col});
    int element1 = visitedArray.pop_back().first;
    int element2 = visitedArray.pop_back().second;


    // Example-4
    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        cout << "sum of row + col" << row + col << endl;
    } 

    cout << "End of code -> " << endl;
    return 0;
}
