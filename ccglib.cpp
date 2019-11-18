#include <bits/stdc++.h>
using namespace std;

// chris computational geometry library (ccglib)
namespace ccglib {
	struct vector3D {
		double x, y, z;
		vector3D(double _x = 0, double _y = 0, double _z = 0): x(_x), y(_y), z(_z) {}
		vector3D operator-() const {
			return vector3D(-x, -y, -z);
		}
		vector3D operator+(const vector3D& r) const {
			return vector3D(x+r.x,y+r.y,z+r.z);
		}
		vector3D operator-(const vector3D& r) const {
			return vector3D(x-r.x,y-r.y,z-r.z);
		}
		vector3D operator*(double r) const {
			return vector3D(x*r,y*r,z*r);
		}
		friend vector3D operator*(double l, const vector3D& r) {
			return vector3D(l*r.x,l*r.y,l*r.z);
		}
		vector3D operator/(double r) const {
			return vector3D(x/r,y/r,z/r);
		}
		double operator*(const vector3D& r) const { // dot product
			return x*r.x+y*r.y+z*r.z;
		}
		vector3D operator%(const vector3D& r) const { // cross product
			return vector3D(y*r.z-r.y*z, z*r.x-r.z*x, x*r.y-r.x*y);
		}
		bool operator==(const vector3D& r) const {
			return (x == r.x) && (y == r.y) && (z == r.z);
		}
		bool operator!=(const vector3D& r) const {
			return (x != r.x) || (y != r.y) || (z != r.z);
		}
		bool operator<(const vector3D& r) const {
			if (x != r.x) return x < r.x;
			if (y != r.y) return y < r.y;
			return z < r.z;
		}
		void print() const {
			printf("%lf %lf %lf\n",x,y,z);
		}
		void apply_eps(double eps = 1e-9) {
			x = (abs(x) < eps ? 0 : x);
			y = (abs(y) < eps ? 0 : y);
			z = (abs(z) < eps ? 0 : z);
		}
	};
	double norm(const vector3D& u) {
		return sqrt(dot(u,u));
	}
	vector3D proj(const vector3D& u, const vector3D& v) {
		return (dot(u,v)/dot(v,v))*v;
	}
	vector3D perp(const vector3D& u, const vector3D& v) {
		return u-proj(u,v);
	}
	int convex2D_tests(const vector<vector3D>& points, bool pt = 0, vector3D ref = vector3D()) {
		int n = points.size(), t = -2, dir = -2;
		if (n < 3) return -2;
		double res = 0; bool zr = 0;
		for (int i = 0; i < n; i++) {
			res = (pt ? cross(points[i]-ref,points[(i+1)%n]-ref) : cross(points[i]-points[(i-1+n)%n], points[(i+1)%n]-points[i])).z;
			t = (res > 0 ? 1 : (res < 0 ? -1: 0));
			dir = (i == 0 ? t : (t == 0 ? dir : (dir == 0 ? t : (dir == t ? dir : -2))));
			if (pt) zr = (zr ? 1 : (t == 0));
		}
		return (!pt ? dir : (!zr ? dir : (dir != -2 ? 0 : -2)));
	}
	double area2D(const vector<vector3D>& points) {
		int n = points.size();
		if (n < 3) return 0;
		double ans = 0;
		for (int i = 0, j = n-1; i < n; j = i++)
			ans += cross(points[i],points[j]).z;
		return abs(ans)/2.0;
	}
	vector<vector3D> convex_hull(vector<vector3D> pts) {
		sort(pts.begin(), pts.end());
		int top = 0;
		vector<vector3D> stk(2*pts.size());
		for (int i = 0; i < pts.size(); i++) {
			while (top >= 2 and cross(stk[top-1]-stk[top-2], pts[i]-stk[top-2]).z <= 0) top--;
			stk[top++] = pts[i];
		}
		for (int i = pts.size()-2, t = top+1; i >= 0; i--) {
			while (top >= t and cross(stk[top-1]-stk[top-2], pts[i]-stk[top-2]).z <= 0) top--;
			stk[top++] = pts[i];
		}
		stk.resize(top-1);
		return stk;
	}
	vector3D to_implicit(vector3D u, vector3D v) {
		return cross(u,v);
	}
	pair<vector3D, vector3D> to_four_numbers(vector3D u, bool type) {
		double d = -u.z/(dot(u,u)-u.z*u.z);
		return make_pair(vector3D(d*u.x, d*u.y, 1), vector3D(d*u.x*type + u.y, d*u.y*type - u.x, type));
	}
}

int main() {
	
	return 0;
}