#include <string>
#include <vector>

using namespace std;

//갈색 - 4 -> 노란색의 가로 세로 사이즈 합의 * 2-> 노란색 가로 + 2, 세로 + 2가 총 사이즈
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int temp = (brown - 4) / 2;
    int row, col;
    for(int idx = 1; idx <= temp / 2; idx++){
        if(yellow == idx * (temp - idx)){
            answer.push_back(temp - idx + 2);
            answer.push_back(idx + 2);
        }
    }
    return answer;
}