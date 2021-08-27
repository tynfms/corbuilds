#ifndef cglobal
#define cglobal

#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

// typedef
typedef long long ll;
const double PI = acos(-1.);

namespace GLOBAL {
double eps = 1e-8;
const double DelPx[8] = {1., 1., 1., 0., -1., -1., -1., 0.};
const double DelPy[8] = {1., 0., -1., -1., -1., 0., 1., 1.};
inline bool cmp(const double &x, const double &y) {
	return fabs(x - y) < eps;
}

}

#endif