//
// Created by themastermind on 8/1/20.
//

#ifndef LDDMS3_SOLVER
#define LDDMS3_SOLVER

#include "template.cpp"
#include "problem.cpp"
#include "checker.cpp"

namespace Solver {
	unordered_set<string> found_motif;

	void achieve_motif(const string &motif) {
		if (found_motif.find(motif) != found_motif.end()) return;

		found_motif.insert(motif);

		Checker::check_motif(motif);

		if (motif == "CATCCACATCAAGATCGAC") cerr << motif.length() << "\n";

		cout << motif << "\n";
	}

	void travel_on_neighbor_tree(
			string &motif,
			const int &pivot,
			const int &h,
			int delta = -1
			) {
		if (pivot == Problem::l) return;
		if (delta == -1) delta = Problem::delta(motif);
		if (delta <= Problem::d1) {
			achieve_motif(motif);
			return;
		}
		if (delta - Problem::d1 > Problem::d2 - h) return;

		char current_character = motif[pivot];

		if (delta - Problem::d1 == Problem::d2 - h) {
			for (auto ch : Constant::ALPHABET) {
				int _h = h + (ch != current_character);
				if (_h > Problem::d2) continue;
				motif[pivot] = ch;

				int _delta = Problem::delta(motif);
				if (_delta == delta - 1)
					travel_on_neighbor_tree(
							motif,
							pivot + 1,
							_h,
							_delta
					);

				motif[pivot] = current_character;
			}
			return;
		}

		if (delta - Problem::d1 == Problem::d2 - h - 1) {
			for(auto ch : Constant::ALPHABET) {
				int _h = h + (ch != current_character);
				if (_h > Problem::d2) continue;
				motif[pivot] = ch;

				int _delta = Problem::delta(motif);
				if (_delta <= delta - 1)
					travel_on_neighbor_tree(
							motif,
							pivot + 1,
							_h,
							_delta
					);

				motif[pivot] = current_character;
			}
			return;
		}

		for(auto ch : Constant::ALPHABET) {
			int _h = h + (ch != current_character);
			if (_h > Problem::d2) continue;
			motif[pivot] = ch;
			travel_on_neighbor_tree(
					motif,
					pivot + 1,
					_h
			);
		}
	}

	void solve() {
		for(const auto& sequence : Problem::sequences)
			for_inc(seq_pivot, sequence.length() - Problem::l + 1) {
				string motif = sequence.substr(seq_pivot, Problem::l);
				travel_on_neighbor_tree(motif, 0, 0);
			}
	}
}

#endif
