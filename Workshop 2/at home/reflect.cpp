  
  #include <iostream>
using namespace std;

class Point {
	int x;
	int y;
	void out() const {
		cout << x << '|' << y << endl;
	}
public:
	Point() { cout << 'C'; x = 0; y = 2; }
	~Point() { cout << '~'; out(); }
	Point operator++(int) {
		Point p = *this;
		x++;
		return p;
	}
	Point& operator++() {
		y++;
		return *this;
	}
};

int main() {
	Point p[2];
	cout << endl;
	cout << "----" << endl;
	p[0]++;
	cout << "++++" << endl;
	++p[1];
	cout << "====" << endl;
	{	Point q;
		cout << endl;
		++q;
	}
	cout << "----" << endl;
	return 0;
}

