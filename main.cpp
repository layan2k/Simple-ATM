#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class atm    // class atm
{
private:
    long int account_No;   //private attribute variable
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:   // public attribute funtions

    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a){
        account_No = account_No_a;          // Set Account Details
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    // Get Details
    long int getAccountNo(){
        return account_No;
    }
    string getName(){
        return name;
    }
    int getPIN(){
        return PIN;
    }
    double getBalance(){
        return balance;
    }
    string getMoblile(){
        return mobile_No;
    }
    // Update Mobile public function/method
    void setMobile(string mob_prev, string mob_new){
        if (mob_prev == mobile_No){
            mobile_No = mob_new;

            cout << "Mobile Number Updated" << endl;
            _getch();
        }
        else{
            cout << " Incorrect , Please Enter Old Number " << endl;
            _getch();
        }
    }
    // Cash Withdrawal Method
    void cashWithdrawal(int amount_a){
        if(amount_a > 0 && amount_a < balance){
            balance -= amount_a;
            cout << "Please Collect You Cash" << endl;
            cout << "Available Balance: " << balance << endl;
            _getch();
        }
        else{
            cout << " Invalid Input or Insufficient Balance" << endl;
            _getch();
        }
    }

};
////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");
    atm user1;

    user1.setData(1234567, "Leslie", 1234, 60000.60, "123456789");

    do{
        system("cls");
        cout << "Welcome to Moola Bank" << endl;
        cout << "Enter Account No" << endl;
        cin >> enterAccountNo;
        cout << "Enter PIN" << endl;
        cin >> enterPIN;

        // check if account number matches with user 1 details
        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do{
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                // UI
                cout << "Welcome to Moola Bank" << endl;
                cout << "Select Options" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdrawal" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile no." << endl;
                cout << "5. Exit." << endl;
                cin >> choice;

                //  Switch Statement for choices
                switch (choice){
                    case 1:
                    cout << "Your Bank Balance is : " << user1.getBalance();

                    _getch();
                    break;

                    case 2:
                    cout << "Enter Amount : " << endl;
                    cin >> amount;
                    user1.cashWithdrawal(amount);
                    break;

                    case 3:
                    cout << "User Details:-" << endl;
                    cout << "Account No:-" << user1.getAccountNo() << endl;
                    cout << "Name :-" << user1.getName()<< endl;
                    cout << "Mobile No:-" << user1.getMoblile()<< endl;
                    _getch();
                    break;

                    case 4:
                    cout << "Enter Old Number." << endl;
                    cin >> oldMobileNo;
                    cout << "Enter New Number." << endl;
                    cin >> newMobileNo;
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                    case 5:
                    exit(0);

                    default:
                    cout << "Enter Valid Input" << endl;

                }




            }while (1);
        }

    }
    while (1);

return 0;
}
