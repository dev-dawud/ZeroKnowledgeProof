#include <iostream>
#include <string>
#include <random>

#include "../header/prover.h"

    Prover::Prover() {

        // random numbers initiliazion
        int r = 0;

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> dist(1, 10);

        r = dist(generator);

        //initialize new variables because int doesnt work with gmp
        mpz_init_set_ui(gmp_p, p);
        mpz_init_set_ui(gmp_g, g);
        mpz_init_set_ui(gmp_x, x);
        mpz_init_set_ui(gmp_q, q);
        mpz_init_set_ui(gmp_r, r);

        mpz_init(gmp_y);
        mpz_init(gmp_t);
        mpz_init(gmp_s);
        mpz_init(gmp_tmp);
        mpz_init(gmp_c);

    }

    int Prover::calculatePBkey() {

        // y = (g^x) % p
        mpz_powm(gmp_y, gmp_g, gmp_x, gmp_p);

        std::cout << mpz_get_ui(gmp_y) << std::endl;

        // converts gmp_y to an integer so it can be used in C++
        int y = mpz_get_ui(gmp_y);

        return y;

    }

    int Prover::commitment() {

        // calculates: t = (g^r) % p
        mpz_powm(gmp_t, gmp_g, gmp_r, gmp_p);

        std::cout << mpz_get_ui(gmp_t) << std::endl;

        int t = mpz_get_ui(gmp_t);

        return t;

    }

    int Prover::response(int& c) {

        // s = r + c * x % q
        // s -> verifier

        mpz_init_set_ui(gmp_c, c);

        // tmp = c * x
        mpz_mul(gmp_tmp, gmp_c, gmp_x);
        
        // s = r  + tmp
        mpz_add(gmp_s, gmp_r, gmp_tmp);   

        // s = s % q
        mpz_mod(gmp_s, gmp_s, gmp_q);

        std::cout << mpz_get_ui(gmp_s) << std::endl;

        int s = mpz_get_ui(gmp_s);

        return s;
    }

    Prover::~Prover() {

        mpz_clear(gmp_p);
        mpz_clear(gmp_g);
        mpz_clear(gmp_q);
        mpz_clear(gmp_r);
        mpz_clear(gmp_c);
        mpz_clear(gmp_x);
        mpz_clear(gmp_y);
        mpz_clear(gmp_t);
        mpz_clear(gmp_s);
        mpz_clear(gmp_tmp);

    }