#include "mylib.h"
int takeAction(){
    cout<<"Оберіть дію:\n\t"
          "1->Створити рахунок\n\t"
          "2->Створити депозит\n\t"
          "3->Переглянути дані рахунків\n\t"
          "4->Переглянути наявні депозити\n\t"
          "5->Зняти кошти\n\t"
          "6->Поповнити картку\n\t"
          "7->Дата останньої операції\n\t"
          "8->Пропустити місяць\n\t"
          "9->Закінчити взаємодію\n"
          "P.S. Для кожної операції, крім 1 і 4 вам доведеться обрати рахунок серед наявних."
          "Якщо не існує, створити.\nВведіть номер дії:";
    int res;
    cin>>res;
    return res;
}
currentAccount createAccount(){
    while(true) {
        cout << "Скільки коштів хочете покласти при створенні рахунку:";
        int amount;
        cin >> amount;
        if(amount>=0 && amount<100000){
            return currentAccount(amount);
        }else{
            cout<<"Сума коштів має бути від 0 до 100 000. Спробуйте ще раз."<<endl;
        }
    }
}
int takeNumAccount(currentAccount accounts[6]){
    while(true) {
        cout << "Доступні картки та кількість коштів на них:" << endl;
        int i = 0;
        while (accounts[i].getIsActive() == true) {
            cout << "Рахунок " << i + 1 << ": " << accounts[i].getMoneyAmount() << "$" << endl;
            i++;
        }
        cout << "        0: Повернутися в меню." << endl;
        cout << "Оберіть номер рахунку для виконання дії:";
        int res;
        cin >> res;
        if (res > i || res < 0) {
            cout << "Оберіть картку серед доступних." << endl;
            continue;
        }
        return res;
    }
}
int takeNumDeposit(deposit deposits[10]){
    cout<<"Доступні депозити та сума вкладів на них:"<<endl;
    int i=0;
    while(deposits[i].getIsActive()==true){
        cout<<"Депозит "<<i+1<<": "<<deposits[i].getMoneyAmount()<<"$"<<endl;
        i++;
    }
    cout<<"        0:Повернутися в меню."<<endl;
    cout<<"Оберіть депозит для виконання дії:";
    int res;
    cin>>res;
    if(res>(i+1) || res<0){
        cout<<"Оберіть депозит серед доступних."<<endl;
        takeNumDeposit(deposits);
    }
    return res;
}