#include <iostream>
#include <string>
using namespace std;

string Union(const int A[], int m, const int B[], int n) {
    string out = "";

    for (int i = 0; i < m; i++) {
        int x = i;
        for (int j = i + 1; j < m; j++) {
            if (A[i] == A[j]) { x = j; break; }
        }
        if (x == i) {
            if (out != "") out = out + ",";
            out = out + to_string(A[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        bool inA = false;
        for (int j = 0; j < m; j++) {
            if (B[i] == A[j]) { inA = true; break; }
        }
        if (inA) continue;

        bool seenEarlierInB = false;
        for (int j = 0; j < i; j++) {
            if (B[i] == B[j]) { seenEarlierInB = true; break; }
        }
        if (seenEarlierInB) continue;

        if (out != "") out = out + ",";
        out = out + to_string(B[i]);
    }

    return out;
}

string intersect(const int A[], int m, const int B[], int n) {
    string out = "";

    for (int i = 0; i < m; i++) {
        int x = i;

        for (int j = i + 1; j < m; j++) {
            if (A[i] == A[j]) { x = j; break; }
        }

        if (x != i) continue; 

        bool inB = false;
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) { inB = true; break; }
        }

        if (inB) {
            if (out != "") out = out + ",";
            out = out + to_string(A[i]);
        }
    }

    return out;
}

int main() {
    int A[] = { 1,2,3,4,5 };
    int B[] = { 2,4,6,8,6 };

    cout << "union:     " << Union(A, 5, B, 5) << "\n";
    cout << "intersect: " << intersect(A, 5, B, 5) << "\n"; 
}
