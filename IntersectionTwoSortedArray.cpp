#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

////////////////////////////////////////////////////// Brute Force /////////////////////////////////////////
/*
Idea: Use two nested loops, For each element in a[], search the entire b[] for a match. Use a set data structures to avoid 
duplicates in the result.

Time Complexity: O(n * m)
*/

vector<int>IntersectionUsingBrtueforce(vector<int>&a, vector<int>&b)
{
    set<int> ans;
    for (int i = 0; i <a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if(a[i]==b[j])
            {
                ans.insert(a[i]);
                break;
            }
        }   
    }
    return vector<int>(ans.begin(), ans.end()); //converting set into the vector...
}
////////////////////////////////////////////////////// Better /////////////////////////////////////////
/*
Idea: Store frequencies of elements from array a in a map. Traverse b, and if the element exists 
in the map, it’s a common element. Insert it into a set to remove duplicates.

Time Complexity: O(n log n + m log n)
*/
vector<int> intersectionBetter(vector<int>& a, vector<int>& b) {
    map<int, int> freqMap;
    set<int> resultSet;

    for (int x : a) {
        freqMap[x]++;
    }

    for (int x : b)
    {
        if (freqMap[x] > 0)
        {
            resultSet.insert(x);
        }
    }

    // Convert set to vector
    vector<int> result(resultSet.begin(), resultSet.end());
    return result;
}

////////////////////////////////////////////////////// Optimal /////////////////////////////////////////

/*
Idea: Traverse both arrays using two pointers. If elements match, add to result (if not a duplicate).
Skip duplicates and advance pointers appropriately.

Time Complexity: O(n + m)
*/

vector<int> intersectionOptimal(vector<int>& a, vector<int>& b)
{
    int i = 0, j = 0;
    vector<int> result;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            // Match found; checking duplicates before adding
            if (result.empty() || result.back() != a[i])
            {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }
    }

    return result;
}


////////////////////////////////////////////////////// Main Function ////////////////////////////////////

int main() 
{
    int n, m;
    cout << "Enter size of first sorted array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Choose which approach to test
    // vector<int> result = IntersectionUsingBrtueforce(a, b);
    // vector<int> result = intersectionBetter(a, b);
    vector<int> result = intersectionOptimal(a, b); 

    cout << "Intersection of the two arrays:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}