#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

bool segementsIntersect(std::pair<double, double> p1,
                        std::pair<double, double> p2,
                        std::pair<double, double> p3,
                        std::pair<double, double> p4)
{
   double d1 = direction(p3, p4, p1);
   double d2 = direction(p3, p4, p2);
   double d3 = direction(p1, p2, p3);
   double d4 = direction(p1, p2, p4);
   bool retval = false;

   if( ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
    && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
      retval = true;
   else if ( d1 == 0 && onSegment(p3, p4, p1))
      retval = true;
   else if ( d2 == 0 && onSegment(p3, p4, p2))
      retval = true;
   else if ( d3 == 0 && onSegment(p1, p2, p3))
      retval = true;
   else if ( d4 == 0 && onSegment(p1, p2, p4))
      retval = true;

   return retval;
}

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
