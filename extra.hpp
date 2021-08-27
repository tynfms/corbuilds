#ifndef extra
#define extra

#include "cglobal.hpp"
#include "point.hpp"
#include "line.hpp"

// 在编辑tikz中标注点位置的辅助函数
inline Point Nod(const Point &P, const int &dir, double Delt = 0.4) {
	return Point(P.x + GLOBAL::DelPx[dir] * Delt, P.y + GLOBAL::DelPy[dir] * Delt);
}

// 多变量输出函数
void Print() { printf("\n"); }
void Print(const double& x) { printf("[Double] %.6lf\n", x); }
void Print(const string& s) { printf("[String] %s\n", s.c_str()); }
template <typename T, typename... Ts>
void Print(const T& arg, const Ts&... args) {
	Print(arg); Print(args...);
}


#endif