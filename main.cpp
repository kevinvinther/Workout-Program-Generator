#include <iostream>
#include <string>
#include <fstream>

////////////////////////////
//     TODO: 
// 
// 
//
////////////////////////////

class Generator {
private:
	enum lifts { squat, bench, deadlift, ohp };
	double maxes[4] = { 0 };
	double tMax[4] = { 0 };
	void generateSets(const char name[], int week, int tMax);
	void generateCSVSets(const char name[], int week, int tMax, std::ofstream& File);
	int checkForWeekAndReturnSets(int week, int reps = 0);
	double checkForWeekAndReturnKG(int week, int set, int tMax);
public:
	void createCSVFile();
	explicit Generator();
	void getMaxes();
	const void generateProgramFromCurrentMaxes() { generateProgramFromCustomMaxes(tMax[squat], tMax[bench], tMax[deadlift], tMax[ohp]); };
	void generateProgramFromCustomMaxes(int squatTMax, int benchTMax, int deadlidtTMax, int ohpTMax);

};


int main() {
	bool running = true;
	int answer;
	Generator gen;

	while (running) {
		std::cout << "//////////////////////////" << std::endl;
		std::cout << "// 1. Generate program  //" << std::endl;
		std::cout << "// 2. Generate CSV file //" << std::endl;
		std::cout << "// 3. Exit              //" << std::endl;
		std::cout << "//////////////////////////" << std::endl;
		std::cin >> answer;
		switch (answer) {
		case 1:
			gen.getMaxes();
			gen.generateProgramFromCurrentMaxes();
			break;
		case 2:
			gen.createCSVFile();
			break;
		case 3:
			return 0;
			break;
		default:
			std::cout << "You need to choose an option!" << std::endl;
		}
	}
	return 0;
}

Generator::Generator()
{
	std::cout << "Welcome to 5/3/1 generator!" << std::endl;;
}

void Generator::getMaxes()
{
	std::cout << "First thing you need to do is enter your maxes:" << std::endl;
	std::cout << "Squat : ";
	std::cin >> maxes[squat];
	std::cout << "Bench : ";
	std::cin >> maxes[bench];
	std::cout << "Deadlift : ";
	std::cin >> maxes[deadlift];
	std::cout << "OHP : ";
	std::cin >> maxes[ohp];
	tMax[squat] = maxes[squat] * 0.9;
	tMax[bench] = maxes[bench] * 0.9;
	tMax[deadlift] = maxes[deadlift] * 0.9;
	tMax[ohp] = maxes[ohp] * 0.9;
}

void Generator::generateProgramFromCustomMaxes(int squatTMax, int benchTMax, int deadlidtTMax, int ohpTMax)
{
	generateSets("Squat", 1, tMax[squat]);
	generateSets("Bench", 1, tMax[bench]);
	generateSets("Deadlift", 1, tMax[deadlift]);
	generateSets("OHP", 1, tMax[ohp]);
	std::cout << "WEEK 2:\tWEEK 2:\tWEEK 2:\tWEEK 2:\tWEEK 2:\tWEEK 2:" << std::endl;
	generateSets("Squat", 2, tMax[squat]);
	generateSets("Bench", 2, tMax[bench]);
	generateSets("Deadlift", 2, tMax[deadlift]);
	generateSets("OHP", 2, tMax[ohp]);
	std::cout << "WEEK 3:\tWEEK 3:\tWEEK 3:\tWEEK 3:\tWEEK 3:\tWEEK 3:" << std::endl;
	generateSets("Squat", 3, tMax[squat]);
	generateSets("Bench", 3, tMax[bench]);
	generateSets("Deadlift", 3, tMax[deadlift]);
	generateSets("OHP", 3, tMax[ohp]);
	std::cout << "DELOAD:\tDELOAD:\tDELOAD:\tDELOAD:\tDELOAD:\tDELOAD:" << std::endl;
	generateSets("Squat", 4, tMax[squat]);
	generateSets("Bench", 4, tMax[bench]);
	generateSets("Deadlift", 4, tMax[deadlift]);
	generateSets("OHP", 4, tMax[ohp]);
}

