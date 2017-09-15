#include <iostream>
#include <fstream>

using namespace std;

#ifdef FILEINPUT
std::ifstream fin("input.txt");
std::ofstream fout("out.txt");
#define cin fin
#define cout fout
#endif //FILEINPUT

int main() {
    int n;

    while (cin >> n) {
        while (n--) {
            unsigned long long a;
            cin >> a;
            cout << (8 * a * a - 7 * a + 1) << endl;
        }
    }

    return 0;
}
