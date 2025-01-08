// Younis Turk 1/7/2024
// felt myself slipping in my ability to quickly perform mental calculations, this is meant to be a practice tool to re-sharpen my skill
#include <iostream>
#include <random>

int generateDvisionProblem();

int main() {

    char choice = 'y'; // set choice char var to y for yes as default
    int wrongOrRight; // int var to hold return value of generateDvisionProblem();

    // while choice has not been set to n for no
    while (choice != 'n') {

        // set variable to return value of generateDvisionProblem();
        wrongOrRight = generateDvisionProblem();

        // if the answer was wrong
        if (wrongOrRight != 0) {
            // generate another one bc this guy needs more practice
            generateDvisionProblem();
        }

        // commented this out so that I don't have to worry about answering this 
        /*
        std::cout << "Go again? y or n\n";
        std::cin >> choice;
        */
    }

    return 0;
}

int generateDvisionProblem() {

    int min = 1; // min of random numbers 
    int max = 100; // max of random numbers
    double answer = 0; // will be set to the product of both

    // initialize a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

	// set two random numbers (double since this is division)
    double firstRandomDvisionValue = distrib(gen);
    double secondRandomDvisionValue = distrib(gen);

	while (firstRandomDvisionValue < secondRandomDvisionValue) {
		firstRandomDvisionValue = distrib(gen);
		secondRandomDvisionValue = distrib(gen);
	}

    // question for the product 
    std::cout << firstRandomDvisionValue << " / " << secondRandomDvisionValue << " = ?\n";
    std::cin >> answer;

    // if it's right say so
    if (answer == (firstRandomDvisionValue / secondRandomDvisionValue)) {
        // yippee !!!
        std::cout << "\nCorrect Answer\n\n";
    }

    // get it right 
    else {
        std::cout << "\nGo again\n";
        return -1;
    }

    return 0;
}