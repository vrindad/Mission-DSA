#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        stringstream ss(preorder);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        int slots = 1;
        for (const string& node : nodes) {
            slots--;
            if (slots < 0) {
                return false;
            }
            if (node != "#") {
                slots += 2;
            }
        }
        return slots == 0;
    }
};
