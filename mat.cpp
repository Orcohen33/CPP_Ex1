#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


namespace ariel{
string mat(int x, int y, char a, char b){
    // Exceptions
    if (x%2==0||y%2==0){
        throw invalid_argument("Mat size is always odd");
    }
    if ( int(a) < 32 || int(a) > 127 || int(b) < 32 || int(b) > 127){
        throw invalid_argument("Mat contains two symbols(type char)");
    }
    if (x<0 || y<0){
        throw invalid_argument("Mat dimension cant be with negative numbers");
    }
    /*
    r - Row = y
    c - Col = x
    */
    int r = 0, c = 0, i;
    // 2D Mat
    char mat[y][x];
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
    Because i decreased the value of x and y, i initialize it again to be as it started.
    */
    x = sizeof(mat[0])/ sizeof(mat[0][0]);
    y = sizeof(mat)/ sizeof(mat[0]);

    /*
    Fills 'ans' for the output
    */
    string ans = "";
    int row, col;
    for(row = 0; row < y; row++){
        for(col = 0; col < x; col++){
            ans+= mat[row][col];
        }
        ans+="\n";
    }
    return ans;
}
} 
