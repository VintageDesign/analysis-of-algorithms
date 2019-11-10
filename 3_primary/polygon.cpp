#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;
bool onSegment(pair<double, double> pi,
        pair<double, double> pj,
        pair<double, double> pk)
{
    if( (min(pi.first, pj.first) <=  pk.first && pk.first <= max(pi.first, pj.first))
            && (min(pi.second, pj.second) <=  pk.second && pk.second <= max(pi.second, pj.second)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double direction(pair<double, double> pi,
        pair<double, double> pj,
        pair<double, double> pk)
{
    pair<double, double> left;
    pair<double, double> right;
    double retval = 0;

    left.first = pk.first - pi.first;
    left.second = pk.second - pi.second;

    right.first = pj.first - pi.first;
    right.second = pj.second - pi.second;

    retval = (left.first * right.second) - (right.first * left.second);

    if(retval < 0)
    {
        retval = -1;
    }
    else if (retval > 0)
    {
        retval = 1;
    }
    else
    {
        retval = 0;
    }

    return retval;
}


bool segementsIntersect(pair<double, double> p1,
        pair<double, double> p2,
        pair<double, double> p3,
        pair<double, double> p4)
{
    double d1 = direction(p3, p4, p1);
    double d2 = direction(p3, p4, p2);
    double d3 = direction(p1, p2, p3);
    double d4 = direction(p1, p2, p4);
    bool retval = false;

    if( ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
            && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    {
        retval = true;
    }
    else if ( d1 == 0 && onSegment(p3, p4, p1))
    {
        retval = true;
    }
    else if ( d2 == 0 && onSegment(p3, p4, p2))
    {
        retval = true;
    }
    else if ( d3 == 0 && onSegment(p1, p2, p3))
    {
        retval = true;
    }
    else if ( d4 == 0 && onSegment(p1, p2, p4))
    {
        retval = true;
    }

    return retval;
}

int main(void)
{
    //TODO change this to cmd input
    ifstream polygonFile("polygons.txt");
    int polygonSize = 0;
    vector<pair<double, double>> points;
    pair<double, double> tempPoint;
    int polyCount = 1;
    bool hasCross = false;
    vector<double> angles;

    polygonFile >> polygonSize;
    do
    {
        for(int i = 0; i < polygonSize; i++)
        {
            polygonFile >> tempPoint.first >> tempPoint.second;
            points.push_back(tempPoint);
        }

        cout << "Polygon " << polyCount << endl;

        for(int i = 0; i < points.size() && !hasCross; i++)
        {
            pair<double,double> p2 = points.at((i+1)%points.size());
            pair<double,double> p3 = points.at((i+2)%points.size());
            pair<double,double> p4 = points.at((i+3)%points.size());

            if(polygonSize != 3)
            {
                hasCross |= segementsIntersect(points.at(i), p2, p3, p4);
            }
            angles.push_back(direction(points.at(i), p2, p3));

        }

        if(hasCross)
        {
            cout << "  Not simple" << endl;
        }
        else
        {
            cout << "  Simple" << endl;
           int leftCount = 0;
           int rightCount = 0;

            for(int i = 0; i < angles.size(); i++)
            {
               if(angles.at(i) < 0)
                   leftCount++;
               if(angles.at(i) > 0)
                   rightCount++;
            }

            if(leftCount == 0 || rightCount == 0)
            {
                cout << "  Convex" << endl;
            }
            else
            {
                cout << "  Not convex" << endl;
            }

            if(leftCount < rightCount)
            {
                cout << "  Clockwise" << endl;
            }
            else
            {
                cout << "  Counterclockwise" << endl;
            }
        }






        points.clear();
        angles.clear();
        hasCross = false;
        polygonFile >> polygonSize;
        polyCount++;
    }
    while(polygonSize > 2);



}