void Generator::generateSets(const char name[], int week, int tMax)
{
	std::cout << "\t\tWeek" << week << std::endl;
	std::cout << "\t" << name << " : " << std::endl;
	if (week != 4) {
		std::cout << "\tWarmup: " << std::endl;
		std::cout << "\t    Set 1 : " << tMax * 0.4 << " x 5" << std::endl;
		std::cout << "\t    Set 2 : " << tMax * 0.5 << " x 5" << std::endl;
		std::cout << "\t    Set 3 : " << tMax * 0.6 << " x 3" << std::endl;
	}
	for (int i = 4; i < 7; i++) {
		std::cout << "\t    Set " << i << " : " << checkForWeekAndReturnKG(week, i - 3, tMax) << " x " << checkForWeekAndReturnSets(week, i - 3) << std::endl;
	}
}


int Generator::checkForWeekAndReturnSets(int week, int reps)
{
	switch (week) {
	case 1: 
		return 5;
	case 2: 
		return 3; 
	case 3: 
		switch (reps) {
		case 1: 
			return 5;
		case 2: 
			return 3;
		case 3: 
			return 1;
		}
	case 4: 
		return 5;
	default:
		break;
	}
	return -1;
}

double Generator::checkForWeekAndReturnKG(int week, int set, int tMax)
{
	switch (week) {
	case 1:
		switch (set) {
		case 1:
			return tMax * 0.65;
		case 2:
			return tMax * 0.75;
		case 3:
			return tMax * 0.85;
		default:
			break;
		}
		break;
	case 2:
		switch (set) {
		case 1:
			return tMax * 0.7;
		case 2:
			return tMax * 0.8;
		case 3:
			return tMax * 0.9;
		default:
			break;
		}
		break;
	case 3:
		switch (set) {
		case 1:
			return tMax * 0.75;
		case 2:
			return tMax * 0.85;
		case 3:
			return tMax * 0.95;
		default:
			break;
		}
		break;
	case 4:
		switch (set) {
		case 1:
			return tMax * 0.4;
		case 2:
			return tMax * 0.5;
		case 3:
			return tMax * 0.6;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0.0;
}

void Generator::generateCSVSets(const char name[], int week, int tMax, std::ofstream& File) {

	File << "Week" << week << std::endl;
	File << name << ": " << std::endl;
	if (week != 4) {
		File << "Set 1 :," << tMax * 0.4 << ", x 5" << std::endl;
		File << "Set 2 :," << tMax * 0.5 << ", x 5" << std::endl;
		File << "Set 3 :," << tMax * 0.6 << ", x 3" << std::endl;
	}
	for (int i = 4; i < 7; i++) {
		File << "Set " << i << " :," << checkForWeekAndReturnKG(week, i - 3, tMax) << ", x " << checkForWeekAndReturnSets(week, i - 3) << std::endl;
	}
}

void Generator::createCSVFile() {
	//Eror checking
	for (int i = 0; i < 4; i++) {
		if (maxes[i] == 0) {
			std::cerr << "Error! You have to have entered your maxes!" << std::endl;
			return;
		}
		if (tMax[i] == 0) {
			std::cerr << "Error! tMax's not initalized. Have you entered your maxes?" << std::endl;
			return;
		}
	}

	std::ofstream File("program.csv", std::ofstream::out); //Open program.csv
	if (File.fail()) { //Errorcheck 
		std::cout << "An error occured while opening program.csv" << std::endl;
		return;
	}
	//Generates the sets 
	generateCSVSets("Squat", 1, tMax[squat], File);
	generateCSVSets("Bench", 1, tMax[bench], File);
	generateCSVSets("Deadlift", 1, tMax[deadlift], File);
	generateCSVSets("OHP", 1, tMax[ohp], File);
	generateCSVSets("Squat", 2, tMax[squat], File);
	generateCSVSets("Bench", 2, tMax[bench], File);
	generateCSVSets("Deadlift", 2, tMax[deadlift], File);
	generateCSVSets("OHP", 2, tMax[ohp], File);
	generateCSVSets("Squat", 3, tMax[squat], File);
	generateCSVSets("Bench", 3, tMax[bench], File);
	generateCSVSets("Deadlift", 3, tMax[deadlift], File);
	generateCSVSets("OHP", 3, tMax[ohp], File);
	generateCSVSets("Squat", 4, tMax[squat], File);
	generateCSVSets("Bench", 4, tMax[bench], File);
	generateCSVSets("Deadlift", 4, tMax[deadlift], File);
	generateCSVSets("OHP", 4, tMax[ohp], File);
}