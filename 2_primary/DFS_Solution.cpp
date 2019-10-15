#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <float.h>
using namespace std;

class GraphSolver{

   public:
      int nodeTotal;
      int k;
      int end;
      vector<bool> visited;
      vector<vector<int>> finalPath;
      double **graph;
      double **results;

      GraphSolver(int sizeIn, double** graphIn, int maxK, int endIn)
      {
         graph = new double*[sizeIn];
         results = new double*[sizeIn];
         visited = vector<bool>(sizeIn, false);
         finalPath = vector<vector<int>>(maxK, vector<int>(sizeIn));

         for( int i = 0; i < sizeIn; i++)
         {
            graph[i] = new double[sizeIn];
            results[i] = new double[maxK];
            for (int j = 0; j < maxK; j++)
            {
               results[i][j] = DBL_MAX;
            }
         }


         graph = graphIn;
         nodeTotal = sizeIn;
         k = maxK;
         end = endIn;

      }


      vector<int> DFS(int vertex, double currentWeight,vector<int> currentPath)
      {
            visited[vertex] = true;
            currentPath.push_back(vertex);
            if (currentPath.size()-2 >= 0)
               currentWeight += graph[vertex][currentPath.at(currentPath.size()-2)];

            if (graph[vertex][currentPath[currentPath.size()-2]] > 0
                  && currentPath.size() - 2 < k
                  && results[vertex][currentPath.size()-2] > currentWeight)
            {
               results[vertex][currentPath.size()-2] = currentWeight;
               finalPath[currentPath.size()-2].clear();
               finalPath[currentPath.size()-2] = currentPath;
               for (int i = currentPath.size()-2; i < k; i++)
               {
                  if(results[vertex][i] > currentWeight)
                  {
                     results[vertex][i] = currentWeight;
                     finalPath[i].clear();
                     finalPath[i] = currentPath;
                  }
               }
            }

            for(int i = 0; i < nodeTotal; i++)
            {
               if(vertex != end) {
                  if ( graph[vertex][i] > 0 && !visited[i])
                  {
                     if( graph[vertex][i] + currentWeight < results[i][currentPath.size() - 1])
                     {
                        currentPath = DFS(i, currentWeight, currentPath);
                        currentPath.pop_back();
                        visited[i] = false;
                     }
                  }
               }
            }
            return currentPath;

      }
};


// Written by Ayden
double **read_file(string file_name, int& size){
   ifstream inFile;
   double t;
   int counter = 0;
   inFile.open(file_name);
   if (!inFile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
   }
   inFile >> size;
   double **graph = new double*[size];
   for(int i = 0; i < size; ++i)
      graph[i] = new double[size];
   while (inFile >> t) {
      graph[counter/size][counter%size] = t;
      counter +=1;
   }
   inFile.close();
   return graph;
}


int main(int argc, char* argv[])
{
   // input comes in like `inputGraph start end k`
   double ** graph;
   int start = atoi(argv[2]) - 1; // All graphs inside the Solver are 0 indexed
   int end = atoi(argv[3]) - 1;
   int k = atoi(argv[4]);
   int size;
   vector<int> path;

   graph = read_file(argv[1], size);

   GraphSolver test(size, graph, k, end);


   test.DFS(start, 0.0, path);

   cout << test.results[end][k-1] << endl;

   cout << "Final Path: " << endl;
   for(int j = 0; j < k+1; j++)
   {
      cout << test.finalPath[k-1][j]+1 << " ";

   }
   cout << endl;

}




