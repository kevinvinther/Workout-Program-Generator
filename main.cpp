#include "531.h"
#include <fstream>
#include <iostream>

int main() {
    bool running = true; //For the program loop

    Generator gen; //Creates an instance of the generator class for 531

    std::ifstream readMaxes;
    readMaxes.open("Maxes.txt");

    if (readMaxes.fail()) {
        std::cout << "Error occured while trying to read maxes." << std::endl;
    }

    if (!readMaxes.eof()) {
        readMaxes >> gen.item[0];
        gen.tMax[gen.squat] = gen.item[0];
        readMaxes >> gen.item[1];
        gen.tMax[gen.bench] = gen.item[1];
        readMaxes >> gen.item[2];
        gen.tMax[gen.deadlift] = gen.item[2];
        readMaxes >> gen.item[3];
        gen.tMax[gen.ohp] = gen.item[3];
    }
    readMaxes.close();

    while (running) {
        std::cout << "//////////////////////////" << std::endl;
        // std::cout << "// Cycle (WIP): " << gen.cycle << "       //" << std::endl;
        std::cout << "// 1. Generate program  //" << std::endl;
        std::cout << "// 2. Update maxes      //" << std::endl;
        std::cout << "// 3. Generate CSV file //" << std::endl;
        //std::cout << "// 4. Change cycle      //" << std::endl;
        std::cout << "// 4. Calculate 1RM     //" << std::endl;
        std::cout << "// 5. Exit              //" << std::endl;
        std::cout << "//////////////////////////" << std::endl;
        std::cout << "Training Maxes: " << std::endl;
        std::cout << "Squat:" << gen.tMax[gen.squat] << std::endl;
        std::cout << "Bench:" << gen.tMax[gen.bench] << std::endl;
        std::cout << "Deadlift:" << gen.tMax[gen.deadlift] << std::endl;
        std::cout << "OHP:" << gen.tMax[gen.ohp] << std::endl;

        int answer;
        std::cin >> answer;
        switch (answer) {
        case 1:
            gen.generateProgramFromCurrentMaxes();
            break;
        case 2:
            gen.getMaxes();
            break;
        case 3:
            gen.createCSVFile();
            break;
        //case 4:
          //  std::cout << "Cycle (WIP): ";
            //std::cin >> gen.cycle;
            //break;
        case 4:
            gen.make1RM();
            break;
        case 5:
            return 0;
            break;
        default:
            std::cout << "You need to choose an option!" << std::endl;
        }
    }
    return 0;
}
