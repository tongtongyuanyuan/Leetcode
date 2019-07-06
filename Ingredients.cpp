//
// Created by Tong Xue on 7/6/19.
//

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Meal
{
    Meal(string n, vector<string> i) { name = n; ingredients = i; }
    string name; vector<string> ingredients;
};

vector<string> split(const string& str, const string& delim) {
    vector<string> tokens;
    int prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
#include <unordered_set>


using namespace std;

int getUniqueMealCount(const vector<Meal> meals) {
    set<set<string>> res;
    for(auto& m : meals){
        set<string> tmp(m.ingredients.begin(), m.ingredients.end());
        res.insert(tmp);
    }
    return res.size();
}
int main() {
    string line;
    vector<Meal> meals;

    while (true) {
        getline(cin, line);
        if (cin.fail()) {
            cout << "A parsing error occurred";
        }

        vector<string> mealIngredients = split(line, " - ");
        vector<string> ingredients = split(mealIngredients[1], ",");
        string name = mealIngredients[0];
        meals.push_back(Meal(name, ingredients));

        if (cin.eof()) {
            break;
        }
    }
    cout << getUniqueMealCount(meals) << endl;
    return 0;
}
