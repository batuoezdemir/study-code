#include <iostream>
#include <vector>
#include <algorithm>

#include "drone_test_bench.hpp"

int main()
{
    const int COUNT_VALUE = 8;
    // Section I
    std::cout << '\n'
              << "-------------Section I-------------" << '\n';
    const int SIZE = 5;
    char testFrame[SIZE] = {'1', '2', '3', '4', '5'};

    if (SIZE <= 0)
    {
        std::cout << "Error: SIZE is zero or negative." << std::endl;
        return 1;
    }
    printFrame(testFrame);
    std::cout << min(testFrame) << std::endl;
    composeTags("Channel", "motor_temp", "Priority", 4);

    // Section II
    // Task 6
    std::cout << '\n'
              << "-------------Task 6-------------" << '\n';

    std::vector<int> recordedData = {42, 17, 42, 5, 99, 17, 63, 12};

    printVector(recordedData);

    std::sort(recordedData.begin(), recordedData.end());

    printVector(recordedData);

    std::vector<int>::iterator searchedValue;
    searchedValue = std::find(recordedData.begin(), recordedData.end(), 63);

    if (searchedValue == recordedData.end())
    {
        std::cout << "No value found" << std::endl;
    }
    else
    {
        std::cout << "Value exists" << std::endl;
    }

    // Task 7
    std::cout << '\n'
              << "-------------Task 7-------------" << '\n';

    std::vector<int> recordedData2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    printVector(recordedData2);

    std::replace(recordedData2.begin(), recordedData2.end(), -1, 0);
    printVector(recordedData2);

    int valueCount = std::count(recordedData2.begin(), recordedData2.end(), COUNT_VALUE);
    std::cout << "The value " << COUNT_VALUE << " occurs " << valueCount << " times.\n";

    std::reverse(recordedData2.begin(), recordedData2.end());
    printVector(recordedData2);

    return 0;
}