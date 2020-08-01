#include <iostream>
#include <cmath>
using namespace std;

namespace test1
{
    class point
    {
    public:
        point(double x, double y) : x_(x), y_(y)
        {
            cout << "init point at " << x << " " << y << endl;
        }
        friend double dist(point& a, point& b); // friend不是成员 不受private public等关键字的影响
    private:
        double x_;
        double y_;
    };
    // friend
    double dist(point& a, point& b){
        return sqrt((a.x_-b.x_)*(a.x_-b.x_) + (a.y_-b.y_)*(a.y_-b.y_));
    }

} // namespace test1

int main()
{
    test1::point a(1,0);
    test1::point b(0,1);
    cout<<test1::dist(a,b);

    return 0;
}