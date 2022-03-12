#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


namespace ariel{
string mat(int x, int y, char a, char b){
    // Exceptions
    if (x%2==0||y%2==0){
        throw invalid_argument("Mat size is always odd");
    }
    const auto lower_assci = 32;
    const auto higher_assci = 127;
    if ( (a < lower_assci || a > higher_assci) || (b < lower_assci || b > higher_assci)){
        throw invalid_argument("Mat contains two symbols(type char)");
    }
    if (x<0 || y<0){
        throw invalid_argument("Mat dimension cant be with negative numbers");
    }
    /*
    r - Row = y
    c - Col = x
    */
    int r = 0;
    int c = 0;
    int i = 0;
    // 2D Mat
    vector<char> v(x, a);               // initialize columns
    vector<vector<char>> mat(y, v);     // initialize rows
    char curr_char_rect = a;
    /*
    Manufacturing mat with rings design as the company asked.
    The idea is to make a rectangle in a rectangle in a rectangle and so on...
    */
    while(r < y && c < x){

        for (i = c; i < x; i++){
            mat[r][i] = curr_char_rect;
        }
        r++;

        for(i = r; i < y; i++){
            mat[i][x-1] = curr_char_rect;
        }
        x--;

        if(r < y){
            for(i = c; i < x; i++){
                mat[y-1][i] = curr_char_rect;
            }
            y--;
        }
        if(c < x){
            for(i = r; i < y; i++){
                mat[i][c] = curr_char_rect;
            }
            c++;
        }

        curr_char_rect = (curr_char_rect == a)? b : a;

    }
    /*
    Fills 'ans' for the output
    */
    string ans;
    for (auto const &row: mat){
        for(char val: row){
            ans += val;
        }
        ans+="\n";
    }
    return ans;
}
} 
