#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int towDistance(vector<int> &a, vector<int> &b){
        return (pow(abs(a[0]-b[0]),2) + pow(abs(a[1]-b[1]),2));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = towers.size();
        int xMax = towers[0][0], yMax = towers[0][1];
        for(auto arr : towers){
            xMax = max(xMax,arr[0]);
            yMax = max(yMax,arr[1]);
        }

        vector<int> res(3,0);
        for(int x=0; x<=xMax; ++x){
            for(int y=0; y<=yMax; ++y){
                vector<int> num = {x,y,0};

                for(int i=0; i<n; ++i){
                    int d = towDistance(towers[i],num);
                    if(d <= radius * radius) num[2] += (towers[i][2] / (1 + sqrt(d)));
                }
                cout << x << " " << y << " = " << num[2] << endl;

                if(num[2] >= res[2]) res = num;
            }
        }
        return {res[0],res[1]};
    }
};

class Solution2 {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int xMax = INT_MIN, yMax = INT_MIN;
        for (auto &&tower : towers) {
            int x = tower[0], y = tower[1];
            xMax = max(xMax, x);
            yMax = max(yMax, y);
        }
        int cx = 0, cy = 0;
        int maxQuality = 0;
        for (int x = 0; x <= xMax; x++) {
            for (int y = 0; y <= yMax; y++) {
                vector<int> coordinate = {x, y};
                int quality = 0;
                for (auto &&tower : towers) {
                    int squaredDistance = getSquaredDistance(coordinate, tower);
                    if (squaredDistance <= radius * radius) {
                        double distance = sqrt((double)squaredDistance);
                        quality += floor((double)tower[2] / (1 + distance));
                    }
                }
                cout << x << " " << y << " = " << quality << endl;
                if (quality > maxQuality) {
                    cx = x;
                    cy = y;
                    maxQuality = quality;
                }
            }
        }
        return {cx, cy};
    }

    int getSquaredDistance(const vector<int> &coordinate, const vector<int> &tower) {
        return (tower[0] - coordinate[0]) * (tower[0] - coordinate[0]) + (tower[1] - coordinate[1]) * (tower[1] - coordinate[1]);
    }
};

int main(){
    //vector<vector<int>> towers = {{1,2,5},{2,1,7},{3,1,9}};
    //vector<vector<int>> towers = {{2,0,0}};
    vector<vector<int>> towers = {{0,1,2},{2,1,2},{1,0,2},{1,2,2}};

    int radius = 2;
    Solution st;
    vector<int> res = st.bestCoordinate(towers,radius);
    cout << endl;
    std::cout << res[0] << " " << res[1] << endl;
}