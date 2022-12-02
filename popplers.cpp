//Author: Logan Markley
//Assignment: HW4 (Queue)
//Class: CS1575
//Semester: Fall 2022
//Due Date: Fri, 12/2/22

#include "line.hpp"
#include "customer.hpp"
#include "randomengine.h"
#include <iostream>
using namespace std;

int main()
{
    randomEngine random;
    
    int numCustomers=0;
    cin >> numCustomers;
    Line<Customer> l(numCustomers);
    
    for(int i=0; i<numCustomers; i++)
    {
        string name = "";
        int popplersRequested = 0;
        cin >> name;
        cin >> popplersRequested;
        Customer person(name, popplersRequested);
        l.enqueue(person);
    }
    //cout << endl << "Initial: " << l << endl << endl; //to print the line
    
    
    int mostPopplersAmount = 0; //temporary set to the front customer. Updates throughout each iteration
    string mostPopplersName = l.front().getName(); 
    int leastPopplersAmount = 100; //random big number
    string leastPopplersName = l.front().getName(); 
    
    int popplersAteByEverybody = 0;
    while( l.isEmpty() == false ) //every iteration of this loop encompasses one customer buying and eating popplers and the line moving positions
    {
        int numPopplersRequested = l.front().getPopplersRequested();
	int setsOfPopplersToEat = 0;
	if(numPopplersRequested % 5 == 0)
        	setsOfPopplersToEat = numPopplersRequested / 5;
        else
		setsOfPopplersToEat = numPopplersRequested / 5 + 1;

        int popplersEaten = 0;
        int extraPopplersWanted = 0;
        while(popplersEaten < setsOfPopplersToEat * 5)
        {
            popplersEaten++;
            if(random.rollD(6)==6)
                extraPopplersWanted++;
        }
        
        l.retrieve(0).addToTotalPopplersEaten(popplersEaten); //customer's individual total
        popplersAteByEverybody+=popplersEaten; //total for all customers
        
        if( l.front().getTotalPopplersEaten() > mostPopplersAmount ) //updates the ateTheMost values to whoever currently has ate the most
        {
            mostPopplersAmount = l.front().getTotalPopplersEaten();
            mostPopplersName = l.front().getName();
        }
        if( l.front().getTotalPopplersEaten() < leastPopplersAmount )//updates the ateTheLeast values to whoever currently has ate the least
        {
            leastPopplersAmount = l.front().getTotalPopplersEaten();
            leastPopplersName = l.front().getName();
        }

        if(extraPopplersWanted == 0)
        {
            cout << l.front().getName() << " eats " << popplersEaten << " popplers. ";
            cout << l.front().getName() << " is satisfied after eating " << l.front().getTotalPopplersEaten() << " popplers." <<endl;
            l.dequeue();
        }
        else
        {
            cout << l.front().getName() << " eats " << popplersEaten << " popplers. ";
            cout << l.front().getName() << " wants " << extraPopplersWanted << " more poppler(s)!" <<endl;
            l.retrieve(0).updatePopplersRequested(extraPopplersWanted); //changes the popplers requested value for when they order again
            l.enqueue(l.front());
            l.dequeue(); //copies the customer to the back and then deletes them from the front
        }

        //cout << l << endl << endl; //to print the line
    }
    cout << endl << "A total of " << popplersAteByEverybody << " popplers were ate!" << endl;
    cout << mostPopplersName << " ate the most popplers with a total of " << mostPopplersAmount << "!" << endl;
    cout << leastPopplersName << " ate the least popplers with a total of " << leastPopplersAmount << "!" << endl;
    return 0;
}

