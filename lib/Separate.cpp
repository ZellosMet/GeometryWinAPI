#include"HeadGeometry.h"

//Shape
	Geometry::Shape::Shape(SHAPE_TAKE_PARAMETERSINT) : color(color)
	{
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}
	Geometry::Shape::~Shape() {}
	int Geometry::Shape::get_start_x()const
	{
		return start_x;
	}
	int Geometry::Shape::get_start_y()const
	{
		return start_y;
	}
	int Geometry::Shape::get_line_width()const
	{
		return line_width;
	}
	void Geometry::Shape::set_start_x(int start_x)
	{
		if (start_x < MIN_START_X) start_x = MIN_START_X;
		if (start_x > MAX_START_X) start_x = MAX_START_X;
		this->start_x = start_x;
	}
	void Geometry::Shape::set_start_y(int start_y)
	{
		if (start_y < MIN_START_Y) start_y = MIN_START_Y;
		if (start_y > MAX_START_Y) start_y = MAX_START_Y;
		this->start_y = start_y;
	}
	void Geometry::Shape::set_line_width(int line_width)
	{
		if (line_width < MIN_LINE_WIDTH) line_width = MIN_LINE_WIDTH;
		if (line_width > MAX_LINE_WIDTH) line_width = MAX_LINE_WIDTH;
		this->line_width = line_width;
	}
	void Geometry::Shape::info()const
	{
		std::cout << "Площать фигуры: " << get_area() << std::endl;
		std::cout << "Периметр фигуры: " << get_perimeter() << std::endl;
	}

//Rectangle
	double Geometry::Rectangle::get_length()const
	{
		return side1;
	}
	double Geometry::Rectangle::get_width()const
	{
		return side2;
	}
	void Geometry::Rectangle::set_length(double side1)
	{
		if (side1 < MIN_SIDE) side1 = MIN_SIDE;
		if (side1 > MAX_SIDE) side1 = MAX_SIDE;
		this->side1 = side1;
	}
	void Geometry::Rectangle::set_width(double side2)
	{
		if (side2 < MIN_SIDE) side2 = MIN_SIDE;
		if (side2 > MAX_SIDE) side2 = MAX_SIDE;
		this->side2 = side2;
	}
	Geometry::Rectangle::Rectangle(double side1, double side2, SHAPE_TAKE_PARAMETERSINT) : Shape(SHAPE_GIVE_PARAMETERSINT)
	{
		set_length(side1);
		set_width(side2);
	}
	Geometry::Rectangle::~Rectangle() {}
	double Geometry::Rectangle::get_area()const
	{
		return side1 * side2;
	}
	double Geometry::Rectangle::get_perimeter()const
	{
		return (side1 + side2) * 2;
	}
	void Geometry::Rectangle::get_draw(_In_ HWND &hwnd)const
	{
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		::Rectangle(hdc, start_x, start_y, start_x + side1, start_y + side2);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
	}
	void Geometry::Rectangle::info()const
	{
		std::cout << "Сторона1: " << side1 << std::endl;
		std::cout << "Сторона2: " << side2 << std::endl;
		Shape::info();
	}

//Square
		Geometry::Square::Square(double side, SHAPE_TAKE_PARAMETERSINT) : Rectangle(side, side, SHAPE_GIVE_PARAMETERSINT) {}
		Geometry::Square::~Square() {}

//Circle	
	double Geometry::Circle::get_radius()const
	{
		return radius;
	}
	void Geometry::Circle::set_radius(double radius)
	{
		if (radius < MIN_RADIUS) radius = MIN_RADIUS;
		if (radius > MAX_RADIUS) radius = MAX_RADIUS;
		this->radius = radius;
	}
	Geometry::Circle::Circle(double radius, SHAPE_TAKE_PARAMETERSINT) : Shape(SHAPE_GIVE_PARAMETERSINT)
	{
		set_radius(radius);
	}
	Geometry::Circle::~Circle() {}
	double Geometry::Circle::get_area()const
	{
		return 3.14 * radius * radius;
	}
	double Geometry::Circle::get_perimeter()const
	{
		return 3.14 * radius * 2;
	}
	void Geometry::Circle::get_draw(_In_ HWND &hwnd)const
	{
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		::Ellipse(hdc, start_x, start_y, start_x + radius, start_y + radius);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
	}
	void Geometry::Circle::info()const
	{
		std::cout << "Радиус: " << radius << std::endl;
		Shape::info();
	}

