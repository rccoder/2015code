#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_NUM_OF_FIGURES = 100;
enum FigureShape {LINE, RECTANGLE, CIRCLE};
struct Line
{
    FigureShape place_hoder;
    double x1, x2, y1, y2;
};
struct Rectangle
{
    FigureShape place_hoder;
    double left, right, top, bottom;
};
struct Circle
{
    FigureShape place_hoder;
    double x, y, r;
};
union Figure
{
    FigureShape shape;
    Line line;
    Rectangle rectangle;
    Circle circle;
};
Figure figures[MAX_NUM_OF_FIGURES];
extern void drawLine(Line line);
extern void drawRectangle(Rectangle rectangle);
extern void drawCircle(Circle circle);
int main()
{
    int count;
    for(count = 0; count < MAX_NUM_OF_FIGURES; count++)
    {
        int shape;
        do
        {
            cout << "Please input the number:(1.Line 2.Rectangle 3.Circle 0.End)";
            cin >> shape;
        }while(shape < 0 || shape > 3);
        switch(shape)
        {
            case 1:
                figures[count].shape = LINE;
                cout << "Please input the (x1, y1, x2, y2)";
                cin >> figures[count].line.x1 >> figures[count].line.y1 >> figures[count].line.x2 >> figures[count].line.y2;
                break;
            case 2:
                figures[count].shape = RECTANGLE;
                cout << "Please input the(left, right, top, bottom) ";
                cin >> figures[count].rectangle.left >> figures[count].rectangle.right >> figures[count].rectangle.top >> figures[count].rectangle.bottom;
                break;
            case 3:
                figures[count].shape = CIRCLE;
                cout << "Please input the (x, y, r)";
                cin >> figures[count].circle.x >> figures[count].circle.y >> figures[count].circle.r;
                break;
            case -1:
                break;
        }
    }
    for(int i = 0; i < count; i++)
    {
        switch(figures[i].shape)
        {
            case LINE:
                drawLine(figures[i].line);
                break;
            case RECTANGLE:
                drawRectangle(figures[i].rectangle);
                break;
            case CIRCLE:
                drawCircle(figures[i].circle);
                break;
        }
    }
    return 0;
}
