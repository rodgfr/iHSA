#ifndef SOLUTION_H
#define SOLUTION_H

#define _USE_MATH_DEFINES
#include <climits>
#include <cmath>
#include <vector>
#include<stdlib.h>
#include<time.h>

#include "Benchmark.h"
#include "Problem.h"

class Solution
{
public:
	/**
 	 * Constructor with a problem.
 	 *
 	 * \param problem A Problem.
	 */
	Solution(const Problem& problem);

	/**
 	 * Copy constructor.
	 *
	 * \param solution A solution.
	 */
	Solution(const Solution& solution);

	/// Default destructor
	~Solution();

	/**
	 * Returns the values of the solution.
	 *
	 * \returns the values of the solution.
	 */
	std::vector<double> solution() const;

	/**
	 * Returns the fitness of the solution.
	 *
	 * \returns the fitness of the solution.
	 */
	double current_fitness() const;

	/**
	* Returns the real fitness of the solution.
	*
	* \returns the real fitness of the solution.
	*/
	double real_current_fitness() const;

	/**
	 * Returns the problem of the solution.
	 *
	 * \returns the problem of the solution.
	 */
	Problem problem() const;

	/**
	 * Overload of the copy operator.
	 *
	 * \params solution An other solution
	 *
	 * \returns the solution which sustains the copy.
	 */
	Solution& operator=  (const Solution& solution);

	/**
	 * Overload of the "equal to" operator.
	 *
	 * \params solution An other solution
	 *
	 * \returns true if the two solutions are the same. Else, returns false.
	 */
	bool operator== (const Solution& solution) const;

	/**
	 * Overload of the "different to" operator.
	 *
	 * \params solution An other solution
	 *
	 * \returns true if the two solutions are different. Else, returns false.
	 */
	bool operator!= (const Solution& solution) const;

    /**
     * Set a new value to the solution of the index specified
     * in parameters.
     *
     * \params value The new value to apply
     * \params index The index of the solution to change.
     */
    void set_value_to_index(double value, int index);

	/**
	 * Initialize the solution.
	 *
	 * It consist of generating each value of different dimensions with
	 * a mathematic function.
	 */
	void initialize();

    double return_fitness();

	/**
	 * Calculate the best fitness of the solution.
	 *
	 * Using the function contained in the choosen benchmark, this function
	 * calculates the result of each values in the solution, and finally uses
	 * a little mathematic function in order to keep unsigned integers.
	 */
	void calculate_fitness();
private:
	/// A vector containing the different values of the solution.
	std::vector<double> _solution;
	/// The best fitness of the given solution.
	double _current_fitness;
	///  The fitness used by algorithm
	double _real_current_fitness;
	/// The problem solved by the solution.
	const Problem& _problem;
};

#endif
