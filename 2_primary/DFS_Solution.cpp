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
      int **finalPath;


      GraphSolver(int sizeIn, vector<struct Edge> edgeIn, int maxK,int startIn, int endIn)
      {
         path = new double*[maxK+1];
         finalPath = new int*[maxK+1];

         for( int i = 0; i < maxK+1; i++)
         {
            path[i] = new double[sizeIn];
            finalPath[i] = new int[sizeIn];
            for (int j = 0; j < sizeIn; j++)
            {
               path[i][j] = DBL_MAX;
               finalPath[i][j] = -1;
            }
         }


         edges = edgeIn;
         nodeTotal = sizeIn;
         k = maxK;
         end = endIn;
         start = startIn;


      }

      double** Solve()
      {
         path[0][start] = 0;
         int s = 0;
         int t = 0;


         for(int kIndex = 1; kIndex < k+1; kIndex++)
         {
            for(int i = 0; i < edges.size(); i++)
            {
               s = edges[i].from;
               t = edges[i].to;
               if( path[kIndex][t] > min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost))
               {
                  path[kIndex][t] = min( path[kIndex][t], min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost));
                  if(path[kIndex][t] == path[kIndex-1][t])
                     finalPath[kIndex][t] = finalPath[kIndex-1][t];
                  else
                     finalPath[kIndex][t] = s;

               }
               t = edges[i].from;
               s = edges[i].to;
               if( path[kIndex][t] > min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost))
               {
                  path[kIndex][t] = min( path[kIndex][t], min(path[kIndex-1][t],path[kIndex-1][s] + edges[i].cost));
                  if(path[kIndex][t] == path[kIndex-1][t])
                     finalPath[kIndex][t] = finalPath[kIndex-1][t];
                  else
                     finalPath[kIndex][t] = s;
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
   cout << "===========================================================" << endl;
   for(int iter = 0; iter < (argc-1) /4 ; iter++)
   {
      cout << "Test " << iter + 1 << endl;
      // input comes in like `inputGraph start end k`
      vector<struct Edge> graph;
      int start = atoi(argv[iter*4 + 2]) - 1; // All graphs inside the Solver are 0 indexed
      int end = atoi(argv[iter*4 + 3]) - 1;
      int k = atoi(argv[iter*4 + 4]);
      int size;
      double ** final;
      vector<int> pathStack;
      int buildK;

      graph = read_file(argv[iter*4 + 1], size);

      GraphSolver test(size, graph, k, start, end);
      final = test.Solve();

      // Path
      // the worst possible way to do this but.... Im still gonna send it.
      buildK = k;
      pathStack.push_back(end);
      while (pathStack.back() != start)
      {
         pathStack.push_back(test.finalPath[buildK][pathStack.back()]);
         buildK--;
      }

      for(int i = 0; i < k +1; i++)
      {
         for(int j = 0; j < size; j++)
         {
            cout << test.finalPath[i][j]  + 1<< " ";
         }
         cout << endl;
      }

      buildK = 0;
      cout << "Path: ";
      if (final[k][end] == DBL_MAX)
      {
         cout << "None" << endl;
      }
      else
      {
         while(pathStack.size() != 1)
         {
            cout << pathStack.back() + 1 << " to ";
            pathStack.pop_back();
            buildK++;
         }

         cout << pathStack.back() + 1<< endl;
         //cost
         cout << "Cost: " << final[k][end] << endl;
         cout << "===========================================================" << endl;
      }
   }
}




