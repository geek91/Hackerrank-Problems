#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

10// Input
// 2        test cases
// 5 2      elements count : sub-array elements
// 3 4 6 3 4
// 7 4
// 3 4 5 8 1 4 

// Output
// 4 6 6 4
// 8 8 8 10

// Objective O(n) linear time complexity

void printKMax (std::vector<int>& v, int k) {

    std::deque<int> dq; // this will only store the index

    int i;
    for (i = 0; i < k; ++i) {

        //should always pick the decreasing sequence in the deque
        while ((!dq.empty()) && v[i] > v[dq.back()])
        dq.pop_back ();
        dq.push_back (i);   // finally push back the increasing sequence
    }

    for (; i<v.size(); ++i) {

        std::cout << v[dq.front()] << " ";

        while ((!dq.empty()) && dq.front() <= i-k)
        dq.pop_front();     // removing the element outside of the window

        while ((!dq.empty()) && v[i] > v[dq.back()])
        dq.pop_back();

        dq.push_back(i);
    }
    std::cout << v[dq.front()] << std::endl;
}


int main() {

    int nCases, nCount, k;
    std::cin >> nCases;

    while (nCases-- > 0) {

        std::cin >> nCount >> k;
        std::vector<int> num;
        while (nCount-- > 0) {
            int temp;
            std::cin >> temp;
            num.push_back (temp);
        }
        printKMax (num, k);
        num.clear();
    }

    return 0;
}