//
// Created by themastermind on 7/30/20.
//

#include "config.cpp"
#include "problem.cpp"

int main() {
	Config::load_config_from_file();
	Config::print_config();

	Problem::initialize(Config::input);
	Problem::print_sequences();

}