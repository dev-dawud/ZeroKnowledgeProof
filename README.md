# ZeroKnowledgeProof

This project is an C++ implementation of a zero knowledge proof based on the Schnorr protocol. 
The concept of a ZKP is to mathematically prove another party (the verifier) that you know a certain secret x without ever revealing that secret. 
In the real world, this concept is a key component of cybersecurity.
For example, a classic problem with logins is that you have to send your password to a server, which means it can be stolen in the event of a data breach. 
With a ZKP, the user (prover) never sends their password. 
Instead, they use it locally on their device to correctly answer a cryptographic challenge from the server.
In the end, the server is 100% convinced that the user knows the secret, but has absolutely no idea (zero knowledge) what the secret is.


This project strictly separates the logic into two independent classes (`Prover` and `Verifier`) to simulate a secure real-world architecture. The Prover safely encapsulates the secret `x`, while the Verifier only operates with public parameters to validate the mathematical proof.

The flow of the implemented **Schnorr Protocol** works as follows:
1. **Setup:** Both parties agree on the public parameters: a prime `p`, a prime `q`, and a generator `g`. The Prover calculates their public key `y = (g^x) % p`.
2. **Commitment:** The Prover generates a random number `r`, calculates the commitment `t = (g^r) % p`, and sends `t` to the Verifier.
3. **Challenge:** The Verifier generates a random number `c` (the challenge) and sends it to the Prover.
4. **Response:** The Prover calculates the response `s = (r + c * x) % q` and sends `s` back to the Verifier.
5. **Verification:** The Verifier checks if `(g^s) % p == (t * y^c) % p`. If the equation holds true, the mathematical proof is successful.


## Requirements
- C++ 11 or later
- GMP Library (GNU) for large integer arithmetic
- Visual Studio (MSVC) or any standard C++ compiler


## Installation
Use ``git clone`` to download the project.

```bash 
git clone https://github.com/dev-dawud/ZeroKnowledgeProof.git
```
Before you run and test the project, make sure the compiler in Visual Studio is set to **“Release (x64)”** to ensure smooth real time performance of the program. 

## Contributing
Contributions are welcome! (But please follow the existing code style and write me an E-mail to david_wahab@icloud.com for permission)
If you have any suggestions or improvements, please feel free to submit a pull request.

## Acknowledgments
- Thanks to Gemini for the idea and for helping with debugging (Every AI generated code/line will be marked as "AI-Generated")
- DeepL for helping with the translation of the README files and git commits into English

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


