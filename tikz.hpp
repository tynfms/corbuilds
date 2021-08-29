#ifndef tikz
#define tikz

#include "corbuilds.hpp"
#include "extra.hpp"
#include <fstream>
#include <vector>
#include <windows.h>

class tikz_picture {
private:
	string file_name = "document.tex";
	const string default_file_name = "document.tex";
	FILE* fp;
public:
	inline void set_file_name (string s) {
		file_name = s;
	}
	inline void open_file () { 
		fp = fopen(file_name.c_str(), "w+");
		fprintf(fp, "\\documentclass{article}\n");
		fprintf(fp, "\\usepackage{tikz}\n");
		fprintf(fp, "\\begin{document}\n");
		fprintf(fp, "\\begin{tikzpicture}\n");
	}
	inline void close () {
		fprintf(fp, "\\end{tikzpicture}\n");
		fprintf(fp, "\\end{document}\n"); 
		fclose(fp); 
	}
	inline void set_axis (double xl, double xr, double yd, double yu, bool DrawO = 1) {
		fprintf(fp, "\\draw [thick, ->] (0, %lf) -- (0, %lf);\n", xl, xr);
		fprintf(fp, "\\draw [thick, ->] (%lf, 0) -- (%lf, 0);\n", yd, yu);
		fprintf(fp, "\\node at (%lf, 0) {$x$};\n", xr + 0.4);
		fprintf(fp, "\\node at (0, %lf) {$y$};\n", yu + 0.4);
		if (DrawO) fprintf(fp, "\\node at (-0.4, -0.4) {$O$};\n");
	}
	inline void match_point (vector<Point> v, bool cycle = 1) {
		if (v.size() <= 2) cycle = 0;
		fprintf(fp, "\\draw (%lf, %lf) ", v[0].x, v[0].y);
		for (int i = 1; i < v.size(); i++)
			fprintf(fp, "-- (%lf, %lf) ", v[i].x, v[i].y);
		if (cycle) fprintf(fp, "-- cycle");
		fprintf(fp, ";\n");
	}
	inline void match_point (vector<vector<Point> > v, bool cycle = 1) {
		for (int i = 0; i < v.size(); i++)
			match_point(v[i], cycle);
	}
	inline void node (Point P, int Pd, string Ps) {
		Point Node_Point = Nod(P, Pd);
		fprintf(fp, "\\node at (%lf, %lf) {$%s$};\n", 
			Node_Point.x, Node_Point.y, Ps.c_str());
	}
	inline void node (vector<Point> vP, vector<int> vPd, vector<string> vPs) {
		for (int i = 0; i < vP.size(); i++)
			node(vP[i], vPd[i], vPs[i]);
	}
	inline void stress (Point P, double r = .05) {
		fprintf(fp, "\\filldraw (%lf, %lf) circle (%lf);\n", P.x, P.y, r);
	}
	inline void stress(vector<Point> vP, double r = .05) {
		for (int i = 0; i < vP.size(); i++)
			stress(vP[i], r);
	}
	inline void draw_line (Line l, double l_l, double l_r, bool l_l_d = 0, bool l_r_d = 0) {
		match_point({l_l_d ? PX(l, l_l) : PY(l, l_l), 
			   l_r_d ? PX(l, l_r) : PY(l, l_r)});
	}
	inline void compile() {
		string command = "pdflatex.exe -synctex=1 -interaction=nonstopmode " 
			+ file_name;
		system(command.c_str());
	}
	inline void run() {
		close(); compile();
	}
};
// 辅助tikz绘图代码程序

#endif