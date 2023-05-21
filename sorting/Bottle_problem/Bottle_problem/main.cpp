

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Bottles {
    int id;
    string color;
    int amount_of_water;
};

vector<pair<Bottles, Bottles>> findMatch(const vector<Bottles>& bottles) {

    vector<pair<Bottles, Bottles>> match;
    unordered_map<int, Bottles> BlueeBottles;

    for (int i = 0; i < bottles.size(); i++) {

        if (bottles[i].color == "Blue")
            BlueeBottles[bottles[i].amount_of_water] = bottles[i];

        else if (bottles[i].color == "red")
        {
            auto y = BlueeBottles.find(bottles[i].amount_of_water);

            if (y != BlueeBottles.end())
            {
                match.push_back(make_pair(y->second, bottles[i]));
                BlueeBottles.erase(y);
            }
        }
    }

    return match;
}

int main() {
    vector<Bottles> bottles = {
        {1, "Blue", 10},
        {2, "Blue", 1},
        {3, "Blue", -2},
        {4, "Blue", 5},
        {5, "Blue", 423},
        {11, "red", 10},
        {22, "red", 1},
        {33, "red", -2},
        {44, "red", 5},
        {55, "red", 423}
    };

    vector<pair<Bottles, Bottles>> match = findMatch(bottles);

    cout << "Matching pairs:\n";
    for (int i = 0; i < match.size(); i++) {
        cout << "Id Blue: " << match[i].first.id << ", Id red: " << match[i].second.id << "\n";
    }

    return 0;
}


//second version
/*

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Bottles {
    int id;
    string color;
    int amount_of_water;
};

vector<pair<Bottles, Bottles>> findMatch(const vector<Bottles>& bottles) {

    vector<pair<Bottles, Bottles>> match;
    unordered_map<int, Bottles> BlueeBottles;

    for (int i = 0; i < bottles.size(); i++) {

        if (bottles[i].color == "Blue")
            BlueeBottles[bottles[i].amount_of_water] = bottles[i];
    }

    for (int i = 0; i < bottles.size();i++) {

        if (bottles[i].color == "red")
        {
            auto y = BlueeBottles.find(bottles[i].amount_of_water);

            if (y != BlueeBottles.end())
            {
                match.push_back(make_pair(y->second, bottles[i]));
                BlueeBottles.erase(y);
            }
        }
    }

    return match;
}

int main() {
    vector<Bottles> bottles = {
        {11, "red", 10},
        {22, "red", 1},
        {1, "Blue", 10},
        {2, "Blue", 1},
        {3, "Blue", -2},
        {4, "Blue", 5},
        {5, "Blue", 423},
        {33, "red", -2},
        {44, "red", 5},
        {55, "red", 423}
    };

    vector<pair<Bottles, Bottles>> match = findMatch(bottles);

    cout << "Matching pairs:\n";
    for (int i = 0; i < match.size(); i++) {
        cout << "Id Blue: " << match[i].first.id << ", Id red: " << match[i].second.id << "\n";
    }

    return 0;
}

*/
