#include <iostream>
#include <fstream>
using namespace std;

 //Hashing Program

string hashString(const string& input) {
  // Using std::hash function to hash the input string
  size_t hashValue = hash<string>()(input);

  // Convert hash value to string
  return to_string(hashValue);
}

int main () {
    //Declarations
    string username;
    string password;
    string request;
    string ans1, ans2, ans3;
    string fileans1, fileans2, fileans3;
    string fileUsername, filePassword;
    ifstream inFile;
    ifstream inFile2;
    ofstream outFile;

    //Open Files
    inFile.open ("login.txt");
    if (!inFile) {
        cout << " Cannot read file. " << endl;
    } 

    //Retrieve data from file
    for (int a = 0; a < 1; a++) {
        cout << "Do you have a login? ";
        cin >> request;
        while ((request !="yes")||(request !="Yes")||(request !="YES")){
            if ((request =="yes")||(request =="Yes")||(request =="YES")){
                break;
            } else; {
                cout << "You must have a login to proceed" << endl;
                cout << "Do you have a login? ";
                cin >> request;
            }
        }
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter a your password: ";
        cin >> password;
        string hashed = hashString(password);


        inFile >> fileUsername >> filePassword >> fileans1 >> fileans2 >> fileans3;

        while ((request =="yes")||(request =="Yes")||(request =="YES")){  
            if (username == fileUsername){
                if (hashed == filePassword){
                cout << "Verifying data. Please wait..." << endl;
                cout << "Username and Password worked" << endl;
                break;
                } else {
                    cout << "Verifying data. Please wait..." << endl;
                    cout << "Username and Password didn't work " << endl;
                }
            } else {
                cout << "Verifying data. Please wait..." << endl;
                cout << "Username and Password didn't work " << endl;
            }
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            hashed = hashString(password);
        } 

        cout << "SECURITY QUESTIONS" << endl;

       //Close the first file
           inFile.close();

           //Open second file
           inFile2.open ("questions.txt");
               if (!inFile2) {
                   cout << " Can not read file " << endl;
               }

      //Questions and Answers
       while (inFile2) {
            cout << " What planet do we live on? ";
            cin >> ans1;
            cout << " What do apples grow on? ";
            cin >> ans2;
            cout << " What color is the sky? ";
            cin >> ans3;
            string hashed1 = hashString(ans1);
            string hashed2 = hashString(ans2);
            string hashed3 = hashString(ans3);

            inFile2 >> fileans1 >> fileans2 >> fileans3;
                if (hashed1 != fileans1 || hashed2 != fileans2 || hashed3 != fileans3) {
                    cout << " Incorrect answer. Try again. (You only get one more attempt)"<< endl;
                    continue; 
                } else {
                    cout << " Congratulations! You have successfull logged in. " << endl;
                    break;
                }
        }
    }
    return 0;
}