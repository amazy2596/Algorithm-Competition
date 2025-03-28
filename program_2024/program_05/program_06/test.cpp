#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using intt = long long;

int main() {
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);

    ifstream file("large_input.txt");

    int n;
    file >> n;

    auto start = chrono::high_resolution_clock::now();

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        file >> a[i];
        
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                swap(a[j - 1], a[j]);
                swap(a[j - 1], a[j]);
            }
    
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        
    std::cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}
