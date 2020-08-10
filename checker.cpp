//
// Created by themastermind on 8/1/20.
//

#ifndef LDDMS3_CHECKER
#define LDDMS3_CHECKER

#include "template.cpp"
#include "problem.cpp"

namespace Checker {
	void assertFailure(const string &motif, const string &message) {
		cerr << "Failed Motif: " << motif << "\n" << message << "\n";
		exit(0);
	}

	void check_motif(const string &motif) {
		if (motif.length() != Problem::l) assertFailure(motif, "Not satisfy l-condition");
		for(const auto &sequence: Problem::sequences) {
			bool found = false;
			for_inc(i, sequence.length() - Problem::l + 1) {
				int hamming_distance = 0;
				for_inc(j, Problem::l) {
					if (motif[j] != sequence[i + j])
						hamming_distance++;
					if (hamming_distance > Problem::d1) break;
				}
				if (hamming_distance <= Problem::d1) {
					found = true;
					break;
				}
			}
			if (!found) assertFailure(motif, "Not satisfy d1-condition");
		}
	}
}

#endif
