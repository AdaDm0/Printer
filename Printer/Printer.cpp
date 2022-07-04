// Printer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "User.h"
#include "QueuePrint.h"


/*Разработать приложение, имитирующее очередь печати принтера. Должны быть клиенты, посылающие
запросы на принтер, у каждого из которых есть свой приоритет. Каждый новый клиент попадает в очередь
в зависимости от своего приоритета. Необходимо сохранять статистику печати (пользователь, время)
в отдельной очереди. Предусмотреть вывод статистики на экран.*/


int main()
{
    User boss(1);
    User secretary(2);
    User mesto1(3);
    User mesto2(3);
    QueuePrint Printer;
    secretary.addUserQueue("S1. A really busy person never knows how much he weighs.");
    secretary.addUserQueue("S2. A dream is just a dream. A goal is a dream with a plan and a deadline.");
    mesto1.addUserQueue("M1. It isn't the mountains ahead to climb that wear you out; it's the pebble in your shoe.");
    mesto2.addUserQueue("I'm tired and want to go home.");
    boss.addUserQueue("Boss. When two men in business always agree, one of them is unnecessary.");
    boss.addUserQueue("Boss. A man is judged by what he spends, not by what he earns.");
    boss.addUserQueue("Boss. When the eagles are silent, the parrots begin to jabber.");
    boss.addUserQueue("I have never let my schooling interfere with my education.");
    boss.printAll();
    boss.printQueueLength();
    boss.deleteDoc(1);
    boss.printAll();
    boss.printQueueLength();
    cout << "\n\n";
    secretary.printQueueLength();
    mesto1.printQueueLength();
    mesto2.printQueueLength();


    



    
}

