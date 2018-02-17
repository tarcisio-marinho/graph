#include<vector>
#include<iostream>

using namespace std;

vector<vector<int> > matrix_to_adj(int mat[3][3]){
    vector<vector<int> > adj;
    for(int i = 0; i < 3; i++){
        vector<int> novo;
        for(int j = 0; j < 3; j++){
            if(mat[i][j] != 0){
                novo.push_back(mat[i][j]);
            }else{
                novo.push_back(-99);
            }
        }
        adj.push_back(novo);
    }

    return adj;
}



int main(){
    vector<vector<int> > matrix;
    int mat[3][3] = {{1, 0, 0}, {1, 0, 1}, {0, 1, 0}};

    
    matrix = matrix_to_adj(mat);

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "i: " << i << " - j: " << j  << " valor: "<< matrix[i][j] << endl;
        }
        cout << endl;
    }


    
    return 0;
}