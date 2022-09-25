#include <cmath> 
#include <iostream> 
#include <exception> 

using namespace std;

double calculate_integral(const double step) {
    // init x range from 1 to 2 
    double x_limit = 2;
    size_t num = static_cast<size_t>(1 / step);
    // define function value calculation
    auto y_value = [](const double x_value) -> double 
    {

        const double inv_square_x = (double)1 / (x_value * x_value);
        const double inv_square_x_plus = (double)1 / ((x_value + 1) * (x_value + 1));
        
        return sqrt(1 + inv_square_x + inv_square_x_plus);
    };
    cout << "number of x elements " << num << endl;


    double result = 0;
    try {
        for (size_t c = 0; c < num; c++) {
            result += y_value(x_limit);
            x_limit += step;
        }
    }
    catch (exception& ex) {
        cerr << "calculate y failed at " << x_limit << ", exception: " << ex.what() << endl;
    }
    result *= step;
    return result;
}

int main() {
    cout << "Start!" << endl;
    double step = 1e-07f;
    double ret = calculate_integral(step);
    cout << "result of the integral calculated with x-distance of " << step << " is : "
        << ret << endl;
    return 0;
}