#include <iostream>

////////////////////////////
//     TODO: 
// 1. Make ReturnKG and CheckAndReturn% one function
//
//
////////////////////////////

class Generator {
private:
	const enum lifts {squat, bench, deadlift, ohp};
	double maxes[4]; 
	double tMax[4]; 
	void generateSets(const char name[], int week, int tMax);
	int checkForWeekAndReturnSets(int week, int reps = 0);
	double checkForWeekAndReturnPercentage(int week, int set);
	double returnKGAfterPercentageIsApplied(int tMax, int week, int set);
public:
	explicit Generator();
	void getMaxes(); 
	const void generateProgramFromCurrentMaxes() { generateProgramFromCustomMaxes(tMax[squat], tMax[bench], tMax[deadlift], tMax[ohp]); };
	void generateProgramFromCustomMaxes(int squatTMax, int benchTMax, int deadlidtTMax, int ohpTMax);
	
};

int main() {
	Generator g;
	system("pause");
	return 0;
}

Generator::Generator()
{
	std::cout << "Welcome to 5/3/1 generator!" << std::endl;
	getMaxes();
	generateProgramFromCurrentMaxes();
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
	std::cout << name << " : " << std::endl;
	if (week != 4) {
		std::cout << "Warmup: " << std::endl;
		std::cout << "Set 1 : " << tMax * 0.4 << " x 5" << std::endl;
		std::cout << "Set 2 : " << tMax * 0.5 << " x 5" << std::endl;
		std::cout << "Set 3 : " << tMax * 0.6 << " x 3" << std::endl;
	}
	for (int i = 4; i < 7; i++) {
		std::cout << "Set " << i << " : "<< returnKGAfterPercentageIsApplied(tMax, week, i - 3) << " x " << checkForWeekAndReturnSets(week, i - 3) << std::endl;
	}
	std::cout << "Next? (Press enter)" << std::endl;
	std::cin.get();
}

int Generator::checkForWeekAndReturnSets(int week, int reps)
{
	if (week = 1) {
		return 5; 
	}
	else if (week = 2) {
		return 3; 
	}
	else if (week = 3) {
		if (reps = 1) {
			return 5;
		}
		else if (reps = 2) {
			return 3; 
		}
		else if (reps = 3) {
			return 1; 
		}
	}
	else if (week = 4) {
		return 5; 
	}
	return -1;
}

double Generator::checkForWeekAndReturnPercentage(int week, int set)
{
	switch (week) {
	case 1: 
		switch (set) {
		case 1: 
			return 0.65;
		case 2: 
			return 0.75;
		case 3:
			return 0.85;
		default:
			break;
		}
		break;
	case 2: 
		switch (set) {
		case 1:
			return 0.7;
		case 2:
			return 0.8;
		case 3:
			return 0.9;
		default:
			break;
		}
		break; 
	case 3: 
		switch (set) {
		case 1:
			return 0.75;
		case 2:
			return 0.85;
		case 3:
			return 0.95;
		default:
			break;
		}
		break;
	case 4:
		switch (set) {
		case 1:
			return 0.4;
		case 2:
			return 0.5;
		case 3:
			return 0.6;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0.0;
}

double Generator::returnKGAfterPercentageIsApplied(int tMax, int week, int set)
{
	return tMax * checkForWeekAndReturnPercentage(week, set); 
}

