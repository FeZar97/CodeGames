#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

const int MaxDistance = 26;

int getStacksNumber(string line) {

    vector<list<char>> stacks;

    for(char c : line) {

        int dist = MaxDistance;
        vector<list<char>>::iterator bestIt = stacks.end();

        for(auto it = stacks.begin(); it != stacks.end(); it++) {
            char lastChar = (*it).back();
            int curDist = lastChar - c;
            if(curDist < dist && curDist > 0) {
                dist = curDist;
                bestIt = it;
            }
        }

        if(bestIt == stacks.end()) {
            stacks.push_back({c});
        } else {
            (*bestIt).push_back(c);
        }
    }

    return stacks.size();
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string line;
    vector<int> answers(N);

    for(int i = 0; i < N; i++) {
        getline(cin, line);
        answers[i] = getStacksNumber(line);
    }

    for(auto answer : answers) {
        cout << answer << endl;
    }
}