#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

#include <gmp.h>

class Prover {
public:

    mpz_t gmp_p, gmp_g, gmp_x, gmp_y, gmp_t, gmp_r , gmp_s, gmp_c, gmp_tmp, gmp_q;
    int p = 23;
    int q = 11;
    int g = 2;
    int x = 4;




    Prover() {

        // random numbers initiliazion
        int r = 0;
        int c = 0;

        std::random_device rd;
        std::mt19937 generator(rd());

        std::uniform_int_distribution<int> dist(1, 10);

        r = dist(generator);
        c = dist(generator);

        mpz_init_set_ui(gmp_r, r);
        mpz_init_set_ui(gmp_c, c);

        //initialize new variables because int doesnt work with gmp
        mpz_init_set_ui(gmp_p, p);
        mpz_init_set_ui(gmp_g, g);
        mpz_init_set_ui(gmp_x, x);
        mpz_init_set_ui(gmp_q, q);

        mpz_init(gmp_y);
        mpz_init(gmp_t);
        mpz_init(gmp_s);
        mpz_init(gmp_tmp);

        mpz_mul(gmp_tmp, gmp_c, gmp_x);   // tmp = c * x
        mpz_add(gmp_s, gmp_r, gmp_tmp);   // s = r  + tmp
    }

    void calculatePBkey() {

        // calculates: y = (g^x) % p
        mpz_powm(gmp_y, gmp_g, gmp_x, gmp_p);

        std::cout << mpz_get_ui(gmp_y) << std::endl;
    }

    void commitment() {

        // calculates: t = (g^r) % p
        mpz_powm(gmp_t, gmp_g, gmp_r, gmp_p);

        std::cout << mpz_get_ui(gmp_t) << std::endl;

    }

    //int challenge() {

        

        // c -> prover
     //   return c;

   // }

    void response() {

        // s = r + c * x % q
        // s -> verifier

        mpz_mod(gmp_s, gmp_s, gmp_q);

        std::cout << mpz_get_ui(gmp_s) << std::endl;
    }

    class Verifier {

        void verification() {

        }


    };

};

int main()
{
    Prover prover;

    prover.calculatePBkey();
    prover.commitment();
    prover.response();
}