#include <iostream>
#include "mylib.h"
using namespace std;
int main() {
    currentAccount accounts[6];
    deposit deposits[10];
    int accountsCounter = 0;
    int depositsCounter = 0;
    int i;
    while(true){
        int action = takeAction();
        int numAccount;
        switch(action){
            case 1:   //створити рахунок
                if(accountsCounter==5){
                    cout<<"Ви не можете створити більше 5 рахунків."<<endl;
                }else{
                    accounts[accountsCounter] = createAccount();
                    accountsCounter++;
                    cout<<"Рахунок створено успішно."<<endl;
                }
                break;
            case 2:   //створити депозит
                if(!accounts[0].getIsActive()) cout<<"У вас немає доступних рахунків для відкриття депозиту"<<endl;
                else if(depositsCounter==10) cout<<"Ви не можете створити більше 10 депозитів."<<endl;
                else {
                    numAccount = takeNumAccount(accounts);
                    if(numAccount==0) break;
                    deposits[depositsCounter] = accounts[numAccount - 1].createDeposit(numAccount-1);
                    depositsCounter++;
                }
                break;
            case 3:   //Вивести дані карток
                if(!accounts[0].getIsActive()) cout << "У вас немає доступних рахунків для відкриття депозиту" << endl;
                else{
                    numAccount = takeNumAccount(accounts);
                    if(numAccount==0) break;
                    accounts[numAccount-1].printInfo();
                    cout<<accounts[numAccount-1].getId()<<endl;
                }
                break;
            case 4:   //Переглянути депозити
                if(!deposits[0].getIsActive()) cout<<"У вас немає відкритих депозитів."<<endl;
                else{
                    numAccount = takeNumDeposit(deposits);
                    if(numAccount==0) break;
                    deposits[numAccount-1].printInfo();
                }
                break;
            case 5:   //Зняти кошти
                numAccount = takeNumAccount(accounts);
                if(numAccount==0) break;
                accounts[numAccount-1].takeMoney();
                break;
            case 6:   //Додати кошти
                numAccount = takeNumAccount(accounts);
                if(numAccount==0) break;
                accounts[numAccount-1].addMoney();
                break;
            case 7:   //Дата останньої операції
                numAccount = takeNumAccount(accounts);
                if(numAccount==0) break;
                cout<<accounts[numAccount-1].getLastOperationDay()<<endl;
                break;
            case 8:   //Проспати місяць
                i=0;
                while(deposits[i].getIsActive()){
                    deposits[i].skipMonth();
                    accounts[deposits[i].getIdDep()].addMoney(deposits[i].remittance());
                    i++;
                }
                i=0;
                while(accounts[i].getIsActive()){
                    accounts[i].skipMonth();
                    i++;
                }
                break;
            default:
                return 1;
        }
    }
}
