#ifndef functions
#define functions

#include "point.hpp"
#include "line.hpp"

// 点到点的距离
inline double Dist(const Point &A, const Point &B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

// 点到直线的距离
inline double Dist(const Point &P, const Line &l) {
	return fabs(l.A * P.x + l.B * P.y + l.C) / sqrt(P.x * P.x + P.y * P.y);
}

// 等分线段
inline Point PointDivision(const Point &A, const Point &B, double x = 1., double y = 1.) {
	return Point((A.x * x + B.x * y) / (x + y), (A.y * x + B.y * y) / (x + y));
}

// P作到直线l的垂足
inline Point FootPoint(const Point &P, const Line &l) {
	double A = l.A, B = l.B, C = l.C, x = P.x, y = P.y;
	return Point((B * B * x - A * B * y - A * C) / (A * A + B * B),
				 (A * A * y - A * B * x - B * C) / (A * A + B * B)
				);
}

// P关于直线l的对称点
inline Point OppositePoint(const Point &P, const Line &l) {
	double A = l.A, B = l.B, C = l.C, x = P.x, y = P.y;
	return Point(((B * B - A * A) * x - 2 * A * B * y - 2 * A * C) / (A * A + B * B),
				 ((A * A - B * B) * y - 2 * A * B * x - 2 * B * C) / (A * A + B * B)				
				);
}

inline double XKnown(const Line &l, const double &x) { return - (l.A * x + l.C) / l.B; } // 在直线l上横坐标为x的点
inline double YKnown(const Line &l, const double &y) { return - (l.B * y + l.C) / l.A; } // 在直线l上纵坐标为y的点

// l关于l0的对称直线
inline Line OppositeLine(const Line &l, const Line &l0) {
	double L = l0.A, M = l0.B, N = l0.C, A = l.A, B = l.B, C = l.C;
	return Line(2 * A * B * M + L * (A * A - B * B),
				2 * A * B * L + M * (B * B - A * A),
				2 * A * C * L + 2 * B * C * M - N * (A * A + B * B)
			   );
}

// 两直线的交点
inline Point TwoLines(const Line &A, const Line &B) {
	double a = A.A, b = A.B, c = B.A, d = B.B, e = -A.C, f = -B.C;
	return Point((d * e - b * f) / (a * d - b * c), 
				 (a * f - c * e) / (a * d - b * c)
				); 
}



#endif