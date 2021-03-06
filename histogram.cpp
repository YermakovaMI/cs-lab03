#include "histogram.h"
#include <iostream>

void find_minmax (vector<double> numbers, double& min, double& max)
{
    size_t length = numbers.size();
    if (length!=0)
    {
       min = numbers[0];
       max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }

    }






}
void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height <<"' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

    void svg_text (double left, double baseline, string text) {
        cout <<"<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
    }

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
cout <<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

void show_histogram_svg(const vector<size_t>& bins)
    {
        const auto IMAGE_WIDTH = 400;
        const auto IMAGE_HEIGHT = 300;
        const auto TEXT_LEFT = 10;
        const auto TEXT_BASELINE = 20;
        const auto TEXT_WIDTH = 50;
        const auto BIN_HEIGHT = 30;

         const size_t MAX_ASTERISK = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    max_count*=10;
    const bool scaling_needed = max_count > MAX_ASTERISK;

    double scaling_factor=1;
        if (scaling_needed)
        {
            scaling_factor = (double)MAX_ASTERISK / max_count;
        }
    max_count*=scaling_factor;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins) {
    const double bin_width = 10 * bin * scaling_factor;
    svg_rect(max_count+TEXT_LEFT-bin_width, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
    svg_text(max_count+2*TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));

    top += BIN_HEIGHT;
}
    svg_end();
}
