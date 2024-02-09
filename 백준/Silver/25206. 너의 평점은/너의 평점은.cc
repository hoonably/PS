#include <iostream>
#include <map>
using namespace std;



int main(){
    // map 사용
    map<string, float> grade_map = {
        {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, 
        {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}
    };

    int total_score = 0;
    float total_grade = 0;

    for (int i=0; i<20; i++){
        string subject, grade;
        double score;
        cin >> subject >> score >> grade;
        if (grade == "P"){
            continue;
        }
        total_score += score;
        total_grade += score * grade_map[grade];
    }
    cout << total_grade / total_score;
}