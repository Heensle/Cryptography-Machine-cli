#include <iostream>
#include <string>

#include "intermediary_functions.h"
#include "screen_functions.h"
using namespace IntermediaryFunctions;
using namespace ScreenFunctions;

using std::cout;
using std::endl;
using std::string;
using std::cin;

namespace CeaserCipher{

  int ceaser_cipher_intro(bool &encode, int &cipher){

    bool invalidInput = false;
    bool returnQuestion = false;

    while (true){

      clear_screen();

      if (!invalidInput && !returnQuestion){

        cout << "      Howdy there, partner! My name's Andy, and welcome to Ceaser Cipher Ranch (get it?), the simplest cipher of all!" << endl;

      } else if (returnQuestion){
        cout << "      Welcome back! I reckon Al had mighty words with you: the mouth on that one!" << endl;
      } else if (invalidInput){
        cout << "      I don't know what that means, mate. I'm only looking for an 'e' or 'd', or a code Al mighta given ya'." << endl;
      }
          
          
      cout << "      'R you looking to encode, or decode? (e / d)" << endl;

      string input;
      getline(cin, input);

      if (input.length() == 1 && input == "?"){
        question("Andy");
        returnQuestion = true;
      } else if (input.length() == 5 && input == "Code1"){
        cipher = 1;
        return 1;
      } else if (input.length() == 5 && input == "Code2"){
        clear_screen();
        cout << "      Ha! Good one! We're standing in Ceaser Cipher Ranch right now, so that code won't take you no where!" << endl << "      Let's go back to the selection, eh?" << endl << endl << "      Back to main screen? ";
        string con;
        getline(cin, con);
      } else if (input.length() == 5 && input == "Code3"){
        cipher = 3;
        return 3;
      } else if (input.length() == 1 && (input == "e" || input == "E")){
        encode = true;
        break;
      } else if (input.length() == 1 && (input == "d" || input == "D")){
        encode = false;
        break;
      } else {
        invalidInput = true;
      }
    }
    return 2;
  }

  int ceaser_cipher_encode(int &cipher){

    bool invalidInput = false;
    bool falseNum = false;
    bool returnQuestion = false;

    while (true){
      while (true){
        clear_screen();

        if (!invalidInput && !falseNum && !returnQuestion){
          cout << "      Alrighty! Let's get to encoding! I told ya' the Ceaser Cipher Ranch is home to the easiest cipher, and I dun' meant it! All I need is one key, an integer between one and twenty five." << endl;
        } else if (invalidInput){
          cout << "      Yeah, mate... I got no clue what that is. Try again. I need an integer between one and twenty five." << endl;
        } else if (falseNum){
          cout << "      Close! That's a number (I think), but it's not an integer between one and twenty five." << endl;
        } else if (returnQuestion){
          cout << "      Welcome back, mate! I hope Al didn't blabber too much, and that you actually learned something. Would be one in a million if you did! Haha, just kidding, I love Al." << endl << "      Just reminding you, I'm going to need an integer between one and twenty five to encode your message for you." << endl;
        }
        invalidInput = false;
        falseNum = false;
        returnQuestion = false;

        string input;
        getline(cin, input);

        if (input == "?"){
          question("Andy");
          returnQuestion = true;
          break;
        } else if (input == "Code1"){
          cipher = 1;
          return 1;
        } else if (input == "Code2"){
          cout << "      You're already in Ceaser Cipher Ranch, mate. Code2 will do you no good! Use Code1 to visit Preston (not sure why you'd want to though, the prententious hipster...) or Code3 to visit SmileBot." << endl << "      Let's go back to the key selection screen for now though, huh?" << endl << endl << "      Back to key selection? ";
          string con;
          getline(cin, con);
          break;
        } else if (input == "Code2"){
          cipher = 3;
          return 3;
        } else if (input.length() > 2 && input.at(0) >= '0' && input.at(0) <= '9'){
          falseNum = true;
          break;
        } else if (input.length() == 0 || input.length() > 2){
          invalidInput = true;
          break;
        }

        if (input.length() == 1 && !(input.at(0) >= '0' && input.at(0) <= '9')){
          invalidInput = true;
          break;
        }
        if (input.length() == 2 && !(input.at(0) >= '1' && input.at(0) <= '2' && input.at(1) >= '0' && input.at(1) <= '9')){
          invalidInput = true;
          break;
        }
        if (input.length() == 2 && input.at(0) == '2' && input.at(1) > '5'){
          invalidInput = true;
          break;
        }

        int shift = stoi(input);

        clear_screen();

        cout << "      Perfect! Excellent work! Now, all you need to do is type in your message. You may include numbers, capital letters, spaces, and special characters (provided they don't exceed 8-bit memory), but the jumbled mess that is spit out will be written in capital letters." << endl << "      Also, special codes won't work on this screen. Sorry!" << endl << "      Type your message in here:" << endl << endl;
        string unMess;
        getline(cin, unMess);

        char enMess[unMess.length()];

        for (int i = 0; i < unMess.length(); i++){
          if (unMess.at(i) >= 'a' && unMess.at(i) <= 'z'){
            enMess[i] = ((unMess.at(i) - 'a' + shift) % 26) + 'A';
          } else if (unMess.at(i) >= 'A' && unMess.at(i) <= 'Z'){
            enMess[i] = ((unMess.at(i) - 'A' + shift) % 26) + 'A';
          } else {
            enMess[i] = unMess.at(i);
          }
        }

        clear_screen();
        
        cout << "      Your encrypted message is: " << endl << endl << endl << endl;
        for (int i = 0; i < unMess.length(); i++){
          cout << enMess[i];
        }
        cout << endl << endl << endl << endl << "      ...using the key " << shift << ". Just let me know when you're ready to go back." << endl << endl << "      Continue? ";
        string con;
        getline(cin, con);
        return 2;
      }
    }
    return 2;
  }

