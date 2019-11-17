#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> readFile(void){
    ifstream file;
    int size;
    int n;
    vector<int> line;
    vector<vector<int>> out;
    int temp;

    file.open("test.txt");
    while(!file.eof()){
        file >> n;
        file >> size;
        line.push_back(n);
        line.push_back(size);

        for(int i = 0; i < size; i++){
            file >> temp;
            line.push_back(temp);
        }

        n = 0;
        size = 0;
        out.push_back(line);
        line.clear();
    }

    return out;
}

int main(void) {
    vector<vector<int>> file = readFile();
    vector<int> line;
    int val = 0;

    for(int x = 0; x < 1; x++)
    {
        line = file.at(x);
        int n = line.at(0);

        int array[line.size()-2][n] = {{0}};

        for(int i = 0; i < line.size() - 2; i++)
        {
            val = line.at(i+2);
            for (int j = 1; j < n+1; j++)
            {
                int dividend = j / val;
                int rem = j % val;

                if (dividend == 0)
                {
                    array[i][j-1] = array[i-1][j-1];
                }
                else
                {
                    if(rem == 0)
                    {
                        array[i][j-1] = dividend;
                    }
                    else
                    {
                        array[i][j-1] = dividend + array[i][rem-1];
                    }

                    if(array[i][j-1] > array[i-1][j-1] && i != 0)
                    {
                        array[i][j-1] = array[i-1][j-1];
                    }
                }
            }
        }

        for(int i = 0; i < line.size()-2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << array[i][j] << " ";

            }
            cout << endl;
        }


    }


}
