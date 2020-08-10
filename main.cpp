//
// Created by themastermind on 7/30/20.
//

#include "config.cpp"
#include "problem.cpp"
#include "solver.cpp"
#include "checker.cpp"

int main(int argc, char *argv[]) {
	Config::load_config_from_file();
//	Config::print_config();

	Problem::initialize();
//	Problem::print_sequences();

	Solver::solve();

	return 0;
}