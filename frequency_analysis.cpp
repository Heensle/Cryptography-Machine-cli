#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

#include "intermediary_functions.h"
#include "screen_functions.h"

using namespace IntermediaryFunctions;
using namespace ScreenFunctions;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;
using std::fixed;
using std::setprecision;

namespace FrequencyAnalysis{

  int frequency_analysis(int &cipher){

    bool noText = false;
    bool invalidInput = false;
    bool lowercase = false;
    
    while (true){
      while(true){
        clear_screen();
        if (invalidInput){
          cout << "     Wait A Second... There Is No Text There!" << endl << "      Rebooting..." << endl << endl;
        } else if (noText){
          cout << "      Wait A Second... There Are No Letters In Your Message. I Cannot Analyze A Message With No Letters." << endl << "      Rebooting..." << endl << endl;
        } else if (lowercase){
          cout << "      Wait A Second... You Used LowerCase Letters. I Told You Not To Use LowerCase Letters!" << endl << "      Rebooting..." << endl << endl;
        }
        invalidInput = false;
        noText = false;
        lowercase = false;
        cout << "      Beep. Beep. Hello, Human! My Name Is SmileBot :). It's Very Good To See You. I Don't Get Many Visitors. Beep. Beep." << endl << "      Please Enter In The Text You Want To Analyze. Please Only Use Capital Letters. Beep." << endl << endl;
        string input;
        getline(cin, input);
  
        if (input == "?"){
          question("SmileBot");
          break;
        } else if (input == "Code1"){
          cipher = 1;
          return 1;
        } else if (input == "Code2"){
          cipher = 2;
          return 2;
        } else if (input == "Code3"){
          clear_screen();
          cout << "      Wait A Second... That Codes For Here. Stupid Human. Code3 Is For Frequency_Analysis. Code1 Is for Affine_Cipher. Code2 Is For Ceaser_Cipher. With Andy. I Love Andy." << endl << "      Ahem. Let's Go Back To The Main Screen." << endl << endl << "      Continue? ";
          string con;
          getline(cin, con);
          break;
        } else if (input.length() == 0){
          invalidInput = true;
          break;
        } else {
          bool found = false;
          lowercase = false;
          for (int i = 0; i < input.length(); i++){
            if (input.at(i) >= 'A' && input.at(i) <= 'Z'){
              found = true;
            }         
            if (input.at(i) >= 'a' && input.at(i) <= 'z'){
              lowercase = true;
            }
          }
          if (lowercase){
            break;
          }
          if (!found){
            noText = true;
            break;
          }
        }
        
        int frequency[26] = {};

        double total = 0;

        for (int i = 0; i < input.length(); i++){
          if (input.at(i) >= 'A' && input.at(i) <= 'Z'){
            frequency[input.at(i) - 'A']++;
            total++;
          }
        }

        char guesses[26];
        for (int i = 0; i < 26; i++){
          guesses[i] = ' ';
        }
  

        while (true){
          clear_screen();

          cout << "      Your Message:" << endl << endl << input << endl << endl << "      Frequency:" << endl << endl << fixed << setprecision(2);
          for (int i = 0; i < 26; i++){
            cout << char(i + 'A') << '-' << guesses[i] << "- ";
            for (int j = 0; j < frequency[i] / total * 50; j++){
              cout << "*";
            }
            cout << endl;
          }

          cout << endl << endl << "      Unencrypted Message:" << endl << endl;

          for (int i = 0; i < input.length(); i++){
            if (!(input.at(i) >= 'A' && input.at(i) <= 'Z')){
              cout << input.at(i);
            } else if (input.at(i) >- 'A' && input.at(i) <= 'Z'){
              if (guesses[input.at(i) - 'A'] == ' '){
                cout << '*';
              } else {
                cout << guesses[input.at(i) - 'A'];
              }
            }
          }

          cout << endl << endl;


          
          cout << endl << "      Beep. Beep. Enter In A Guess, Human. One At A Time, Please. Do It In This Format: 'letter_in_message:letter_guess'. For Example, If I Wanted To Guess That The Letter 'A' Was Really The Letter 'C', I Would Write: 'A:C'. Make Sure They Are Capital. If Nothing Happens After Your Guess, You Probably Did Something Wrong. I Can't Make Mistakes, But You Can." << endl << endl;
          
          string guess;
          getline(cin, guess);

          if (guess == "?"){
            question("SmileBot");
          } else if (guess == "Code1"){
            cipher = 1;
            return 1;
          } else if (guess == "Code2"){
            cipher = 2;
            return 2;
          } else if (guess.length() == 3){
            if (guess.at(0) >= 'A' && guess.at(0) <= 'Z' && guess.at(1) == ':' && guess.at(2) >= 'A' && guess.at(0) <= 'Z'){
              guesses[guess.at(0) - 'A'] = guess.at(2);
            }
          }
        }
      }
    }
  }








}