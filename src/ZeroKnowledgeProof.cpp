#pragma warning(disable : 4146) // AI-Generated
#pragma warning(disable : 4244) // AI-Generated

#include <iostream>

#include "header/prover.h"
#include "header/verifier.h"

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