# Zookeeper's Challenge

## Introduction
The Zookeeper's Challenge is a program designed to manage animal data at a zoo. The program reads animal information from an input file, creates objects representing different animal species, and summarizes the total count of each species.

## 1. Project Overview
- **Objective**: Manage animal data at a zoo.
- **Functionality**: Reads animal data, creates objects, displays information, and outputs summaries.

## 2. Components
- **Animal Class**: Base class for all animals.
- **Derived Classes**: `Lion`, `Tiger`, `Hyena`, `Bear` – each class provides species-specific output.
- **Utility Function**: `split()` to parse input data.
- **Main Functionality**: Handles reading data and writing output.

## 3. Data Structures
- **Vector**: Stores pointers to `Animal` objects.
- **Map**: Counts the number of animals of each species.

## 4. File I/O
- **Input Handling**: Reads from `arrivingAnimals.txt`.
- **Output Handling**: Writes summaries to `newAnimals.txt`.

## 5. Interactions Between Components
- Initializes data structures, creates animals based on input, and outputs details and counts.

## 6. Error Handling
- Checks if the input file is successfully opened and can be expanded for data validation.

## Installation Instructions
To compile and run the program, use the following commands:
```bash
g++ -o zookeeper zookeeper.cpp
./zookeeper