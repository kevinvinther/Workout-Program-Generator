#include "531.h"
#include <fstream>
#include <iostream>

//
// ──────────────────────────────────────────────── I ──────────
//   :::::: T O D O : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────
// There are still quite a lot of bugs, compared to how small and
// horrible this program is. 
// The known bugs are:
//  Program stops outputting suddenly           DONE? ()
//  Program won't generate from start maxes.    DONE? ()
//
//
// ──────────────────────────────────────────────────────── II ──────────
//   :::::: F E A T U R E S : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────
// A few features still need to be added.  These features include: 
//  * More Programs (nsuns e.g.)
//  * Cycles (for 531)
//  * Hopefully more 

int main() {
    bool running = true; // For the program loop

    Generator gen; // Creates an instance of the generator class for 531

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
        std::cout << "Training Maxes: " << std::endl
                  << "Squat:" << gen.tMax[gen.squat] << std::endl
                  << "Bench:" << gen.tMax[gen.bench] << std::endl
                  << "Deadlift:" << gen.tMax[gen.deadlift] << std::endl
                  << "OHP:" << gen.tMax[gen.ohp] << std::endl
                  << "//////////////////////////" << std::endl
                  << "// 1. Generate program  //" << std::endl
                  << "// 2. Update maxes      //" << std::endl
                  << "// 3. Generate CSV file //" << std::endl
                  << "// 4. Calculate 1RM     //" << std::endl
                  << "// 5. Exit              //" << std::endl
                  << "//////////////////////////" << std::endl;

        int answer;
        std::cin >> answer;
        switch (answer) {
        case 1:
            gen.generateProgramFromCurrentMaxes();
            break;
        case 2:
            gen.getMaxes(); // Update maxes
            break;
        case 3:
            gen.createCSVFile(); // Generates content of CSV file also.
            break;
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
