#include <iostream>
#include <vector>

const int N = 8;
std::vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39};

int binarysearch(int key)
{
    int left = 0;
    int right = N-1;

    while(right >= left)
    {
        int halfpos = left + (right - left)/2;
        if(a[halfpos] == key) return halfpos;
        else if(key > a[halfpos]) left = halfpos + 1;
        else if(key < a[halfpos]) right = halfpos - 1;
    }
    return -1;
}

int main()
{
    std::cout << binarysearch(10) << std::endl;
    std::cout << binarysearch(39) << std::endl;
    std::cout << binarysearch(8) << std::endl;
    std::cout << binarysearch(5) << std::endl;
    std::cout << binarysearch(110) << std::endl;
}