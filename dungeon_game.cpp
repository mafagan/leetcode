#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.size()==0) return 1;
        //int **left = new int[dungeon.size()][dungeon[0].size()];
        //int **minhp = new int[dungeon.size()][dungeon[0].size()];

        vector<vector<int> > left(dungeon.size());
        vector<vector<int> > minhp(dungeon.size());

        for(int i=0; i<dungeon.size(); i++)
        {
            left[i].resize(dungeon[0].size());
            minhp[i].resize(dungeon[0].size());
        }
        minhp[0][0] = dungeon[0][0]<0 ? 1-dungeon[0][0] : 1;
        left[0][0] = dungeon[0][0]<0 ? 1 : dungeon[0][0]+1;

        for(int i=0; i<dungeon.size(); i++){
            for(int j=0; j<dungeon[0].size(); j++){
                if(i==0 && j==0) continue;
                else if(i==0){
                    int leftblood = left[i][j-1] + dungeon[i][j];
                    if(leftblood>0){
                        left[i][j] = leftblood;
                        minhp[i][j] = minhp[i][j-1];
                    }else{
                        left[i][j] = 1;
                        minhp[i][j] = 1 - leftblood + minhp[i][j-1];
                    }
                }else if(j==0){
                    int leftblood = left[i-1][j] + dungeon[i][j];
                    if(leftblood>0){
                        left[i][j] = leftblood;
                        minhp[i][j] = minhp[i-1][j];
                    }else{
                        left[i][j] = 1;
                        minhp[i][j] = 1 - leftblood + minhp[i-1][j];
                    }
                }else{
                    int leftbloodright = left[i][j-1] + dungeon[i][j];
                    int left1, left2;
                    int minhp1, minhp2;

                    if(leftbloodright>0){
                        left1 = leftbloodright;
                        minhp1 = minhp[i][j-1];
                    }else{
                        left1 = 1;
                        minhp1 = 1 - leftbloodright + minhp[i][j-1];
                    }

                    int leftblooddown = left[i-1][j] + dungeon[i][j];
                    if(leftblooddown>0){
                        left2 = leftblooddown;
                        minhp2 = minhp[i-1][j];
                    }else{
                        left2 = 1;
                        minhp2 = 1 - leftblooddown + minhp[i-1][j];
                    }

                    if(minhp1 < minhp2)
                    {
                        minhp[i][j] = minhp1;
                        left[i][j] = left1;
                    }else{
                        minhp[i][j] = minhp2;
                        left[i][j] = left2;
                    }
                }
            }
        }

        return minhp[dungeon.size()-1][dungeon[0].size()-1];
    }
};

int main(){
    int arr[3] = {1, -3, 3};
    int arr1[3] = {0, -2, 0};
    int arr2[3] = {-3, -3, -3};


    vector<int> t1(arr, arr+3);
    vector<int> t2(arr1, arr1+3);
    vector<int> t3(arr2, arr2+3);
    vector<vector<int> > res;
    res.push_back(t1);
    res.push_back(t2);
    res.push_back(t3);

    Solution a;

    cout << a.calculateMinimumHP(res) << endl;
    return 0;
}
