#pragma once

#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <gmp.h>

class Verifier {
private:

    int p = 23;
    int q = 11;
    int g = 2;

    // The verifier can`t know x thats the whole point of this consept
    // The prover must reveal the secret x to the verifier without showing x

    mpz_t gmp_tmp1, gmp_tmp2, gmp_q1, gmp_q2, gmp_p, gmp_g, gmp_y, gmp_t, gmp_s, gmp_c;

public:

    Verifier();

    int challenge();
    void verification(int& y, int& t, int& s, int& c);

    ~Verifier();
};
