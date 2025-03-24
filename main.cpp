#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>

class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    Animal(std::string n, int a, std::string s) : name(n), age(a), species(s) {}

    virtual void display() const {
        std::cout << name << " (" << age << " years old) - " << species << std::endl;
    }

    std::string getSpecies() const {
        return species;
    }

    int getAge() const {
        return age;
    }

    std::string getName() const {
        return name;
    }
};

class Lion : public Animal {
public:
    Lion(std::string n, int a) : Animal(n, a, "Lion") {}
    void display() const override {
        std::cout << "Lion: " << name << " (" << age << " years old)" << std::endl;
    }
};

class Tiger : public Animal {
public:
    Tiger(std::string n, int a) : Animal(n, a, "Tiger") {}
    void display() const override {
        std::cout << "Tiger: " << name << " (" << age << " years old)" << std::endl;
    }
};

class Hyena : public Animal {
public:
    Hyena(std::string n, int a) : Animal(n, a, "Hyena") {}
    void display() const override {
        std::cout << "Hyena: " << name << " (" << age << " years old)" << std::endl;
    }
};

class Bear : public Animal {
public:
    Bear(std::string n, int a) : Animal(n, a, "Bear") {}
    void display() const override {
        std::cout << "Bear: " << name << " (" << age << " years old)" << std::endl;
    }
};

std::vector<std::string> split(const std::string &input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

int main() {
    std::vector<std::unique_ptr<Animal>> zoo;
    std::map<std::string, int> speciesCount;

    std::ifstream inFile("arrivingAnimals.txt");
    if (!inFile) {  
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> result = split(line, ' ');

        std::string name = result[0];
        int age = std::stoi(result[1]);
        std::string species = result[2];

        std::unique_ptr<Animal> animal = nullptr;
        if (species == "Lion") {
            animal = std::make_unique<Lion>(name, age);
        } else if (species == "Tiger") {
            animal = std::make_unique<Tiger>(name, age);
        } else if (species == "Hyena") {
            animal = std::make_unique<Hyena>(name, age);
        } else if (species == "Bear") {
            animal = std::make_unique<Bear>(name, age);
        }

        if (animal != nullptr) {
            zoo.push_back(std::move(animal));
            speciesCount[species]++;
        }
    }

    inFile.close();

    std::ofstream outFile("newAnimals.txt");
    outFile << "Animal Report:" << std::endl;

    for (const auto& animal : zoo) {
        animal->display();
    }

    outFile << "\nSpecies Total Count:" << std::endl;
    for (const auto& entry : speciesCount) {
        outFile << entry.first << ": " << entry.second << std::endl;
    }

    outFile.close();

    return 0;
}
