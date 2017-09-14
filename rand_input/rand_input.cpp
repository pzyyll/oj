#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int rand_range(int a, int b) {
    int range = b - a + 1;
    int sr = rand() % range;
    return sr + a;
}

int main() {
    int n;
    srand(time(NULL));

    cin >> n;
    ofstream ofs("input.txt", std::ofstream::out);
    for (int i = 0; i < n; ++i) {
        int sr = rand_range(2, 5000);
        ofs << sr << endl;
    }
    return 0;
}
