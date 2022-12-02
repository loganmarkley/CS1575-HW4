//Author: Logan Markley
//Assignment: HW4 (Queue)
//Class: CS1575
//Semester: Fall 2022
//Due Date: Fri, 12/2/22

#include <string>

using namespace std;

class Customer;

ostream& operator<<(ostream& os, const Customer& cust);

class Customer
{
  private:
  
    string m_name;
    int m_popplersRequested, m_totalPopplersEaten;
    
    
  public:
    
    Customer()
    {
        m_name="";
        m_popplersRequested=0;
        m_totalPopplersEaten=0;
    }
    
    Customer(const string n, const int popReq)
    {
        m_name = n;
        m_popplersRequested = popReq;
        m_totalPopplersEaten = 0;
    }
    
    void addToTotalPopplersEaten(int n)
    {
        m_totalPopplersEaten+=n;
        return;
    }
    
    void updatePopplersRequested(int n)
    {
        m_popplersRequested=n;
        return;
    }
    
    string getName() const
    {
        return m_name;
    }
    
    int getPopplersRequested() const
    {
        return m_popplersRequested;
    }
    
    int getTotalPopplersEaten() const
    {
        return m_totalPopplersEaten;
    }
    
    friend ostream& operator<<(ostream& os, const Customer& cust);
};


ostream& operator<<(ostream& os, const Customer& cust)
{
    os<<cust.m_name<<"-total:"<<cust.m_totalPopplersEaten;
    return os;
}
