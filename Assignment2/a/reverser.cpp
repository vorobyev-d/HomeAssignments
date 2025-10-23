/* 
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 2a
*/



#include "reverser.h"
#include <iostream>
#include <fstream>
#include <filesystem>


void reverseFile()
{
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

    std::uint32_t size = std::filesystem::file_size(input_file);
    std::cout << "Size: " << size << " bytes" << std::endl;
    
    char* buffer = new char[size];

    std::ifstream input(input_file, std::ios::binary | std::ios::in);
    if (!input)
    {
        std::cerr << "Cant open input file, make sure it exists and has 'input.txt' name" << std::endl;
        delete[] buffer;
        return;
    }

    input.read(buffer, size);
    input.close();

    for (int i = 0; i < size / 2; i++)
    {
        std::swap(buffer[i], buffer[size - i - 1]);
    }
    
    std::ofstream output(output_file, std::ios::binary | std::ios::out);

    if (!output)
    {
        std::cerr << "Cant open output file, make sure it exists and has 'output.txt' name" << std::endl;
        delete[] buffer;
        return;
    }
    
    output.write(buffer, size);
    output.close();

    delete[] buffer;
    
    std::cout << "File has successfully written" << std::endl;
}
