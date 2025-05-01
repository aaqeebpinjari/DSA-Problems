#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

////////////////////////////////////////////////////////////// Brute ///////////////////////////////////////////////////////////
/*1Brute force: insert all elements from both arrays into a set. 
which automatically removes duplicates and stores elements in sorted
order and Convert a vector for the final result.

Time Complexity: O((n + m) * log(n + m))
Space Complexity: O(n + m)
*/ 

vector<int>UnionbruteForce(vector<int>&a, vector<int>&b)
{

// inserting element into the set
    set<int>s;
    for(int num:a) {
        s.insert(num);
    }
    for(int num: b){
        s.insert(num);
    }

// converting set into vector
    vector<int>result(s.begin(), s.end());
    return result;
}

////////////////////////////////////////////////////////////////// Better ////////////////////////////////////////////////////////////

/*
2. Better : Use a map to count frequencies of elements from both arrays.
Since map stores keys in sorted order and we care only about unique elements, 
ignore the count and take only keys.

Time Complexity: O((n + m) * log(n + m))
Space Complexity: O(n + m)

*/

vector<int> UnionBetter(vector<int>&a, vector<int>&b)
{
    map<int, int> freq;
    for (int num : a) {
        freq[num]++;
    }

    for (int num : b) {
        freq[num]++;
    }

    vector<int> result;
    // Extract keys only
    for (auto& [key, _] : freq)
    {
        result.push_back(key); // push key into result
    }
    return result;
}

///////////////////////////////////////////////////////////////  Optimal ////////////////////////////////////////////////////

/* optimal :Use two pointers method, each one pointing to starting index of the array, 
to traverse both, compare the element at the index, If equal, add and update the pointer
and move and check until we traverse both the array completely

Time Complexity: O(n + m)
Space Complexity: O(n + m)*/

vector<int> unionOptimal(vector<int>& a, vector<int>& b)
{
    int i = 0, j = 0; // pointers
    vector<int> result;

    // we compare  the element at the index and whoever is small is placed in the result
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (result.empty() || result.back() != a[i]) // Avoid duplicates
                result.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i]) {
            if (result.empty() || result.back() != b[j])
                result.push_back(b[j]);
            j++;
        }
        else {
            if (result.empty() || result.back() != a[i])
                result.push_back(a[i]); // equal case
            i++;
            j++;
        }
    }

    // Add remaining elements from a[] when b is traversed before a is still remaining
    while (i < a.size()) {
        if (result.empty() || result.back() != a[i])
            result.push_back(a[i]);
        i++;
    }

    // Add remaining elements from b[] where b is still remaining to traverse
    while (j < b.size()) {
        if (result.empty() || result.back() != b[j])
            result.push_back(b[j]);
        j++;
    }

    return result;
}

///////////////////////////////////////////////////////////////////// Main //////////////////////////////////////////////

int main() 
{
    int n, m;
    cout << "Enter size of first sorted array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // Change function to any brute/better/optimal
    vector<int> result = UnionbruteForce(a, b);
    vector<int> result = UnionBetter(a, b);
    vector<int> result = unionOptimal(a, b);

    cout << "Union of the two arrays:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
