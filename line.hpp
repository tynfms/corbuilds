#ifndef line
#define line

#include "cglobal.hpp"
#include "point.hpp"

struct Line {
	double A, B, C;

	Line () {
		A = B = C = 0.;
	}

	Line (double A_, double B_, double C_) {
		A = A_, B = B_, C = C_;
	} 

	Line (const Point &P, const Point &Q) {
		if (P == Q) {
			std::cerr << "Error on solving the line between [two same points].";
			A = B = C = 0.;
		}
		else if (P.y != Q.y) A = 1., B = (P.x - Q.x) / (Q.y - P.y), C = (P.x * Q.y - P.y * Q.x) / (P.y - Q.y);
		else A = 0., B = 0., C = P.y;
	}

	bool operator == (const Line &l1) const {
		// l1.A / A = l1.B / B = l1.C / C
		return GLOBAL::cmp(l1.A * B, l1.B * A) && GLOBAL::cmp(l1.A * C, l1.C * A) ; 
	}
};

inline void Print(const Line& x) {
	printf("[Line] %.6lf, %.6lf, %.6lf\n", x.A, x.B, x.C);
}

#endif