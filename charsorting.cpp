// g++ -o charsorting charsorting.cpp && ./charsorting
#include <iostream>
#include <vector>
#include <array>

// Задача: Отсортировать массив char за O(2n). Так понимаю, имелось ввиду отсортировать за два прохода
// Решение: Классическая сортировка подсчётами
// Note: O(2n) == O(N) in terms of big O notation

typedef unsigned char CharType; // "unsigned" because of compability with several compilers
typedef uint8_t CountType; // There is no more 256 cases of every letter are allowed
const CharType src[] = {'z' ,'g', 'm', 'b', 'a', 'c', '1', 'f', 'g'}; // The source. Please feel free to add any values

int main()
{
    std::vector<CharType> vec(src, src + sizeof(src) / sizeof(CharType));
    std::array<CountType, 256 * sizeof(CharType)> countsArray; // There are 256 letter cases in every byte
    countsArray.fill(0);

    for( size_t i = 0; i < vec.size(); ++i )
    {
        const CharType currChar(vec.at(i));
        std::cout << currChar << ", ";
        const size_t index = static_cast<size_t>(currChar);
        ++countsArray[index];
    }

    std::cout << std::endl;
    int sourceArrayCurrentIndex = 0;

    for( size_t i = 0; i < countsArray.size(); ++i )
    {
        CountType aLetterCounter(countsArray.at( i ));
        const CharType currChar(static_cast<CharType>( i ));

        while( aLetterCounter != 0 ) // It does not make O(n2)! Ok?
        {
            --aLetterCounter;
            vec[sourceArrayCurrentIndex] = currChar; // It is possible calculate the index from i and aLetterCounter. But it will do some overload
            ++sourceArrayCurrentIndex;
        }
    }

    // Now "vec" has a sorted char set!

    // Result output
    for( size_t i = 0; i < vec.size(); ++i )
    {
        std::cout << vec[i] << ", ";
    }

    std::cout << std::endl;

    return 0;
}
