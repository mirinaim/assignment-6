/*

Mirina Im
CMSC 312
12/7/24
Assignment 6

*/

#ifndef COLOR
#define COLOR

class Color {
    private:
    double r;
    double g;
    double b;

    public:
    Color(){
        r = 0.0;
        g = 0.0;
        b = 0.0;
    }
    Color(double r1, double g1, double b1){
        r = r1;
        g = g1;
        b = b1;
    }

    double get_R(){
        return r;
    }
    double get_G(){
        return g;
    }
    double get_B(){
        return b;
    }

    Color operator+(Color const& color){
        return Color(r + color.r, g + color.g, b + color.b);
    }
    Color add(Color const& color){
        return Color(r + color.r, g + color.g, b + color.b);
    }
    Color operator+(double value){
        return Color(r + value, g + value, b + value);
    }
    Color add_scalar(double value){
        return Color(r + value, g + value, b + value);
    }
    Color operator*(double value){
        return Color(r * value, g * value, b * value);
    }
    Color mult_scalar(double value){
        return Color(r * value, g * value, b * value);
    }

    void cap();
};

#endif