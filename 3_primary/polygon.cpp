#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

int main(void)
{
   //TODO change this to cmd input
   std::ifstream polygonFile("polygons.txt");
   int polygonSize = 0;
   std::vector<std::pair<double, double>> points;
   std::pair<double, double> tempPoint;

   polygonFile >> polygonSize;
   do
   {
      for(int i = 0; i < polygonSize; i++)
      {
         polygonFile >> tempPoint.first >> tempPoint.second;

         points.push_back(tempPoint);
      }



      polygonFile >> polygonSize;
   }
   while(polygonSize > 3);



}
