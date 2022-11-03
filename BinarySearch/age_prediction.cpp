#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::cout << "Start Game" << std::endl;
    int right = 36;
    int left = 20;

    while(right - left > 1)
    {
        int mid = left + (right - left) / 2;
        std::cout << "Are you greater than equal to " << mid << " years old? (yes/no) " << std::endl;
        std::string ans;
        std::cin >> ans; 
        if(ans == "yes") left = mid;
        else right = mid;
    }

    std::cout << "Your age is " << left << " years old!" << std::endl;
}