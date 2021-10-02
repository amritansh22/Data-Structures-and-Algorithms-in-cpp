#include <bits/stdc++.h>

using namespace std;

// Implementing sleep sort
int main()
{
    // Get input values
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<thread> threads; // Initialize threads
    for (auto i = 0; i < n; i++){ // Loop each thread
        threads.emplace_back(
            [i, &a]() { // Push each element into a thread and wait
                int t = stoi(a[i]);
                this_thread::sleep_for(chrono::seconds(t)); // Sleep that amount of time
                cout << a[i] << "\n"; // Return the value
            }
        );
    }
    // Join all threads at the end
    for (auto &thread: threads){
        thread.join();
    }
    return 0;
}
