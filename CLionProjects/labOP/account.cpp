#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class account{
private:
    string nameBank;
    long long number;
    double amountMoney;
public:
    account(int amount){
        amountMoney = amount;
        nameBank = "Приват";
        static long long number_ = 5168000000000000-15;
        number = number_++;
    }
    account(){}
    void addMoney(double amount){
        amountMoney += amount;
    }
    void takeMoney(double amount){
        if(amountMoney>=amount){
            amountMoney -= amount;
            cout<<"Гроші знято."<<endl;
        }else{
            cout<<"Недостатньо коштів на рахунку"<<endl;
        }
    }
    long long getNumber(){
        return number;
    }
};
class deposit:public account{
private:
    int creatingDay;
    int creatingMonth;
    int creatingYear;
    int termMonths;
    int rate;
    double moneyAmount;
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int nowMonth = now->tm_mon+1;
    int idDep;
    bool isActive=false;
public:
    deposit(int term, int rate, double amount, int indexAccount){
        isActive = true;
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        creatingDay = now->tm_mday;
        creatingMonth = now->tm_mon+1;
        creatingYear = now->tm_year+1900;
        termMonths = term;
        this->rate = rate;
        moneyAmount = amount;
        idDep = indexAccount;
    }
    double remittance(){
        if(nowMonth==(creatingMonth+termMonths)){
            double res = ((moneyAmount*rate/100)/12)+moneyAmount;
            moneyAmount = 0;
            isActive = false;
            return res;
        }
        return (moneyAmount*rate/100)/12;
    }
    int skipMonth(){
        double res = (moneyAmount*rate/100)/12;
        addMoney(res);
        static int nowMonth_=nowMonth;
        //nowMonth = nowMonth_++;
        nowMonth += 1;
        if(nowMonth==(creatingMonth+termMonths)) {
            //addMoney(moneyAmount);
            //moneyAmount=0;
            cout<<"Депозит закрито. На карту перечислено "<<moneyAmount<<"$"<<endl;
        }
        return idDep;
    }
    deposit(){}
    double getMoneyAmount(){
        return moneyAmount;
    }
    bool getIsActive(){
        return isActive;
    }
    void printInfo(){
        cout<<"\tСума вкладу: "<<moneyAmount<<"\n\tДата відкриття: "<<creatingDay<<"-"<<
            creatingMonth<<"-"<<creatingYear<<"\n\tТермін: "<<termMonths<<" місяців"<<endl;
        cout<<"\tРічні відсотки: "<<rate<<"\n\tСума після закриття депозиту: ";
        cout<<moneyAmount+(moneyAmount*rate/100)*termMonths/12<<endl;
    }
    int getIdDep(){
        return idDep;
    }
};
class currentAccount:public account{
private:
    string lastOperationDay;
    int nowMonth;
    int nowYear;
    double moneyAmount;
    bool isActive=false;
    int idCard;
public:
    currentAccount(int amount) : account(amount){
        static int idCard_= 0;
        idCard = idCard_++;
        moneyAmount = amount;
        //account();
        isActive=true;
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        nowMonth = now->tm_mon+1;
        nowYear = now->tm_year+1900;
        lastOperationDay = to_string(now->tm_mday) + "-" + to_string(now->tm_mon+1)+'-'+to_string(now->tm_year+1900);
    }
    int getId(){
        return idCard;
    }
    bool getIsActive(){
        return isActive;
    }
    currentAccount(){}
    void takeMoney(){
        int sum;
        cout<<"Скільки грошей хочете зняти:";
        cin>>sum;
        if(sum<0 || sum>50000){
            cout<<"Ви можете зняти від 0 до 50 000$"
                  ". Якщо не хочете знімати, натисніть 0."<<endl;
            takeMoney();
        }
        if(sum>moneyAmount){
            cout<<"Недостатньо коштів. Спробуйте ще раз або натисніть 0."<<endl;
            takeMoney();
        }
        moneyAmount -= sum;
        account::takeMoney(sum);
    }
    void addMoney(){
        int sum;
        cout<<"Скільки грошей хочете додати:";
        cin>>sum;
        if(sum<0 || sum>50000){
            cout<<"Ви можете внести від 0 до 50 000$"
                  ". Якщо не хочете вносити кошти, натисніть 0."<<endl;
            addMoney();
        }else{
            moneyAmount += sum;
            account::addMoney(sum);
            lastOperationDay = to_string(nowMonth);
        }
    }
    void addMoney(double amount){
        moneyAmount += amount;
        lastOperationDay = to_string(nowMonth);
    }
    deposit createDeposit(int indexAccount){
        while(true) {
            double amount;
            cout << "Введіть суму вкладу в депозит:";
            cin >> amount;
            if(amount>moneyAmount){
                cout<<"Недостатньо коштів. Максимальний можливий депозит на "<<moneyAmount<<"$"<<endl;
                continue;
            }
            int rate;
            cout << "Введіть відсоток річних нарахувань:";
            cin >> rate;
            if (rate > 15) {
                cout << "Завеликий відсоток. Майте совість. Спробуйте ще раз" << endl;
                continue;
            }else if(rate<1){
                cout<<"Відсоток депозиту від 1 до 15. Спробуйте ще раз"<<endl;
                continue;
            }
            int term;
            cout << "Введіть термін депозиту:";
            cin >> term;
            if(term>24 || term<3){
                cout<<"Термін має бути від 3 до 24 місяців. Спробуйте ще раз."<<endl;
                continue;
            }
            moneyAmount -= amount;
            return deposit(term, rate, amount, idCard);
        }
    }
    double getMoneyAmount(){
        return moneyAmount;
    }
    void printInfo(){
        cout<<"Номер картки "<<account::getNumber()<<"\nОстання операція - "<<lastOperationDay<<endl;
        cout<<"Баланс: "<<moneyAmount<<endl;
    }
    string getLastOperationDay(){
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        return "Дата останньої операції обраної карти -> "+to_string(now->tm_mday)+"-"+ to_string(nowMonth)+"-"+ to_string(nowYear);
    }
    void skipMonth(){
        if(nowMonth==12){
            nowMonth = 1;
            nowYear++;
        }else {
            nowMonth++;
        }
    }
};