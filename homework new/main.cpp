//
//  main.cpp
//  homework new
//
//  Created by Valeria  Bukova on 27.09.2024.
//

#include <iostream>
using namespace std;

// Класс CPU
class CPU
{
private:
    char* model;
    int frequency;

public:
    CPU(const char* model, int frequency) : frequency(frequency)
    {
        int length = 0;
        while (model[length] != '\0') length++;

        this->model = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            this->model[i] = model[i];
        }
    }

    ~CPU()
    {
        delete[] model;
    }

    CPU(const CPU& other) : frequency(other.frequency)
    {
        int length = 0;
        while (other.model[length] != '\0') length++;

        model = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            model[i] = other.model[i];
        }
    }
};

// Класс RAM
class RAM
{
private:
    int* memorySize;

public:
    RAM(int size)
    {
        memorySize = new int(size);
    }

    ~RAM()
    {
        delete memorySize;
    }

    // Конструктор копіювання
    RAM(const RAM& other)
    {
        memorySize = new int(*other.memorySize);
    }
};

// Класс SSD
class SSD
{
private:
    int* capacity;

public:
    SSD(int size)
    {
        capacity = new int(size);
    }
    
    ~SSD()
    {
        delete capacity;
    }

    // Конструктор копіювання
    SSD(const SSD& other)
    {
        capacity = new int(*other.capacity);
    }
};

// Класс GPU
class GPU
{
private:
    char* model;
    int memorySize;

public:
    GPU(const char* model, int memorySize) : memorySize(memorySize) {
        int length = 0;
        while (model[length] != '\0') length++;

        this->model = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            this->model[i] = model[i];
        }
    }

    ~GPU()
    {
        delete[] model;
    }

    // Конструктор копіювання
    GPU(const GPU& other) : memorySize(other.memorySize)
    {
        int length = 0;
        while (other.model[length] != '\0') length++;

        model = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            model[i] = other.model[i];
        }
    }
};

// Класс Laptop
class Laptop
{
private:
    CPU cpu;
    RAM ram;
    SSD ssd;
    GPU gpu;
    char* name;
    int price;
    static int countLaptops;

public:
    Laptop(const char* name, int price, const CPU& cpu, const RAM& ram, const SSD& ssd, const GPU& gpu)
        : cpu(cpu), ram(ram), ssd(ssd), gpu(gpu), price(price)
    {
        int length = 0;
        while (name[length] != '\0') length++;

        this->name = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            this->name[i] = name[i];
        }
        countLaptops++;
    }

    ~Laptop() {
        delete[] name;
    }

    // Конструктор копіювання
    Laptop(const Laptop& other)
        : cpu(other.cpu), ram(other.ram), ssd(other.ssd), gpu(other.gpu), price(other.price)
    {
        int length = 0;
        while (other.name[length] != '\0') length++;

        name = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            name[i] = other.name[i];
        }
        countLaptops++;
    }

    static int getCount()
    {
        return countLaptops;
    }
};

int Laptop::countLaptops = 0;

int main()
{
    CPU cpu1("Intel i7", 3200);
    RAM ram1(16);
    SSD ssd1(512);
    GPU gpu1("NVIDIA GTX", 6);

    Laptop laptop1("MyLaptop", 1000, cpu1, ram1, ssd1, gpu1);

    Laptop laptop2 = laptop1;

   cout << "Number of laptops: " << Laptop::getCount() << endl;
    return 0;
}
