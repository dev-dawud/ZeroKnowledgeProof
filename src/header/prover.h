#pragma once

#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <gmp.h>

class Prover {
private:

	int p = 23;
	int q = 11;
	int g = 2;

	int x = 4; // The Prover is the only one who knows x and is ONLY allowed to know it

	// declare new varible type
	mpz_t gmp_p, gmp_g, gmp_x, gmp_y, gmp_t, gmp_r, gmp_s, gmp_c, gmp_tmp, gmp_q;

public:

Prover();

int calculatePBkey();
int commitment();
int response(int& c);

~Prover();

};