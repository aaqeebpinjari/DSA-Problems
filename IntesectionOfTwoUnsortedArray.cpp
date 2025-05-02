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
Idea: we Store frequency of elements from one array (a[]) in an unordered map then we Traverse the second array (b[]) 
and check if the element exists in the map. Use a set to avoid duplicates in the output.

Time Complexity: O(n + m)

*/
vector<int> IntersectionUsingBetter(vector<int>&a, vector<int>&b){
    unordered_map<int,int>freq;
    set<int>result;

    for (int num:a)
    {
        freq[num]++;
    }
    //check element from another array
    for (int num : b) {
        if (freq[num] > 0)
        {
            result.insert(num); // insert only unique common elements
        }
    }
    return vector<int>(result.begin(), result.end());
}

////////////////////////////////////////////////////// Optimal /////////////////////////////////////////

/*
Idea: Insert all elements of first array into an unordered_set, and Traverse another array, and 
if an element is in the set, insert it into a result and remove it from the original set to avoid duplicates.

Time Complexity: O(n + m)
*/

vector<int> intersectionOptimal(vector<int>& a, vector<int>& b) 
{
    unordered_set<int> elements(a.begin(), a.end()); 

    unordered_set<int> result;
    for (int num : b) {
        if (elements.find(num) != elements.end())
        {
            result.insert(num); // common element found
            elements.erase(num); // remove to ensure uniqueness
        }
    }
    return vector<int>(result.begin(), result.end());
}


////////////////////////////////////////////////////// Main Function ////////////////////////////////////
int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of first array:\n";
    for (int i = 0; i < n; i++) 
    cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of second array:\n";
    for (int i = 0; i < m; i++) 
    cin >> b[i];

    // Change to brute/better/optimal
    vector<int> result = IntersectionUsingBrtueforce(a, b);
    // vector<int> result = intersectionOptimal(a, b);
    // vector<int> result = intersectionOptimal(a, b);

    cout << "Intersection of the two arrays:\n";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
