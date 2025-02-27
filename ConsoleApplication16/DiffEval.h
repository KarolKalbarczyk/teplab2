
#include "MscnProblem.h"

const int POPULATION_SIZE = 12;
const double CROSS_PROBABILITY = 0.08;
const double WEIGHT_DIFF = 0.8;
const int FITNESS_COUNT_TO_STOP = 50000;

class Individual {
public:
	Individual(double *genes, int size) { this->genes = genes; this->size = size;checked = false; };
	bool isDifferent(Individual* other);
	bool setAt(int index, double value) { genes[index] = value; };
	double getAt(int index) { return genes[index]; };
	~Individual() { delete[] genes; };
	double calcFitness(Problem* problem);
	int getSize() { return size; };
	void printSolution();
	double getFitness() { return fitness; };
private:
	double fitness;
	double* genes;
	int size;
	bool checked;
};

class DiffEval {
public:
	Individual* solve(Problem* problem,int seed);
private:
	Individual* currentBest;
	double currentBestFitness;
	Problem* problem;
	Random rand;
	Individual** population;
	Individual* generateIndividual();
	std::pair<double, double>* constraints;
	bool isStopConditionMet();
	void placeBetter(int index, Individual* newInd);
	bool areDifferent(Individual* ind, Individual* base, Individual* indAdd1, Individual* indAdd2);
	void generatePopulation();
	bool isBetter(Individual* old, Individual* newInd);
	Individual * chooseBest();
	Individual* cross(Individual* ind, Individual* base, Individual* indNew1, Individual* indNew2);
};
