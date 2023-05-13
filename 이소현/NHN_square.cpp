#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

double get_distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool middleCmp(Point p1, Point p2, Point p3, Point p4){
	if((p1.x+p3.x == p2.x+p4.x) && (p1.y+p3.y == p2.y+p4.y))
		return true;
	return false;
}

int main() {
    int n;
    cin >> n;

    Point points[51];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
					if(i==j)continue;
            for (int k = 0; k < n ; k++) {
							if(i==k||j==k)continue;
                for (int l = 0; l < n; l++) {
									if(i==l||j==l||k==l)continue;
									if(middleCmp(points[i],points[j],points[k],points[l])){
                    double d1 = get_distance(points[i], points[j]);
                    double d2 = get_distance(points[j], points[k]);
                    double d3 = get_distance(points[k], points[l]);
                    double d4 = get_distance(points[l], points[i]);
										
                    double d5 = get_distance(points[i], points[k]);
                    double d6 = get_distance(points[j], points[l]);

                    if (d1 == d2 && d3 == d4 && d5 == d6) {
                        double area = d1*d2;
                        if (area > max_area) {
                            max_area = area;
                        }
                    }
									}
                }
            }
        }
    }
	printf("%.2f",max_area);

    return 0;
}