// From "C++ Operator Overloading: Program to perform Arithmetic sub of two Box dimensions," (ending comma)
// https://www.youtube.com/shorts/Vepr6B03YKk
#include <iostream>
using namespace std; 
class Box
{
	int length, width, height; 
	public:
		Box()
		{
			this->length = 0;
			this->width = 0;
			this->height = 0;
		}
		Box(int length, int width, int height)
		{
			this->length = length;
			this->width = width;
			this->height = height;
		}
		Box operator+(Box& obj)
		{
			Box b3;
			b3.length = length + obj.length;
			b3.width = width + obj.width;
			b3.height = height + obj.height;
			return b3;
		}
		void display()
		{
			cout << " Length = " << length << endl;
			cout << " Width = " << width << endl;
			cout << " Height = " << height << endl;
		};
};
int main()
{
	Box obj1(10, 20, 30);
	Box obj2(5, 6, 7);
	Box obj3;
	obj3 = obj1 + obj2;
	obj3.display();
	return 0;
}