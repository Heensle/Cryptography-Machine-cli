#include "affine_cipher.h"
#include "ceaser_cipher.h"
#include "frequency_analysis.h"
#include "intro_screens.h"
#include <iostream>
#include <string>

using std::string;
using namespace IntroScreens;
using namespace AffineCipher;
using namespace CeaserCipher;
using namespace FrequencyAnalysis;

int main() {

  bool secondTime = false;
  bool instruction;
  int cipher;

  intro_sequence(secondTime, instruction);
  cipher_set_up(secondTime, cipher, instruction);

  while (true) {
    while (cipher == 1) {
      bool encode;
      affine_cipher_intro(encode, cipher);
      if (cipher == 1 && encode) {
        affine_cipher_encode(cipher);
      } else if (cipher == 1 && !encode) {
        affine_cipher_decode(cipher);
      }
    }
    while (cipher == 2) {
      bool encode;
      ceaser_cipher_intro(encode, cipher);
      if (cipher == 2 && encode) {
        ceaser_cipher_encode(cipher);
      } else if (cipher == 2 && !encode) {
        ceaser_cipher_decode(cipher);
      }
    }
    while (cipher == 3) {
      frequency_analysis(cipher);
    }
  }

  return 0;
}