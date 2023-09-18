#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

#define INF 9999999999999999

void Neneig(int N, float **gr){
    int i;
    vector<int> path;
    bool vs[N];
    for(int i=0; i<N;i++){
        vs[i]=false;
    }
    int v0=0, u=0;
    path.push_back(v0);
    float sum=0;
    vs[v0]=true;
    while (path.size() != N) {
        int v0 = path[path.size() - 1];
        float min = INF;
        for(i=0;i<N;i++) if(gr[v0][i]< min && !vs[i]){min=gr[v0][i];  u=i;} 
        
        vs[u]=true;
        path.push_back(u);
        sum= sum + gr[v0][u];
        
    }
    //for (int i = 0; i < N; i++) {
       //cout << path[i] + 1 << " ";}
    cout<<sum<<"  ";
    return ;
}





void jjj(string S){
    int i,j, k;  

ifstream data(S);
    int N;
    data>>N;
    float** mm = new float *[N]; 
    for (int i=0; i < N; i++)
        mm[i] = new float [2];

    float** gr = new float *[N]; 
    for (int i=0; i < N; i++)
        gr[i] = new float [N];

    for(int i = 0; i<N;i++){
        data>>mm[i][0];
        data>>mm[i][1];
        
    }
    data.close();
    
    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
        if(i!=j){
            gr[i][j] = sqrt(( mm[i][0]-mm[j][0])*(mm[i][0]-mm[j][0]) + (mm[i][1]-mm[j][1])*(mm[i][1]-mm[j][1]));
            gr[j][i] = gr[i][j];
        }
        else gr[i][j]=INF;

    
    Neneig(N,gr);
    delete [] mm;
    delete [] gr;

    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
   

    return ;
}    

int main(){
string S[73] = {"tsp_100_1", "tsp_100_2", "tsp_100_3", "tsp_100_4", "tsp_100_5", "tsp_100_6", "tsp_1000_1", "tsp_101_1", "tsp_105_1", "tsp_1060_1", "tsp_107_1",
"tsp_1084_1", "tsp_1173_1", "tsp_11849_1", "tsp_124_1", "tsp_127_1", "tsp_1291_1", "tsp_1304_1", "tsp_1323_1", "tsp_136_1", "tsp_1379_1", "tsp_1400_1", "tsp_14051_1",
"tsp_1432_1", "tsp_144_1", "tsp_150_1", "tsp_150_2", "tsp_152_1", "tsp_1577_1", "tsp_159_1", "tsp_1655_1", "tsp_1748_1", "tsp_1817_1", "tsp_18512_1",
"tsp_1889_1", "tsp_195_1", "tsp_198_1", "tsp_200_1", "tsp_200_2", "tsp_2103_1", "tsp_2152_1", "tsp_225_1", "tsp_226_1", "tsp_2319_1", "tsp_2392_1",
"tsp_262_1", "tsp_264_1", "tsp_299_1", "tsp_3038_1", "tsp_318_1", "tsp_318_2", "tsp_33810_1", "tsp_3795_1", "tsp_400_1", "tsp_417_1", "tsp_439_1",
"tsp_442_1", "tsp_4461_1", "tsp_493_1", "tsp_5_1", "tsp_51_1", "tsp_574_1", "tsp_575_1", "tsp_5915_1", "tsp_5934_1", "tsp_654_1",  "tsp_70_1",
"tsp_724_1", "tsp_7397_1", "tsp_76_1", "tsp_76_2", "tsp_783_1", "tsp_99_1"};

for(int i=0;i<73;i++) {cout<<S[i]<<"  "; jjj(S[i]); cout<<",";}

    return 0;
}