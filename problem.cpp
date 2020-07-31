//
// Created by themastermind on 7/31/20.
//

#ifndef LDDMS3_PROBLEM
#define LDDMS3_PROBLEM

#include "template.cpp"
#include "config.cpp"

namespace Problem {
	int n;		// number of sequences
	int l;		// length of motif
	int d1;		// first upper_bound of hamming distance
	int d2;		// second upper_bound of hamming distance

	vector<string> sequences;

	void initialize(const string& input_file_name) {
		ifstream input_file(input_file_name);
		while (input_file.good()) {
			string seq_name;
			getline(input_file, seq_name);

			string sequence;
			getline(input_file, sequence);
			sequences.push_back(sequence);

		}

		while (sequences.back().empty()) sequences.pop_back();

		n = sequences.size();
		l = Config::l;
		d1 = Config::d1;
		d2 = Config::d2;

	}

	void print_sequences() {
		cout << "Number of sequences:\t" << n << "\n\n";
		for(const auto& sequence : sequences)
			cout << "Length: " << sequence.length() << "\n" << sequence << "\n\n";
	}


}

#endif