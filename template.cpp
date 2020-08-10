//
// Created by themastermind on 7/30/20.
//

#ifndef DHK_TEMPLATE
#define DHK_TEMPLATE

#include <bits/stdc++.h>
using namespace std;

#define for_inc(i, n) for(int i = 0, _n = n; i < _n; ++i)
#define for_dec(i, n) for(int i = n - 1; i >= 0; --i)


template <class _o_type, class _l_type>
bool in(const _o_type &obj, const _l_type &list) {
	for(auto element : list)
		if (obj == element)
			return true;
	return false;
}


#endif