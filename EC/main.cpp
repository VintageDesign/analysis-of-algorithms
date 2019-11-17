#include <iostream>
#include <vector>
#include <fstream>
#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> readFile(void){
    ifstream            file;
    int                 size;
    int                 n;
    int                 temp;
    vector<int>         line;
    vector<vector<int>> out;

    file.open("test.txt");


    // Read in the whole file into a vector per line
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
    vector<int>         line;
    int                 minValPos;
    int                 val = 0;
    int                 n = 0;
    int                 temp = 0;

    for(int x = 0; x < file.size()-1; x++)
    {
        cout << "Test " << x + 1 << endl;
        minValPos = 0;
        line = file.at(x);
        n = line.at(0);

        cout << "Input: s = {";


        int array[line.size()-2][n] = {{0}};

        for(int i = 0; i < line.size() - 2; i++)
        {
            val = line.at(i+2);
            if(i >= line.size() - 3)
            {
                cout << val << "}, ";
            }
            else
            {
                cout << val << ", ";
            }
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

                    /*if(array[i][j-1] > array[i-1][j-1] && i != 0)
                    {
                        array[i][j-1] = array[i-1][j-1];
                    }*/
                }
            }
        }

        cout << "n =  " << n << endl;


        for(int i = 0; i < line.size() - 2; i++)
        {
           if( array[i][n-1] < array[minValPos][n-1])
               minValPos = i;
        }
        cout << "Min Count: " << array[minValPos][n-1] << endl << "Result: ";

        temp = n;


        while(temp > 0)
        {
            temp -= line[minValPos + 2];
            if(temp >= line[minValPos + 2])
            {
                cout << line[minValPos + 2] << ", ";
            }
            else
            {
                if (temp == 0)
                {
                    cout << line[minValPos + 2] << endl;
                }
                else
                {
                    cout << line[minValPos + 2] << ", ";
                    minValPos -= 1;

                }
            }
        }
        cout << "=============================================================" << endl;
    }


}