  int ceaser_cipher_decode(int &cipher){
    
    bool invalidInput = false;
    bool falseNum = false;
    bool returnQuestion = false;

    while (true){
      while (true){
        clear_screen();

        if (!invalidInput && !falseNum && !returnQuestion){
          cout << "      Alrighty! Let's get to decoding! I told ya' the Ceaser Cipher Ranch is home to the easiest cipher, and I dun' meant it! All I need is one key, an integer between one and twenty five." << endl;
        } else if (invalidInput){
          cout << "      Yeah, mate... I got no clue what that is. Try again. I need an integer between one and twenty five." << endl;
        } else if (falseNum){
          cout << "      Close! That's a number (I think), but it's not an integer between one and twenty five." << endl;
        } else if (returnQuestion){
          cout << "      Welcome back, mate! I hope Al didn't blabber too much, and that you actually learned something. Would be one in a million if you did! Haha, just kidding, I love Al." << endl << "      Just reminding you, I'm going to need an integer between one and twenty five to decode your message for you." << endl;
        }
        invalidInput = false;
        falseNum = false;
        returnQuestion = false;

        string input;
        getline(cin, input);

        if (input == "?"){
          question("Andy");
          returnQuestion = true;
          break;
        } else if (input == "Code1"){
          cipher = 1;
          return 1;
        } else if (input == "Code2"){
          cout << "      You're already in Ceaser Cipher Ranch, mate. Code2 will do you no good! Use Code1 to visit Preston (not sure why you'd want to though, the prententious hipster...) or Code3 to visit SmileBot." << endl << "      Let's go back to the key selection screen for now though, huh?" << endl << endl << "      Back to key selection? ";
          string con;
          getline(cin, con);
          break;
        } else if (input == "Code2"){
          cipher = 3;
          return 3;
        } else if (input.length() > 2 && input.at(0) >= '0' && input.at(0) <= '9'){
          falseNum = true;
          break;
        } else if (input.length() == 0 || input.length() > 2){
          invalidInput = true;
          break;
        }

        if (input.length() == 1 && !(input.at(0) >= '0' && input.at(0) <= '9')){
          invalidInput = true;
          break;
        }
        if (input.length() == 2 && !(input.at(0) >= '1' && input.at(0) <= '2' && input.at(1) >= '0' && input.at(1) <= '9')){
          invalidInput = true;
          break;
        }
        if (input.length() == 2 && input.at(0) == '2' && input.at(1) > '5'){
          invalidInput = true;
          break;
        }

        int shift = stoi(input);

        clear_screen();

        cout << "      Perfect! Excellent work! Now, all you need to do is type in your message. You may include numbers, capital letters, spaces, and special characters (provided they don't exceed 8-bit memory), but the translated message that is spit out will be written in capital letters." << endl << "      Also, special codes won't work on this screen. Sorry!" << endl << "      Type your message in here:" << endl << endl;
        string enMess;
        getline(cin, enMess);

        char unMess[enMess.length()];

        for (int i = 0; i < enMess.length(); i++){
          if (enMess.at(i) >= 'a' && enMess.at(i) <= 'z'){
            unMess[i] = ((enMess.at(i) - 'a' + 26 - shift) % 26) + 'A';
          } else if (enMess.at(i) >= 'A' && enMess.at(i) <= 'Z'){
            unMess[i] = ((enMess.at(i) - 'A' + 26 - shift) % 26) + 'A';
          } else {
            unMess[i] = enMess.at(i);
          }
        }

        clear_screen();
        
        cout << "      Your decrypted message is: " << endl << endl << endl << endl;
        for (int i = 0; i < enMess.length(); i++){
          cout << unMess[i];
        }
        cout << endl << endl << endl << endl << "      ...using the key " << shift << ". Just let me know when you're ready to go back." << endl << endl << "      Continue? ";
        string con;
        getline(cin, con);
        return 2;
      }
    }
    return 2;
  }

}