// Younis Turk 1/7/2024
// felt myself slipping in my ability to quickly perform mental calculations, this is meant to be a practice tool to re-sharpen my skill
#include <iostream>
#include <random>

int generateSubtractionProblem();

int main() {

    char choice = 'y'; // set choice char var to y for yes as default
    int wrongOrRight; // int var to hold return value of generateSubtractionProblem();

    // while choice has not been set to n for no
    while (choice != 'n') {

        // set variable to return value of generateSubtractionProblem();
        wrongOrRight = generateSubtractionProblem();

        // if the answer was wrong
        if (wrongOrRight != 0) {
            // generate another one bc this guy needs more practice
            generateSubtractionProblem();
        }

        // commented this out so that I don't have to worry about answering this 
        /*
        std::cout << "Go again? y or n\n";
        std::cin >> choice;
        */
    }

    return 0;
}

int generateSubtractionProblem() {

    int min = 1; // min of random numbers 
    int max = 100; // max of random numbers
    int answer = 0; // will be set to the product of both

    // initialize a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    // set two random numbers
    int firstRandomSubtractionValue = distrib(gen);
    int secondRandomSubtractionValue = distrib(gen);

	while (firstRandomSubtractionValue < secondRandomSubtractionValue) {
		firstRandomSubtractionValue = distrib(gen);
		secondRandomSubtractionValue = distrib(gen);
	}

    // question for the product 
    std::cout << firstRandomSubtractionValue << " - " << secondRandomSubtractionValue << " = ?\n";
    std::cin >> answer;

    // if it's right say so
    if (answer == (firstRandomSubtractionValue - secondRandomSubtractionValue)) {
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