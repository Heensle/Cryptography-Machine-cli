#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "screen_functions.h"
#include "intermediary_functions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::chrono::seconds;
using std::this_thread::sleep_for;
using IntermediaryFunctions::question;
using ScreenFunctions::clear_screen;

namespace AffineCipher{

  int affine_cipher_intro(bool &encode, int &cipher){

    bool invalidInput = false;

    while (true){

      clear_screen();
  
      if (!invalidInput){
        cout << "      Greetings, darling. Welcome to the Affine cipher. My name is Preston. ";
      } else {
        cout << "      That's not a valid input. Make sure it's either 'e', 'd', or a different specified code Al has gave you ('?', 'CodeX', etc). ";
      }
      invalidInput = false;
      cout << endl << "      Are you looking to encode or decode? (e / d)." << endl;
  
      string input;
      getline(cin, input);
  
      if (input.length() == 1 && (input.at(0) == 'e' || input.at(0) == 'E')){
        encode = true;
        break;
      } else if (input.length() == 1 && (input.at(0) == 'd' || input.at(0) == 'D')){
        encode = false;
        break;
      } else if (input == "?"){
        question("Preston");
      } else if (input == "Code1"){
        clear_screen();
        cout << "      You're already in the Affine cipher, darling. 'Code1' codes for here. If you wish to the see the other ciphers, 'Code2' will take you to the Ceaser cipher, and 'Code3' will take you to Frequency Analysis. But why should you ever want to leave the prestigious Affine cipher?" << endl << endl << "      Shall we return to the main screen? ";
        string con;
        getline(cin, con);
      } else if (input == "Code2"){
        cipher = 2;
        return 2;
      } else if (input == "Code3"){
        cipher = 3;
        return 3;
      } else {
        invalidInput = true;
      }
    }
    return 1;
  }

  int affine_cipher_encode(int &cipher){

    bool returnQuestion = false;
    bool invalidInput = false;
    bool falseNum = false;

    while (true){
      while (true){
        clear_screen();
  
        if (!returnQuestion && !invalidInput && !falseNum){
          cout << "      Excellent choice." << endl;
        } else if (returnQuestion){
          cout << "      Welcome back. I trust Al answered all questions you may have had." << endl;
        } else if (invalidInput){
          cout << "      That is not a valid input, darling. Please review my instructions for passing keys over." << endl;
        } else if (falseNum){
          cout << "      Ooh, this is a tricky error. It seems you may have inputted numbers that would result in a faulty cipher (either that or you didn't pass your keys correctly). Please visit this website if you are not sure which keys will and willn not result in acceptable codes: 'https://crypto.interactive-maths.com/affine-cipher.html'." << endl;
        }
        returnQuestion = false;
        invalidInput = false;
  
        cout << "      May I ask you for the key you want to encode with?" << endl << "      To pass it over, type something like, '1 2' or '3 4', where the first integer is the multiplication key and the second integer is the addition shift, and they are seperated by a space." << endl << endl;
  
        string input;
        getline(cin, input);
  
        if (input.length() == 1 && input.at(0) == '?'){
          question("Preston");
          returnQuestion = true;
          break;
        } else if (input.length() == 5 && input == "Code1"){
          clear_screen();
          cout << "      You're already inside the Affine cipher, silly. Let's proceed back to select your key, hm?" << endl << endl << "      Return to key selection? ";
          string con;
          getline(cin, con);
          break;
          
        } else if (input.length() == 5 && input == "Code2"){
          cipher = 2;
          return 2;
        } else if (input.length() == 5 && input == "Code3"){
          cipher = 3;
          return 3;
        }

        if (input.length() < 3 || input.length() > 5){
          invalidInput = true;
          break;
        }

        int mult;
        int add;

        if (input.length() == 3){
          if ((input.at(0) >= '0' && input.at(0) <= '9') && input.at(1) == ' ' && (input.at(2) >= '0' && input.at(2) <= '9')){
            mult = input.at(0) - '0';
            add = input.at(2) - '0';
          } else {
            invalidInput = true;
            break;
          }
        } else if (input.length() == 4){
          bool found = false;
          int index;
          for (int i = 0; i < input.length(); i++){
            if (input.at(i) == ' '){
              index = i;
              found = true;
            }
          }  
          if (!found || (index != 1 && index != 2)){
            invalidInput = true;
            break;
          } else {
            if (index == 1){
              if (input.at(0) >= '0' && input.at(0) <= '9' && input.at(2) >= '0' && input.at(2) <= '9' && input.at(3) >= '0' && input.at(3) <= '9'){
                mult = input.at(0) - '0';
                add = stoi(input.substr(2, 2));
              } else {
                invalidInput = true;
                break;
              }
            } else if (index == 2){
              if (input.at(0) >= '0' && input.at(0) <= '9' && input.at(1) >= '0' && input.at(1) <= '9' && input.at(3) >= '0' && input.at(3) <= '9') {
                mult = stoi(input.substr(0, 2));
                add = input.at(3) - '0';
              } else {
                invalidInput = true;
                break;
              }
            }
          }
        } else if (input.length() == 5){
          if (input.at(0) >= '0' && input.at(0) <= '9' && input.at(1) >= '0' && input.at(1) <= '9' && input.at(2) == ' ' && input.at(3) >= '0' && input.at(3) <= '9' && input.at(4) >= '0' && input.at(4) <= '9'){

            mult = stoi(input.substr(0, 2));
            add = stoi(input.substr(2, 2));
            
          } else {
            invalidInput = true;
            break;
          }
        }

        if (add < 0 || add > 25){
          falseNum = true;
          break;
        }
        if (mult != 1 && mult != 3 && mult != 5 && mult != 7 && mult != 9 && mult != 11 && mult != 15 && mult != 17 && mult != 19 && mult != 21 && mult != 23 && mult != 25){
          falseNum = true;
          break;
        }

        while (true){
          
          clear_screen();

          cout << "      Perfect! Now, I'll ask for your message. You may include numbers, capital letters, spaces, and special characters (however, they must NOT go over 8 bits of memory, there is NO error condition, and I WILL break). I should preface, the encrypted message will be given back in all capital letters." << endl << "      Currently, special codes will not work. Dearest apologies." << endl << "      Type in your message now." << endl << endl;
          
          if (invalidInput){
            cout << "      That is not a valid message. Read the instructions again." << endl;
          }
          
          invalidInput = false;

          string unMess;
          getline(cin, unMess);

          char enMess[unMess.length()];

          for (int i = 0; i < unMess.length(); i++){
            if(unMess.at(i) <= 'z' && unMess.at(i) >= 'a'){
              enMess[i] = (((unMess.at(i) - 'a') * mult + add) % 26) + 'A';
            } else if (unMess.at(i) <= 'Z' && unMess.at(i) >= 'A'){
              enMess[i] = (((unMess.at(i) - 'A') * mult + add) % 26) + 'A';
            } else {
              enMess[i] = unMess.at(i);
            }
          }

          clear_screen();

          cout << "      Your encrypted message is...";
          cout << endl << endl << endl << endl << "      ";
          for (int i = 0; i < unMess.length(); i++){
            cout << enMess[i];
          }
          cout << endl << endl << endl << endl << "      Now isn't that beautiful? Just let me know when you're ready to return to the main screen. " << endl << endl << "      Continue? ";
          string con;
          getline(cin, con);
          return 1;
        }
      }
    }
  }

