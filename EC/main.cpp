#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> readFile(void){
    ifstream file;
    string line;
    int size;
    int n;
    vector<int> line;
    vector<vector<int>> out;

    file.open("test.txt");
    while(!file.eof()){
        file << n;
        line.push_back(size);
        line.push_back(n);

        for(int i = 0; i < size; i++){
            int temp;
            file << temp;
            line.push_back(temp);
        }

        n = 0;
        size = 0;
        out.push_back(temp);
        line.clear();
    }

    return out;
}

int main(void) {
    vector<vector<int>> file = readFile();
    vector<int> line;
    int val = 0;

    for(i = 0; i < file.size(); i++)
    {
        line = file.at(i);
        n = file.at(0);
        line.erase(0);

        int array[n][line.size()] = {{0}};

        for(int i = 0; i < line.size(); i++)
        {
            val = line.at(i)
            for int j = 0; j < n; j++)
            {
                int dividend = (j + 1) / val;
                int ret = (j + 1) % 1;

                if dividend
            }
        }


    }


}
