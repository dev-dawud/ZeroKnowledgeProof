#pragma warning(disable : 4146) // AI-Generated
#pragma warning(disable : 4244) // AI-Generated

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

#include <gmp.h>

int p = 23;
int q = 11;
int g = 2;
int x = 4;

class Prover {
public:

    mpz_t gmp_p, gmp_g, gmp_x, gmp_y, gmp_t, gmp_r , gmp_s, gmp_c, gmp_tmp, gmp_q;
    


    Prover() {

        // random numbers initiliazion
        int r = 0;

        std::random_device rd;
        std::mt19937 generator(rd());

        std::uniform_int_distribution<int> dist(1, 10);

        r = dist(generator);

        mpz_init_set_ui(gmp_r, r);

        //initialize new variables because int doesnt work with gmp
        mpz_init_set_ui(gmp_p, p);
        mpz_init_set_ui(gmp_g, g);
        mpz_init_set_ui(gmp_x, x);
        mpz_init_set_ui(gmp_q, q);

        mpz_init(gmp_y);
        mpz_init(gmp_t);
        mpz_init(gmp_s);
        mpz_init(gmp_tmp);

       
    }

    int calculatePBkey() {

        // calculates: y = (g^x) % p
        mpz_powm(gmp_y, gmp_g, gmp_x, gmp_p);

        std::cout << mpz_get_ui(gmp_y) << std::endl;

        int y = mpz_get_ui(gmp_y);

        return y;

    }

    int commitment() {

        // calculates: t = (g^r) % p
        mpz_powm(gmp_t, gmp_g, gmp_r, gmp_p);

        std::cout << mpz_get_ui(gmp_t) << std::endl;

        int t = mpz_get_ui(gmp_t);

        return t;

    }

    int response(int& c) {

        // s = r + c * x % q
        // s -> verifier

        mpz_init_set_ui(gmp_c, c);
        
        mpz_mul(gmp_tmp, gmp_c, gmp_x);   // tmp = c * x
        mpz_add(gmp_s, gmp_r, gmp_tmp);   // s = r  + tmp


        mpz_mod(gmp_s, gmp_s, gmp_q);

        std::cout << mpz_get_ui(gmp_s) << std::endl;
        
        int s = mpz_get_ui(gmp_s);

        return s;
    }

};

class Verifier {
public:

    Prover prv;

    int challenge() {

        int c = 0;

        std::random_device rd;
        std::mt19937 generator(rd());

        std::uniform_int_distribution<int> dist(1, 10);

        c = dist(generator);

        // c -> prover
        return c;
    }

    void verification(int& y, int& t, int& s, int& c) {

        mpz_t gmp_tmp1, gmp_tmp2, gmp_q1, gmp_q2, gmp_p, gmp_g, gmp_y, gmp_t, gmp_s, gmp_c;

        mpz_init_set_ui(gmp_p, p);
        mpz_init_set_ui(gmp_g, g);
        mpz_init_set_ui(gmp_y, y);
        mpz_init_set_ui(gmp_t, t);
        mpz_init_set_ui(gmp_s, s);
        mpz_init_set_ui(gmp_c, c);

        mpz_init(gmp_tmp1);
        mpz_init(gmp_tmp2);
        mpz_init(gmp_q1);
        mpz_init(gmp_q2);

        //g^s % p = = (t * y^c) % p

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

            std::cout << "Fehlgeschlagen";
        }
    }


};

int main()
{
    Prover prover;
    Verifier ver;

    int y = prover.calculatePBkey();
    int t = prover.commitment();

    int c = ver.challenge();

    int s = prover.response(c);
    ver.verification(y ,t ,s ,c);
}