// Two Pointer.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    string s;
    map<char, char> mp{
        {'A', 'A'}, {'E', '3'}, {'H', 'H'},
        {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
        {'M', 'M'}, {'O', 'O'}, {'S', '2'},
        {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
        {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'},
        {'Z', '5'}, {'1', '1'}, {'2', 'S'},
        {'3', 'E'}, {'5', 'Z'}, {'8', '8'}
    };
    while(cin >> s){
        int len = s.size();
        bool pa = 1, mi = 1;
        for(int i = 0; i <= len/2; ++i){
            if(s[i] != s[len-1-i]) pa = 0;
            if(mp[s[i]] != s[len-1-i] && s[i] != mp[s[len-1-i]]) mi = 0;
        }
        if(pa && mi)
            printf("%s -- is a mirrored palindrome.\n", s.c_str());
        else if(!pa && !mi)
            printf("%s -- is not a palindrome.\n", s.c_str());
        else{
            if(!pa)
                printf("%s -- is a mirrored string.\n", s.c_str());
            else
                printf("%s -- is a regular palindrome.\n", s.c_str());
        }
        puts("");
    }
    return 0;
}
/*
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA

*/
