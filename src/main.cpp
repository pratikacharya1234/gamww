#include <iostream>
#include <iomanip>

using namespace std;

class Vector2
{
private:
	double x;
	double y;

public:
	// Default constructor: starts at (0, 0)
	Vector2() : x(0.0), y(0.0) {}

	// Constructor with values
	Vector2(double xValue, double yValue) : x(xValue), y(yValue) {}

	double getX() const { return x; }
	double getY() const { return y; }

	void setX(double xValue) { x = xValue; }
	void setY(double yValue) { y = yValue; }

	// Add two vectors: (x1 + x2, y1 + y2)
	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	// Subtract two vectors: (x1 - x2, y1 - y2)
	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	// Multiply vector by scalar: (x * s, y * s)
	Vector2 operator*(double scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	// Divide vector by scalar: (x / s, y / s)
	Vector2 operator/(double scalar) const
	{
		return Vector2(x / scalar, y / scalar);
	}

	// Add and assign: v += other
	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// Subtract and assign: v -= other
	Vector2& operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// Multiply and assign: v *= scalar
	Vector2& operator*=(double scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// Stream output for easy printing
	friend ostream& operator<<(ostream& out, const Vector2& v)
	{
		out << "(" << v.x << ", " << v.y << ")";
		return out;
	}
};

int main()
{
	cout << fixed << setprecision(2);

	// Position and velocity for one game object
	Vector2 position(0.0, 0.0);
	Vector2 velocity(3.0, 1.5);     // units per second
	Vector2 acceleration(0.0, -9.8); // gravity-like acceleration

	double deltaTime = 1.0; // 1 second per update (easy for beginners)

	cout << "Simple Game Physics Engine Demo\n";
	cout << "--------------------------------\n";
	cout << "Start Position: " << position << "\n";
	cout << "Start Velocity: " << velocity << "\n\n";

	// Simulate 5 updates
	for (int step = 1; step <= 5; ++step)
	{
		// velocity = velocity + acceleration * dt
		velocity += acceleration * deltaTime;

		// position = position + velocity * dt
		position += velocity * deltaTime;

		cout << "Step " << step << ":\n";
		cout << "  Velocity: " << velocity << "\n";
		cout << "  Position: " << position << "\n\n";
	}

	// Quick operator examples
	Vector2 a(2.0, 4.0);
	Vector2 b(1.0, -3.0);
	cout << "Operator Examples\n";
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "a + b = " << (a + b) << "\n";
	cout << "a - b = " << (a - b) << "\n";
	cout << "a * 2 = " << (a * 2.0) << "\n";

	return 0;
}