//Tringle
	double Geometry::Triangle::get_side1()const
	{
		return side1;
	}
	double Geometry::Triangle::get_side2()const
	{
		return side2;
	}
	double Geometry::Triangle::get_side3()const
	{
		return side3;
	}
	double Geometry::Triangle::get_angle()const
	{
		return angle;
	}
	void Geometry::Triangle::set_side1(double side1)
	{
		if (side1 < MIN_SIDE1) side1 = MIN_SIDE1;
		if (side1 > MAX_SIDE1) side1 = MAX_SIDE1;
		this->side1 = side1;
	}
	void Geometry::Triangle::set_side2(double side2)
	{
		if (side2 < MIN_SIDE2) side2 = MIN_SIDE2;
		if (side2 > MAX_SIDE2) side2 = MAX_SIDE2;
		this->side2 = side2;
	}
	void Geometry::Triangle::set_side3(double side3)
	{
		if (side3 < MIN_SIDE3) side3 = MIN_SIDE3;
		if (side3 > MAX_SIDE3) side3 = MAX_SIDE3;
		this->side3 = side3;
	}
	void Geometry::Triangle::set_angle(double angle)
	{
		if (angle < MIN_ANGLE) angle = MIN_ANGLE;
		if (angle > MAX_ANGLE) angle = MAX_ANGLE;
		this->angle = angle;
	}
	Geometry::Triangle::Triangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT) : Shape(SHAPE_GIVE_PARAMETERSINT)
	{
		set_side1(side1);
		set_side2(side2);
		set_side3(sqrt(pow(side1, 2) + pow(side2, 2) - 2 * side1 * side2 * (cos(angle * 0.0175))));
		set_angle(angle);
		pt[0].x = start_x;
		pt[0].y = start_y;
		(angle == 90) ? pt[1].x = start_x : (angle < 90) ? pt[1].x = start_x - side1 : pt[1].x = start_x + side1;
		(angle == 90) ? pt[1].y = start_y + side1 : (angle < 90) ? pt[1].y = start_y + side1 : pt[1].y = start_y + side1;
		(angle == 90) ? pt[2].x = pt[1].x + side2 : pt[2].x = pt[1].x + side2;
		(angle == 90) ? pt[2].y = pt[1].y : pt[2].y = pt[1].y;
	}
	Geometry::Triangle::~Triangle() {}
	double Geometry::Triangle::get_area()const
	{
		double p = get_perimeter() / 2;
		return sqrt(fabs(p * (p - side1) * (p - side2) * (p - side3)));
	}
	double Geometry::Triangle::get_perimeter()const
	{
		return side1 + side2 + side3;
	}
	void Geometry::Triangle::get_draw(_In_ HWND &hwnd)const
	{
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, 5, color);
		HBRUSH hBrush = CreateSolidBrush(color);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		::Polygon(hdc, pt, point);

		DeleteObject(hPen);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
	}
	void Geometry::Triangle::info()const
	{
		std::cout << "Сторона1: " << side1 << std::endl;
		std::cout << "Сторона2: " << side2 << std::endl;
		std::cout << "Сторона3: " << side3 << std::endl;
		std::cout << "Угол: " << angle << std::endl;
		Shape::info();
	}
//AcuteTriangle

	Geometry::AcuteTriangle::AcuteTriangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT) : Triangle(side1, side2, angle, SHAPE_GIVE_PARAMETERSINT) {}
	Geometry::AcuteTriangle::~AcuteTriangle() {}
//Rightriangle
	Geometry::RightTriangle::RightTriangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT) : Triangle(side1, side2, angle, SHAPE_GIVE_PARAMETERSINT) {}
	Geometry::RightTriangle::~RightTriangle() {}

//ObtusTriangle
	Geometry::ObtuseTriangle::ObtuseTriangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT) : Triangle(side1, side2, angle, SHAPE_GIVE_PARAMETERSINT) {}
	Geometry::ObtuseTriangle::~ObtuseTriangle() {}