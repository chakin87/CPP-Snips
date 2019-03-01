#include <iostream>
#include <cmath>


using namespace std;

int ch;
double x;
double y;
double a;
double b;
double answer;

double distanceBetweenTwoPoints(double x, double y, double a, double b);

int main() {

	cout << "Enter the points for the coordinates";
	cout << endl;
	cout << "Point x for first coordinates: ";
	cin >> x;
	cout << endl;
	cout << endl;
	cout << "Point y for first coordinate: ";
	cin >> y;
	cout << endl;
	cout << endl;
	cout << "Point x for the second coordinate: ";
	cin >> a;
	cout << endl;
	cout << endl;
	cout << "Point y for the second coordinate: ";
	cin >> b;
	cout << endl;
	cout << endl;
	answer = distanceBetweenTwoPoints(x, y, a, b);
	cout << "The answer is " << answer;


	getchar();
	return 0;
}

double distanceBetweenTwoPoints(double x, double y, double a, double b) {
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}