#ifndef point
#define point

#include "cglobal.hpp"

struct Point {
	double x, y;
	
	Point (double x_, double y_) {
		x = x_, y = y_;
	}

	bool operator == (const Point &p) const {
		return GLOBAL::cmp(x, p.x) && GLOBAL::cmp(y, p.y); 
	} 
};

inline void Print(const Point& x) {
	printf("[Point] (%.6lf, %.6lf)\n", x.x, x.y);
}

#endif