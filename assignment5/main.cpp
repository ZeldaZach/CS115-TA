#include "/Users/zahalpern/Desktop/assignment5_student/Vector3D.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void ReadVectorData(std::string inFile, Vector3D*& vec1, Vector3D*& vec2, float &scalar)
{
    if (vec1 == nullptr)
    {
        vec1 = new Vector3D;
    }
    if (vec2 == nullptr)
    {
        vec2 = new Vector3D;
    }
    int count(0);
    std::ifstream in(inFile);
    if (in.is_open())
    {
        while (!in.eof() || in.peek() != EOF)
        {
            in >> std::ws;
            if (in.eof() || in.peek() == EOF)
            {
                break;
            }
            if (count == 0)
            {
                in >> *vec1;
            }
            else if (count == 1)
            {
                in >> *vec2;
            }
            else
            {
                in >> scalar;
            }
            ++count;
        }
    }
    else
    {
        std::cout << "Failed to open " << inFile << std::endl;
    }
    in.close();
}
int main()
{
    Vector3D* vec1(nullptr);
    Vector3D* vec2(nullptr);
    float scalar(0.f);
    std::string inFile("/Users/zahalpern/Desktop/assignment5/VectorData.txt");

    //read data from text file
    ReadVectorData(inFile, vec1, vec2, scalar);

    //vectors are dynamic arrays that resize as needed
    std::vector<Vector3D*>NewVectorData;
    if (vec1 != nullptr && vec2 != nullptr)
    {
        //create 4 new Vector3D pointer objects by using math operators on dereferenced objects
        NewVectorData.push_back(*vec1 + *vec2);
        NewVectorData.push_back(*vec1 - *vec2);
        NewVectorData.push_back(*vec1 * scalar);
        NewVectorData.push_back(*vec1 / scalar);
        
        std::cout << "Index 0 Before Addition: " << *NewVectorData.at(0) << std::endl;
        //add index 1 to 0
        *NewVectorData.at(0) += *NewVectorData.at(1);
        std::cout << "Index 0 After Addition: " << *NewVectorData.at(0) << std::endl << std::endl;

        //subtract index 2 from 1
        std::cout << "Index 1 Before Subtraction: " << *NewVectorData.at(1) << std::endl;
        *NewVectorData.at(1) -= *NewVectorData.at(2);
        std::cout << "Index 1 After Subtraction: " << *NewVectorData.at(1) << std::endl << std::endl;

        //divide index 2 by a scalar
        std::cout << "Index 2 Before Multiplication: " << *NewVectorData.at(2) << std::endl;
        *NewVectorData.at(2) /= scalar;
        std::cout << "Index 2 After Multiplication: " << *NewVectorData.at(2) << std::endl << std::endl;

        //set index 3 equal to index 2
        std::cout << "Index 3 Before Setting Equal To Index 2: " << *NewVectorData.at(3) << std::endl;
        *NewVectorData.at(3) = *NewVectorData.at(2);
        std::cout << "Index 3 After Setting Equal To Index 2: " << *NewVectorData.at(3) << std::endl << std::endl;

        if (*NewVectorData.at(3) == *NewVectorData.at(2))
        {
            std::cout << "Successfully set index 3 equal to index 2." << std::endl;
        }
        if (*NewVectorData.at(0) != *NewVectorData.at(3))
        {
            std::cout << "Index 1 does not equal index 3." << std::endl << std::endl;;
        }

        for (auto& vec : NewVectorData)
        {
            std::cout << "Vector Before Normalization: " << *vec << std::endl;
            std::cout << "Magnitude Before Normalization: " << vec->Magnitude() << std::endl;
            vec->Normalize();
            std::cout << "Magnitude After Normalization: " << vec->Magnitude() << std::endl;
            std::cout << "Vector After Normalization: " << *vec << std::endl;
            -*vec;
            std::cout << "Vector after negating: " << *vec << std::endl << std::endl;
        }

    }
    //cleanup allocated memory if it is valid
    if (vec1 != nullptr)
    {
        delete vec1;
    }
    if (vec2 != nullptr)
    {
        delete vec2;
    }
    for (auto& vec : NewVectorData)
    {
        if (vec != nullptr)
        {
            delete vec;
        }
    }
    return 0;
}