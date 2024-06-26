//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void topologicalSort(int v,vector<vector<int>>& adjList,vector<bool>& visited,stack<int>& stk) {
        visited[v]=true;
        for (int i=0;i<adjList[v].size();i++) {
            int next=adjList[v][i];
            if (!visited[next]) {
                topologicalSort(next,adjList,visited,stk);
            }
        }
        stk.push(v);
    }
    string findOrder(string dict[],int N,int K) {
        unordered_set<char> uniqueChars;
        for (int i=0;i<N;i++) {
            for (char c:dict[i]) {
                uniqueChars.insert(c);
            }
        }
        vector<vector<int>> adjList(26);
        vector<bool> visited(26,false);
        for (int i=0;i< N-1;i++) {
            string w1=dict[i];
            string w2=dict[i + 1];
            for (int j=0;j<min(w1.length(),w2.length());j++) {
                if (w1[j]!=w2[j]) {
                    adjList[w1[j]-'a'].push_back(w2[j]-'a');
                    break; 
                }
            }
        }
        stack<int> stk;
        for (char c:uniqueChars) {
            if (!visited[c-'a']) {
                topologicalSort(c-'a',adjList,visited,stk);
            }
        }
        string order="";
        while (!stk.empty()) {
            order+=(char)(stk.top()+'a');
            stk.pop();
        }
        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends