// Map. STL use
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, pair<int, string>> dict;
    string line;
    while(getline(cin, line) && line != "#"){
        stringstream ss(line);
        string word;
        while(ss >> word){
            string ord = word;
            transform(word.begin(), word.end(), word.begin(), [&](char c){
                        return c = tolower(c);
                      });
            sort(word.begin(), word.end());
            dict[word].first++;
            dict[word].second = ord;
        }
    }
    set<string> ans;
    for(auto m : dict){
        if(m.second.first == 1){
            ans.insert(m.second.second);
        }
    }
    for(auto w: ans){
        cout << w << endl;
    }
    return 0;
}
/*
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
*/
