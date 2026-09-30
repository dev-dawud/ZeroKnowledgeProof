#include <iostream>
#include <string>
#include <random>

#include "../header/verifier.h"

Verifier::Verifier() {

    mpz_init_set_ui(gmp_p, p);
    mpz_init_set_ui(gmp_g, g);

    mpz_init(gmp_y);
    mpz_init(gmp_t);
    mpz_init(gmp_s);
    mpz_init(gmp_c);
    mpz_init(gmp_tmp1);
    mpz_init(gmp_tmp2);
    mpz_init(gmp_q1);
    mpz_init(gmp_q2);

}

int Verifier::challenge() {

    int c = 0;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    c = dist(generator);

    // c -> prover
    return c;
}

void Verifier::verification(int& y, int& t, int& s, int& c) {
    
    mpz_set_ui(gmp_y, y);
    mpz_set_ui(gmp_t, t);
    mpz_set_ui(gmp_s, s);
    mpz_set_ui(gmp_c, c);

    // Proof: g^s % p = = (t * y^c) % p :: q = q

    // q1 = g^s % p
    mpz_powm(gmp_q1, gmp_g, gmp_s, gmp_p);

    // tmp1 = (y^c) % p
    mpz_powm(gmp_tmp1, gmp_y, gmp_c, gmp_p);

    // tmp2 = t * tmp1
    mpz_mul(gmp_tmp2, gmp_t, gmp_tmp1);

    // q2 = tmp2 % p
    mpz_mod(gmp_q2, gmp_tmp2, gmp_p);

    // mpz_cmp compare the to large int if they are the same
    // if they are the same then it will outputs 0 so it is succesfull
    if (mpz_cmp(gmp_q1, gmp_q2) == 0) {

        std::cout << "Succesful!";
    }
    else {

        std::cout << "Failed";
    }
}

Verifier::~Verifier() {
    
    mpz_clear(gmp_p);
    mpz_clear(gmp_g);

    mpz_clear(gmp_y);
    mpz_clear(gmp_t);
    mpz_clear(gmp_s);
    mpz_clear(gmp_c);
    mpz_clear(gmp_tmp1);
    mpz_clear(gmp_tmp2);
    mpz_clear(gmp_q1);
    mpz_clear(gmp_q2);
   
}

