#include <string>
#include "AirlineTicket.h"
#include <iostream>
#include <memory>

//constructor initializer
AirlineTicket::AirlineTicket()
    : mPassengerName("Unknown Passenger")
    , mNumberOfMiles(0)
    , mHasEliteSuperRewardsStatus(false)
{
}

AirlineTicket::~AirlineTicket()
{
    
}

const std::string& AirlineTicket::getPassengerName() const
{
    return mPassengerName;
}

void AirlineTicket::setPassengerName(const std::string& name)
{
    mPassengerName = name;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
    return mHasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
    mHasEliteSuperRewardsStatus = status;
}

int AirlineTicket::getNumberOfMiles() const
{
    return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles){
    mNumberOfMiles = miles;
}

double AirlineTicket::calculatePriceInDollars() const
{
    if (hasEliteSuperRewardsStatus()){
        return 0;
    }

    return getNumberOfMiles() * 0.1;
}

int main(){
AirlineTicket myTicket;  // Stack-based AirlineTicket
myTicket.setPassengerName("Sherman T. Socketwrench");
myTicket.setNumberOfMiles(700);
std::cout << "get number of miles " << myTicket.getNumberOfMiles() << std::endl;
double cost = myTicket.calculatePriceInDollars();
std::cout << "This ticket will cost $" << cost << std::endl;

// Heap-based AirlineTicket with smart pointer
auto myTicket2 = std::make_unique<AirlineTicket>();
myTicket2->setPassengerName("Laudimore M. Hallidue");
myTicket2->setNumberOfMiles(2000);
myTicket2->setHasEliteSuperRewardsStatus(true);
double cost2 = myTicket2->calculatePriceInDollars();
std::cout << "This other ticket will cost $" << cost2 << std::endl;
// No need to delete myTicket2, happens automatically
    return 0;
}

