#pragma once
#include<Windows.h>
#include<iostream>
#include<ctime>

namespace Geometry
{
	enum Color
	{
	red = 0x000000FF,
	green = 0x00FF000,
	blue = 0x00FF0000,
	yelloy = 0x0000FFFF,

	console_red = 0xCC, //0x - шестнадцаричиный
	console_green = 0xAA,
	console_blue = 0x99,
	console_defauit = 0x07
	};
	#define SHAPE_TAKE_PARAMETERSINT int start_x, int start_y, int line_width, Color color
	#define SHAPE_GIVE_PARAMETERSINT start_x, start_y, line_width, color

	class Shape
	{
		static const int MIN_START_X = 10;
		static const int MIN_START_Y = 10;
		static const int MAX_START_X = 500;
		static const int MAX_START_Y = 400;
		static const int MIN_LINE_WIDTH = 5;
		static const int MAX_LINE_WIDTH = 25;
	protected:
		int start_x;
		int start_y;
		int line_width;
		Color color;
	public:
		Shape(SHAPE_TAKE_PARAMETERSINT);
		virtual ~Shape();
		int get_start_x()const;
		int get_start_y()const;
		int get_line_width()const;
		void set_start_x(int start_x);
		void set_start_y(int start_y);
		void set_line_width(int line_width);
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void get_draw(_In_ HWND &hwnd)const = 0;
		virtual void info()const;
	};
	class Rectangle : public Shape
	{
		static const int MIN_SIDE = 30;
		static const int MAX_SIDE = 500;
		double side1;
		double side2;
	public:
		double get_length()const;
		double get_width()const;
		void set_length(double side1);
		void set_width(double side2);
		Rectangle(double side1, double side2, SHAPE_TAKE_PARAMETERSINT);
		~Rectangle();
		double get_area()const override;
		double get_perimeter()const override;
		void get_draw(_In_ HWND &hwnd)const override;
		void info()const override;
	};
	class Square : public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERSINT);
		~Square();
	};
	class Circle : public Shape
	{
		static const int MIN_RADIUS = 4;
		static const int MAX_RADIUS = 50;
		double radius;
	public:
		double get_radius()const;
		void set_radius(double radius);
		Circle(double radius, SHAPE_TAKE_PARAMETERSINT);
		~Circle();
		double get_area()const override;
		double get_perimeter()const override;
		void get_draw(_In_ HWND &hwnd)const override;
		void info()const override;
	};
	class Triangle : public Shape
	{
	protected:
		double side1;
		double side2;
		double side3;
		double angle;
		static const int point = 3;
		POINT pt[point];
	public:
		double get_side1()const;
		double get_side2()const;
		double get_side3()const;
		double get_angle()const;
		void set_side1(double side1);
		void set_side2(double side2);
		void set_side3(double side3);
		void set_angle(double angle);
		Triangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT);
		~Triangle();
		double get_area()const override;
		double get_perimeter()const override;
		void get_draw(_In_ HWND &hwnd)const override;
		void info()const override;
	};
	class AcuteTriangle : public Triangle
	{
	public:
		AcuteTriangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT);
		~AcuteTriangle();
	};
	class RightTriangle : public Triangle
	{
	public:
		RightTriangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT);
		~RightTriangle();
	};
	class ObtuseTriangle : public Triangle
	{
	public:
		ObtuseTriangle(double side1, double side2, double angle, SHAPE_TAKE_PARAMETERSINT);
		~ObtuseTriangle();
	};
}
