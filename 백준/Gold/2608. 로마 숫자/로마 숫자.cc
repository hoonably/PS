#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
class를 활용해보자.
*/

class roman_numeral {
    unsigned int integer;
    string roman;
public:

    roman_numeral(){
        this->integer=0;
        this->roman="";
    }

    string integer_to_roman(int n) {
        string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int inte[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romannum = "";
        for (int i = 0; i < 13; i++) {
            while(n - inte[i] >= 0) {
                romannum += rom[i];
                n -= inte[i];
            }
        }
        return romannum;
    }

    int roman_to_integer(string r) {
        int len = r.length();
        int result = 0;
        map<char, int> roman_map = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        for (int i = 0; i < len; i++) {
            result += roman_map[r[i]];
        }
        // Loop to handle subtraction cases (like IV, IX, XL, XC, etc.)
        for (int i = 1; i < len; i++) {
            if ((r[i] == 'V' || r[i] == 'X') && r[i - 1] == 'I') {
                result -= 1 + 1; // Subtract 1 for I and add 1 for V or X
            }
            if ((r[i] == 'L' || r[i] == 'C') && r[i - 1] == 'X') {
                result -= 10 + 10; // Subtract 10 for X and add 10 for L or C
            }
            if ((r[i] == 'D' || r[i] == 'M') && r[i - 1] == 'C') {
                result -= 100 + 100; // Subtract 100 for C and add 100 for D or M
            }
        }
        return result;
    }

    // 합연산
    roman_numeral &operator+=(roman_numeral const &other){
        this->integer += other.integer; // Update integer value
        this->roman = integer_to_roman(this->integer); // Update roman value
        return *this;
    }

    // 아라비아 숫자, 로마 숫자 출력
    friend ostream &operator<<(ostream &out, roman_numeral const &f){
        return out << f.integer << '\n' << f.roman;
    }

    friend istream &operator>>(istream &in, roman_numeral &f) {
        in >> f.roman;
        f.integer = f.roman_to_integer(f.roman);  // 아라비아 숫자 바로 구해놓기
        return in;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    roman_numeral a, b;
    cin >> a >> b;

    a+=b;

    cout << a;
    
    return 0;
}