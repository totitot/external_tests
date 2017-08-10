#include <iostream>
#include <string>

using namespace std;
class Point{ 
	public:
		Point( double x, double y, double z ): m_x(x), m_y(y), m_z(z){}
	private:
		double m_x, m_y, m_z;
};

int main(){
	Point p1;
	//Point p1(1.0,2.0,3.0);
	Point p2(1.0,2.0,3.0);
	Point p3 = p1;
}


