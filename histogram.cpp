#include "histogram.h"

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
