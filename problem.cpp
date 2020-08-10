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

	void initialize() {
		ifstream input_file(Config::input);
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

		freopen(Config::output.c_str(), "w", stdout);
	}

	void print_sequences() {
		cout << "Number of sequences:\t" << n << "\n\n";
		for(const auto& sequence : sequences)
			cout << "Length: " << sequence.length() << "\n" << sequence << "\n\n";
	}

	int hamming_distance(const string &motif, int seq_i, int seq_pivot) {
		int d = l;
		for_inc(i, motif.length())
			if (motif[i] == sequences[seq_i][seq_pivot+i]) d--;
		return d;
	}

	int delta(const string &motif, int seq_i) {
		int d = l;
		for_inc(seq_pivot, sequences[seq_i].length() - l + 1)
			d = min(d, hamming_distance(motif, seq_i, seq_pivot));
		return d;
	}

	int delta(const string &motif) {
		int d = 0;
		for_inc(i, n)
			d = max(d, delta(motif, i));
		return d;
	}

}

#endif