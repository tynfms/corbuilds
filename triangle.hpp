#ifndef triangle
#define triangle

#include "point.hpp"
#include "line.hpp"
#include "functions.hpp"

namespace tri {
// 三角形的内心
inline Point I(const Point &A, const Point &B, const Point &C) {
	double a = Dist(B, C), b = Dist(A, C), c = Dist(A, B);
	return Point((a * A.x + b * B.x + c * C.x) / (a + b + c), 
  				 (a * A.y + b * B.y + c * C.y) / (a + b + c) 		
				);
}

// 三角形的外心 
inline Point O(const Point &A, const Point &B, const Point &C) {
	double dA = A.x * A.x + A.y * A.y, dB = B.x * B.x + B.y * B.y, dC = C.x * C.x + C.y * C.y;
	double ABx = A.x - B.x, BCx = B.x - C.x, CAx = C.x - A.x;
	double ABy = A.y - B.y, BCy = B.y - C.y, CAy = C.y - A.y;
	return Point(0.5 * (dA * BCy + dB * CAy + dC * ABy) / (A.x * BCy + B.x * CAy + C.x * ABy),
				 0.5 * (dA * BCx + dB * CAx + dC * ABx) / (A.y * BCx + B.y * CAx + C.y * ABx)
				);
}

// 三角形的重心
inline Point G(const Point &A, const Point &B, const Point &C) {
	return Point((A.x + B.x + C.x) / 3., (A.y + B.y + C.y) / 3.);
}

// 三角形的垂心
inline Point H(const Point &A, const Point &B, const Point &C) {
	// return PointDivision(O(A, B, C), G(A, B, C), 3., -2.);
	double dA = A.x * A.x + A.y * A.y, dB = B.x * B.x + B.y * B.y, dC = C.x * C.x + C.y * C.y;
	double ABx = A.x - B.x, BCx = B.x - C.x, CAx = C.x - A.x;
	double ABy = A.y - B.y, BCy = B.y - C.y, CAy = C.y - A.y;
	return Point(A.x + B.x + C.x - (dA * BCy + dB * CAy + dC * ABy) / (A.x * BCy + B.x * CAy + C.x * ABy),
				 A.y + B.y + C.y - (dA * BCx + dB * CAx + dC * ABx) / (A.y * BCx + B.y * CAx + C.y * ABx)
				);
}

// 三角形外接圆半径
inline double R(const Point &A, const Point &B, const Point &C) {
	return Dist(O(A, B, C), A);
}



};

#endif