#include <iostream>

class Line {
public:
    Line(){}

    float k;
    float b;

    Line(float k, float b) : k(k), b(b)
    {}

    float getY(float x){
        return k * x + b;
    }
    float getX(float y) {
        return (y - b) / k;
     }
       
};

int UpOrDown(float x, float y, Line line) {

    if (line.getY(x)<y) {
        return 1;
    }
    else if (line.getY(x) > y) {
        return -1;
    }
    return 0;
}

int IsInsideTriangle(float x, float y, Line line, Line line1, Line line2) {
    int Oleg, Moisey1, Alina2;
    Oleg = UpOrDown(x, y, line);
    Moisey1 = UpOrDown(x, y, line1);
    Alina2 = UpOrDown(x, y, line2);

    if (Oleg >=1 and Moisey1 >= 1 and Alina2 >= 1) {
        return -1;
    }
    else if (Oleg <= -1 and Moisey1 <= -1 and Alina2 <= -1) {
        return -1;
    }
    else if (Oleg == 0 || Moisey1 == 0 || Alina2 == 0) {
        return 0;
    }
    else if (Oleg + Moisey1 + Alina2 == -1 || Oleg + Moisey1 + Alina2 == 1) {
        return 1;
    }

}

int main()
{
    Line line = Line(1, 0);
    Line line1 = Line(-1, 0);
    Line line2 = Line(0, 1);

    std::cout << IsInsideTriangle(0, 1 / 2, line, line1, line2) << std::endl;
    std::cout << IsInsideTriangle(1,  2, line, line1, line2) << std::endl;
    std::cout << IsInsideTriangle(-1, 1 / 2, line, line1, line2) << std::endl;
    std::cout << IsInsideTriangle(0, 0, line, line1, line2) << std::endl;
    
   /* return 0;*/

    /*std::cout << "Hello World!\n";*/
}

