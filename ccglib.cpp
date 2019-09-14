#include <bits/stdc++.h>
using namespace std;

// chris computational geometry library (ccglib)
namespace ccglib {
	struct vector3D {
		double x, y, z;
		vector3D(): x(0), y(0), z(0) {}
		vector3D(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
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
		bool operator==(const vector3D& r) const {
			return (x == r.x) && (y == r.y) && (z == r.z);
		}
		bool operator!=(const vector3D& r) const {
			return (x != r.x) || (y != r.y) || (z != r.z);
		}
		void print() const {
			printf("%lf %lf %lf\n",x,y,z);
		}
	};
	double dot(const vector3D& u, const vector3D& v) {
		return u.x*v.x+u.y*v.y+u.z*v.z;
	}
	double norm(const vector3D& u) {
		return sqrt(dot(u,u));
	}
	vector3D cross(const vector3D& u, const vector3D& v) {
		return vector3D(u.y*v.z-v.y*u.z, u.z*v.x-v.z*u.x, u.x*v.y-v.x*u.y);
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
		double ref = 0; bool zr = 0;
		for (int i = 0; i < n; i++) {
			if (!pt) ref = cross(points[i]-points[(i-1+n)%n], points[(i+1)%n]-points[i]).z;
			else ref = cross(points[i]-ref,points[(i+1)%n]-ref).z;
			t = (ref > 0 ? 1 : (ref < 0 ? -1: 0));
			if (!pt) dir = (i == 0 ? t : (t == 0 ? dir : (dir == 0 ? t : (dir == t ? dir : -2))));
			else dir = (i == 0 ? t : (t == 0 ? dir : (dir == 0 ? t : (dir == t ? dir : -2)))), zr = (zr ? 1 : (t == 0));
		}
		return (!pt ? dir : (zr && (dir != -2)));
	}
	double area2D(const vector<vector3D>& points) {
		int n = points.size();
		if (n < 3) return 0;
		double ans = 0;
		for (int i = 0, j = n-1; i < n; j = i++)
			ans += cross(points[i],points[j]).z;
		return abs(ans)/2.0;
	}
}

int main() {
	ccglib::vector3D a(1,0,0), b(0,1,0), c(0,0,1), temp;
	a.print();
	temp.print();
	temp = -ccglib::vector3D(1,0,0);
	temp.print();
	return 0;
}