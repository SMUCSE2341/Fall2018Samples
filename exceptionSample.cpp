#include <iostream>
#include <exception>

using namespace std;

class ExceptionTestClass {
private:
    //x is a variable that cannot take on a value less than 0.
    int x;
public:
    ExceptionTestClass(int val = 10):x(val){}

    int getX()
    {
        return x;
    }

    void setX(int newVal)
    {
        //What do we do here if newVal is < 0?
        if (newVal < 0)
            throw std::logic_error("newVal is less than zero");
        x = newVal;
    }
};

int main()
{

    ExceptionTestClass myObj;

    try {
        cout << myObj.getX() << endl;
        myObj.setX(15);
        cout << myObj.getX() << endl;
        myObj.setX(0);
        cout << myObj.getX() << endl;
        myObj.setX(-1);
        cout << myObj.getX() << endl;
    } catch (std::exception& e) {
        cout << "There was an exceptional condition!!" << endl;
        cout << e.what() << endl;
    }


//    for (int i = 0; i < argc; i++)
//        cout << "argv[" << i << "]= " << argv[i] << endl;

    return 0;
}
