#include <iostream>
#include <string>

#include "screen_functions.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using ScreenFunctions::clear_screen;

namespace IntroScreens{

  void intro_sequence(bool &secondTime, bool &instruction){

    while (true){

      clear_screen();

      cout << "      Welcome to the multi-purpose, for all intents and purposes, Cryptography Machine®! My name is Al, and I'll be your escort through this all." << endl << endl << "      Would you like to see all instructional material? (y / n)" << endl;
      if (secondTime){
        cout << "      That isn't a valid input! 'y' or 'n'." << endl;
      }
      secondTime = false;
      string validation;
      getline(cin, validation);
        if (validation == "y"|| validation == "Y"){
    instruction = true;
          break;
      } else if (validation == "n" || validation == "N"){
        instruction = false;
          break;
      } else {
        secondTime = true;
      }
    }
  }

  void cipher_set_up(bool &secondTime, int &cipher, bool &instruction){

    while (true){

      string input;

      clear_screen();
    
      if (instruction){
        cout << "      Great! Cryptography is the art of writing or solving codes. It's a way of keeping information safe! The easiest way to crack a code is if you have the 'key'. The 'key' refers to the transformations on the message that encrypts and decrypts it." << endl << "      Unfortunately, sometimes, we don't have the key. Never fear! Through some trial and error, it's possible to crack simple codes through brute forcing. However, it can be grueling work to rewrite all the code, encrypt it by hand, or have to decrypt the code by writing it all out on a sheet of paper." << endl << "      This is where the Crytography Machine® comes in!" << endl << "      With this, all you need to do is give the machine some basic information, and it will compute it faster than ever! It makes it much faster and more efficient to try and crack codes." << endl << endl << "      Continue? ";
        string con;
        getline(cin, con);

        clear_screen();

        cout << "1 - Affine Cipher" << endl;
        cout << "      The Affine Cipher uses math to encode the letters. It starts by coverting each letter in the message to a numerical value (ex: a = 0, b = 1, etc). Then, it performs some operations on them, and converts them back to letters using the same system. It can be decrypted by following the process--backwards!" << endl << "      This cipher takes two keys: a multiplication and addition. It is prepped to handle spaces, special characters (as long as they don't exceed 8-bit memory), numbers, and capital letters." << endl << endl << "      Continue? ";
        getline(cin, con);

        clear_screen();

        cout << "2 - Ceaser Cipher" << endl;
        cout << "      The Ceaser Cipher was the cipher Julius Ceaser used to send secret messages to his troops. This cipher simply moves the letters down the alphabet. For example, a Ceaser Cipher with a key of 1 would change A to B, B to C, etc, and a Ceaser Cipher with a key of 2 would change A to C, B to D, etc. It can be decrypted by applying the same shift back up the alphabet." << endl << "      This cipher is takes one key: the shift (tip: this number can only be an integer between 1 and 25). It is prepped to handle spaces, special characters (as long as they don't exceed 8-bit memory), numbers, and capital letters." << endl << endl << "      Continue? ";
        getline(cin, con);

        clear_screen();

        cout << "3 - Frequency Analysis" << endl;
        cout << "      Frequency Analysis is a process used to decrypt any message written in English and encoded in the English alphabet. This cipher works by analysing the frequency of each letter in the sample, and comparing that with the general frequency of letters in the English language. The code may be decrypted without a key, as it jsut requires some trial and error." << endl << "      This cipher initially only takes the sample message. After displaying both the frequency of letters in the English language and in the code, you may attempt to decode the message. Guesses must be fed to the comoputer in this form: 'letterInCode-letterGuess'. For example, if the letter X was present very frequently in my code, and I wanted to guess it is E, I would type in 'X-E'. This guess would then display in a 'decrypted' version of the code. This cipher is prepped to handle spaces, special characters (as long as they don't exceed 8-bit memory), numbers, and capital letters. For simplicity, however, the decrypted code will only be displayed in capital letters." << endl << endl << "      Continue? ";
        getline(cin, con);

        clear_screen();

        cout << "      Please enter in the numerical value of the cipher strategy you want to visit (1, 2, or 3, as labeled). Remember, instructions are always avaliable if you just enter a question mark into the terminal at any time after thsi screen! If you want to switch to another cipher, enter 'Cipher' and then the number of the cipher (ex: 'Cipher1' for the Affine Cypher) into the terminal at any time after this sceen!" << endl << endl;

        instruction = false;
      }

      if (secondTime){
        cout << "      That's not a valid input. Only input 1, 2, or 3. Remember, '?' and 'CipherX' are only valid after your selection is made!" << endl << endl;
      }
    
      cout << "1 - Affine Cipher" << endl << "2 - Ceaser Cipher" << endl << "3 - Frequency Analysis" << endl << endl << "      I want to try Cipher: ";
    
      getline(cin, input);
      secondTime = false;

    
      if (input.length() == 1 && input.at(0) == '1'){
        cipher = 1;
        break;
      
      } else if (input.length() == 1 && input.at(0) == '2'){
        cipher = 2;
        break;
      
      } else if (input.length() == 1 &&input.at(0) == '3'){
        cipher = 3;
        break;
      
      } else {
        secondTime = true;
      }
    }
  }
}