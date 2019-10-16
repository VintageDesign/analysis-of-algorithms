#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <float.h>
#include <algorithm>
using namespace std;


struct Edge
{
   int to;
   int from;
   double cost;
};

class GraphSolver{

   public:
      int nodeTotal;
      int k;
      int end;
      int start;
      double **path;
      vector<struct Edge> edges;
      vector<vector<int>> finalPath;


      GraphSolver(int sizeIn, vector<struct Edge> edgeIn, int maxK,int startIn, int endIn)
      {
         path = new double*[maxK+1];

         for( int i = 0; i < maxK+1; i++)
         {
            path[i] = new double[sizeIn];
            for (int j = 0; j < sizeIn; j++)
            {
               path[i][j] = DBL_MAX;
            }
         }


         edges = edgeIn;
         nodeTotal = sizeIn;
         k = maxK;
         end = endIn;
         start = startIn;

         finalPath = vector<vector<int>> (edgeIn.size(), vector<int>(0));

      }

      double** Solve()
      {
         path[0][start] = 0;
         int s = 0;
         int t = 0;

         for (int i = 0; i < finalPath.size(); i++)
         {
            finalPath[i].push_back(start);
         }

         for(int kIndex = 1; kIndex < k+1; kIndex++)
         {
            for(int i = 0; i < edges.size(); i++)
            {
               s = edges[i].from;
               t = edges[i].to;
               if( path[kIndex][t] > min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost))
               {
                  path[kIndex][t] = min( path[kIndex][t], min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost));
                  finalPath[i].pop_back();
                  finalPath[i].push_back(t);

               }
               t = edges[i].from;
               s = edges[i].to;
               if( path[kIndex][t] > min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost))
               {
                  path[kIndex][t] = min( path[kIndex][t], min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost));
                  finalPath[i].pop_back();
                  finalPath[i].push_back(t);
               }
            }
         }

         return path;

      }
};

vector<struct Edge> read_file(string file_name, int& size){
   ifstream inFile;
   vector<Edge> graphEdges;
   Edge temp;
   double t;
   int counter = 0;
   inFile.open(file_name);
// Written by Ayden
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
// End of Ayden Code
   for(int i = 0; i < size; i++)
   {
      for(int j = i + 1; j < size; j++)
      {
         if(graph[i][j] > 0)
         {
            temp.from = i;
            temp.to = j;
            temp.cost = graph[i][j];
            graphEdges.push_back(temp);
         }
      }
   }

   return graphEdges;
}


int main(int argc, char* argv[])
{
   // input comes in like `inputGraph start end k`
   vector<struct Edge> graph;
   int start = atoi(argv[2]) - 1; // All graphs inside the Solver are 0 indexed
   int end = atoi(argv[3]) - 1;
   int k = atoi(argv[4]);
   int size;
   double ** final;

   graph = read_file(argv[1], size);

   /*
   for(auto e: graph)
   {
      cout << "V<f,t>: " << e.to << " " << e.from
         << " Cost: " << e.cost << endl;
   }
   */


   GraphSolver test(size, graph, k, start, end);
   final = test.Solve();

   cout << "Cost: " << final[k][end] << endl;

   for (int j = 0; j <= k; j++)
   {
      for(int i = 0; i < test.finalPath[j].size(); i++)
      {
         cout << test.finalPath[j][i] +1 << " ";
      }
   }
   cout << endl;






}




