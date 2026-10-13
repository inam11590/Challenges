#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers{3, 8, 4, 6};
    int target{10};

    for (std::size_t i{0}; i < numbers.size(); ++i)
    {
        for (std::size_t j{i + 1}; j < numbers.size(); ++j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                std::cout << "Indices: " << i << ", " << j << '\n';
                std::cout << "Values: " << numbers[i]
                          << " + " << numbers[j]
                          << " = " << target << '\n';

                return 0;
            }
        }
    }

    std::cout << "No pair found\n";

    return 0;
}