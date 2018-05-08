#ifndef _531_H
#define _531_H

#include <iostream>
#include <fstream>

class Generator {
private:
  double maxes[4] = {0};
  void generateSets(const char name[], int week, int tMax);
  void generateCSVSets(const char name[], int week, int tMax,
                       std::ofstream &File);
  int checkForWeekAndReturnSets(int week, int reps = 0);
  double checkForWeekAndReturnKG(int week, int set, int tMax);

public:
  void createCSVFile();
  explicit Generator();
  void getMaxes();
  const void generateProgramFromCurrentMaxes() {
    generateProgramFromCustomMaxes(tMax[squat], tMax[bench], tMax[deadlift],
                                   tMax[ohp]);
  };
  void generateProgramFromCustomMaxes(int squatTMax, int benchTMax,
                                      int deadlidtTMax, int ohpTMax);
  void make1RM();

  int cycle = 1;
  double item[3];

  double tMax[3] = {0.00};

  enum lifts { squat, bench, deadlift, ohp };
};

#endif