  int affine_cipher_decode(int &cipher){

    bool secondTime = false;
    bool invalidInput = false;
    bool returnQuestion = false;
    bool falseNum = false;

    while (true){
      while (true){
        clear_screen();
        if (!returnQuestion && !invalidInput && !falseNum){
            cout << "      Excellent choice." << endl;
          } else if (returnQuestion){
            cout << "      Welcome back. I trust Al answered all questions you may have had." << endl;
          } else if (invalidInput){
            cout << "      That is not a valid input, darling. Please review my instructions for passing keys over." << endl;
          } else if (falseNum){
            cout << "      Ooh, this is a tricky error. It seems you may have inputted numbers that would result in a faulty cipher (either that or you didn't pass your keys correctly). Please visit this website if you are not sure which keys will and will not result in acceptable codes: 'https://crypto.interactive-maths.com/affine-cipher.html'." << endl;
          }
          returnQuestion = false;
          invalidInput = false;
    
          cout << "      May I ask you for the key you want to decode with?" << endl << "      To pass it over, type something like, '1 2' or '3 4', where the first integer is the multiplication key and the second integer is the addition shift, and they are seperated by a space." << endl << endl;
    
          string input;
          getline(cin, input);
    
          if (input.length() == 1 && input.at(0) == '?'){
            question("Preston");
            returnQuestion = true;
            break;
          } else if (input.length() == 5 && input == "Code1"){
            clear_screen();
            cout << "      You're already inside the Affine cipher, silly. Let's proceed back to select your key, hm?" << endl << endl << "      Return to key selection? ";
            string con;
            getline(cin, con);
            break;
            
          } else if (input.length() == 5 && input == "Code2"){
            cipher = 2;
            return 2;
          } else if (input.length() == 5 && input == "Code3"){
            cipher = 3;
            return 3;
          }
  
          if (input.length() < 3 || input.length() > 5){
            invalidInput = true;
            break;
          }
  
          int mult;
          int add;
  
          if (input.length() == 3){
            if ((input.at(0) >= '0' && input.at(0) <= '9') && input.at(1) == ' ' && (input.at(2) >= '0' && input.at(2) <= '9')){
              mult = input.at(0) - '0';
              add = input.at(2) - '0';
            } else {
              invalidInput = true;
              break;
            }
          } else if (input.length() == 4){
            bool found = false;
            int index;
            for (int i = 0; i < input.length(); i++){
              if (input.at(i) == ' '){
                index = i;
                found = true;
              }
            }  
            if (!found || (index != 1 && index != 2)){
              invalidInput = true;
              break;
            } else {
              if (index == 1){
                if (input.at(0) >= '0' && input.at(0) <= '9' && input.at(2) >= '0' && input.at(2) <= '9' && input.at(3) >= '0' && input.at(3) <= '9'){
                  mult = input.at(0) - '0';
                  add = stoi(input.substr(2, 2));
                } else {
                  invalidInput = true;
                  break;
                }
              } else if (index == 2){
                if (input.at(0) >= '0' && input.at(0) <= '9' && input.at(1) >= '0' && input.at(1) <= '9' && input.at(3) >= '0' && input.at(3) <= '9') {
                  mult = stoi(input.substr(0, 2));
                  add = input.at(3) - '0';
                } else {
                  invalidInput = true;
                  break;
                }
              }
            }
          } else if (input.length() == 5){
            if ((input.at(0) >= '0' && input.at(0) <= '9') && (input.at(1) >= '0' && input.at(1) <= '9') && input.at(2) == ' ' && (input.at(3) >= '0' && input.at(3) <= '9') && (input.at(4) >= '0' && input.at(4) <= '9')){
  
              mult = stoi(input.substr(0, 2));
              add = stoi(input.substr(2, 2));
              
            } else {
              invalidInput = true;
              break;
            }
          }
  
          if (add < 0 || add > 25){
            falseNum = true;
            break;
          }
          if (mult != 1 && mult != 3 && mult != 5 && mult != 7 && mult != 9 && mult != 11 && mult != 15 && mult != 17 && mult != 19 && mult != 21 && mult != 23 && mult != 25){
            falseNum = true;
            break;
          }
  
          while (true){
          
            clear_screen();

            cout << "      Perfect! Now, I'll ask for your message. You may include numbers, capital letters, spaces, and special characters (however, they must NOT go over 8 bits of memory, there is NO error condition, and I WILL break). I should preface, the decrypted message will be given back in all capital letters." << endl << "      Also, currently, special codes will not work. My condolences." << endl << "      Type in your message now." << endl << endl;
          
            if (invalidInput){
              cout << "      That is not a valid message. Read the instructions again." << endl;
            }
          
            invalidInput = false;

            string enMess;
            getline(cin, enMess);

            char unMess[enMess.length()];

            int modInverse;


            switch (mult){
              case 1:
                modInverse = 1;
                break;
              case 3:
                modInverse = 9;
                break;
              case 5:
                modInverse = 21;
                break;
              case 7:
                modInverse = 15;
                break;
              case 9:
                modInverse = 3;
                break;
              case 11:
                modInverse = 19;
                break;
              case 15:
                modInverse = 7;
                break;
              case 17:
                modInverse = 23;
                break;
              case 19:
                modInverse = 11;
                break;
              case 21:
                modInverse = 5;
                break;
              case 23:
                modInverse = 17;
                break;
              case 25:
                modInverse = 25;
                break;
            }
            

            for (int i = 0; i < enMess.length(); i++){
              if (enMess.at(i) >= 'a' && enMess.at(i) <= 'z'){
                unMess[i] = modInverse * ((enMess.at(i) - 'a') + (26 - add)) % 26 + 'A';
                //unMess[i] = ((modInverse * (enMess.at(i) - 'a')) - (modInverse * add)) % 26 + 'A';
                //unMess[i] = (modInverse * (enMess.at(i) - 'a') + add) % 26 + 'A';
                //unMess[i] = ((modInverse * ((enMess.at(i) - 'a') - add)) % 26) + 'A';
                /*int modInverse;
                int sum = 0;
                for (int j = 0; sum % 26 != 1; j++){
                  modInverse = j;
                  sum = mult * j;
                }
                unMess[i] = ((modInverse * (enMess.at(i) - 'a')) - (modInverse * add)) % 26 + 'A'; */
                
              } else if (enMess.at(i) >= 'A' && enMess.at(i) <= 'Z'){
                unMess[i] = modInverse * ((enMess.at(i) - 'A') + (26 - add)) % 26 + 'A';
                //unMess[i] = (modInverse * (enMess.at(i) - 'A') + add) % 26 + 'A';
                //unMess[i] = ((modInverse * ((enMess.at(i) - 'A') - add)) % 26) + 'A';
                //unMess[i] = ((modInverse * (enMess.at(i) - 'A')) - (modInverse * add)) % 26 + 'A';
              /*  int modInverse;
                int sum = 0;
                for (int j = 0; sum % 26 != 1; j++){
                  modInverse = j;
                  sum = mult * j;
                }
                unMess[i] = ((modInverse * (enMess.at(i) - 'A')) - (modInverse * add)) % 26 + 'A'; */
              } else {
                unMess[i] = enMess.at(i);
              }
            }

            cout << "      Your decrypted message is..." << endl << endl << endl << endl;
            for (int i = 0; i < enMess.length(); i++){
              cout << unMess[i];
            }
            cout << endl << endl << endl << endl << "      Isn't it beautiful? Let me know when you're ready to return to the Affine Cipher main screen." << endl << endl << "      Continue? ";
            string con;
            getline(cin, con);
            return 1;
            
          }
      }
      
    }
    
  }

}