#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

bool onSegment(std::pair<double, double> pi,
        std::pair<double, double> pj,
        std::pair<double, double> pk)
{
    if( (std::min(pi.first, pj.first) <=  pk.first && pk.first <= std::max(pi.first, pj.first))
            && (std::min(pi.second, pj.second) <=  pk.second && pk.second <= std::max(pi.second, pj.second)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double direction(std::pair<double, double> pi,
        std::pair<double, double> pj,
        std::pair<double, double> pk)
{
    std::pair<double, double> left;
    std::pair<double, double> right;
    double retval = 0;

    left.first = pk.first - pi.first;
    left.second = pk.second - pi.second;

    right.first = pj.first - pi.first;
    right.second = pj.second - pi.second;

    retval = (left.first * right.second) - (right.first * left.second);
    return retval;
}


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
    int polyCount = 1;

    polygonFile >> polygonSize;
    do
    {
        for(int i = 0; i < polygonSize; i++)
        {
            polygonFile >> tempPoint.first >> tempPoint.second;
            points.push_back(tempPoint);
        }

        std::cout << "Polygon " << polyCount << endl;








        polygonFile >> polygonSize;
    }
    while(polygonSize > 2);



}
