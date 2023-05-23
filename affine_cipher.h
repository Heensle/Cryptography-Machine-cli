#include <string>
using std::string;

namespace AffineCipher {

  int affine_cipher_intro(bool &encode, int &cipher);

  int affine_cipher_encode(int &cipher);

  int affine_cipher_decode(int &cipher);

}