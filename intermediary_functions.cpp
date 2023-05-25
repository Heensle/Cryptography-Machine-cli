#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "screen_functions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::seconds;
using std::chrono::milliseconds;
using ScreenFunctions::clear_screen;

namespace IntermediaryFunctions{

  void question(string cipher){

    bool secondTime = false;
    bool invalidInput = false;
    
    while(true){
      
      clear_screen();
  
      if (!secondTime && !invalidInput) {
        cout << "      Hey! Al here! I heard you had some questions. By the way, special codes won't work while you're in here: wait until you get to the terminal with Preston, Andy, or SmileBot to use those!" << endl;
      } else if (secondTime && invalidInput){
        cout << "      That's not a valid input. 1, 2, or 3! Remember, special functions won't work while you're in here." << endl;
      } else if (secondTime && !invalidInput){
        cout << "      Alright, we're back! Use one of the codes below! (PS: you still can't use special functions. Wait to be in a cipher to do that!)" << endl;
      }

      cout <<"      Which function do you want to hear about? (Press 'X' to return to the cipher you came from)." << endl << endl << "1 - ? function" << endl << "2 - CodeX function" << endl << "3 - Cipher Briefs"<< endl << endl << "      I want to hear about: ";
  
      string input;
      getline(cin, input);

      if (input.at(0) == '1' && input.length() == 1){
        clear_screen();
        cout << "? function -" << endl << endl;
        cout << "      The '?' function is an easy one: it's where you're here now, so you already know how to use it!" << endl << "If while you're in any of the ciphers, you want to hear about the special functions, or the ciphers, you can type '?' into the terminal to come here. I can tell you anything you need to know!" << endl << "      PS: Make sure that you only use it while in a cipher with Preston, Andy, or SmileBot. Unfortunately, I can't send you here, because I'm already with you!" << endl << endl;
      cout << "      Return to the main screen? ";
      string con;
      getline(cin, con);
      secondTime = true;

      } else if (input.at(0) == '2' && input.length() == 1){
        clear_screen();
        cout << "CodeX function -" << endl << endl;
        cout << "      Ah, this is a tricky one. It's called 'CodeX', but that's not how you call it! See, the purpose of this code is to make is fast to switch between ciphers. That way, instead of going through the whole introduction again (I do tend to talk a lot if you allow me to), you can simply traverse the Cryptography Machine® by yourself!" << endl;
        cout << "      To use the 'CodeX' function, first type the word 'Code' into the terminal (exactly like that! No switching up the capitalization!). Follow that directly with the number of the cipher you want to visit." << endl << endl << "'Code1' will take you to the Affine cipher with Preston." << endl << "'Code2' will take you to the Ceaser cipher with Andy." << endl << "'Code3' will take you to Frequency Analysis with SmileBot." << endl << endl << "      No changed capitalization! No spaces! And you'll be good!" << endl << endl << "      Return to the main screen? ";
      string con;
      getline(cin, con);
      secondTime = true;

      } else if (input.at(0) == '3' && input.length() == 1){
        bool invalidInput = false;
        while(true){
          clear_screen();
          cout << "      Yes! I love talking about the ciphers. Which cipher do you want to hear about?" << endl;
          if (invalidInput){
            cout << "      That wasn't a valid input. '1', '2', or '3'. (You can press 'X' to quit if you really want to...)" << endl;
          }
          cout << endl << "1 - Affine Cipher" << endl << "2 - Ceaser Cipher" << endl << "3 - Frequency Analysis" << endl << endl << "      I want to hear about: ";
          string input2;
          getline(cin, input2);

          if (input2.at(0) == '1' && input.length() == 1){
            clear_screen();
            cout << "1 - Affine Cipher" << endl;
            cout << "      The Affine Cipher uses math to encode the letters. It starts by coverting each letter in the message to a numerical value (ex: a = 0, b = 1, etc). Then, it performs some operations on them, and converts them back to letters using the same system. It can be decrypted by following the process--backwards!" << endl << "      This cipher takes two keys: a multiplication and addition. It is prepped to handle spaces, special characters (as long as they don't exceed 8-bit memory), numbers, and capital letters." << endl << endl << "      Back to main screen? ";
            string con;
            getline(cin, con);

          } else if (input2.at(0) == '2' && input.length() == 1){
            clear_screen();
            cout << "2 - Ceaser Cipher" << endl;
            cout << "      The Ceaser Cipher was the cipher Julius Ceaser used to send secret messages to his troops. This cipher simply moves the letters down the alphabet. For example, a Ceaser Cipher with a key of 1 would change A to B, B to C, etc, and a Ceaser Cipher with a key of 2 would change A to C, B to D, etc. It can be decrypted by applying the same shift back up the alphabet." << endl << "      This cipher is takes one key: the shift (tip: this number can only be an integer between 1 and 25). It is prepped to handle spaces, special characters (as long as they don't exceed 8-bit memory), numbers, and capital letters." << endl << endl << "      Back to main screen? ";
            string con;
            getline(cin, con);
    
          } else if (input2.at(0) == '3' && input.length() == 1){
            clear_screen();
            cout << "3 - Frequency Analysis" << endl;
            cout << "      Frequency Analysis is a process used to decrypt any message written in English and encoded in the English alphabet. This cipher works by analysing the frequency of each letter in the sample, and comparing that with the general frequency of letters in the English language. The code may be decrypted without a key, as it jsut requires some trial and error." << endl << "      This cipher initially only takes the sample message. After displaying both the frequency of letters in the English language and in the code, you may attempt to decode the message. Guesses must be fed to the comoputer in this form: 'letterInCode-letterGuess'. For example, if the letter X was present very frequently in my code, and I wanted to guess it is E, I would type in 'X-E'. This guess would then display in a 'decrypted' version of the code. This cipher is prepped to handle spaces, special characters (as long as they don't exceed 8-bit memory), numbers, and capital letters. For simplicity, however, the decrypted code will only be displayed in capital letters." << endl << endl << "      Back to main screen? ";
            string con;
            getline(cin, con);

          } else if ((input2.at(0) == 'x' || 'X') && input.length() == 1){
            break;
          } else {
            invalidInput = true;
          }
        }
      } else if ((input.at(0) == 'x' || 'X') && input.length() == 1){
        break;
      } else {
        invalidInput = true;
        secondTime = true;
      }
    }
    clear_screen();
    cout << "      So long! I hope the next time I see you, you're a developed crytography apprentice!" << endl << endl << "      Sending you back to " << cipher << ", please wait..." << endl << endl;
    sleep_for(std::chrono::seconds(2));
  }
}