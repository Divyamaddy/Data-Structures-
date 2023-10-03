#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to calculate the largest rectangular area in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int i = 0;

    while (i < heights.size()) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
        } else {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
    }

    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, heights[tp] * width);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = largestRectangleArea(heights);
    cout << "Largest rectangular area in the histogram: " << maxArea << endl;

    return 0;
}
