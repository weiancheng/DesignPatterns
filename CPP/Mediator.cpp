#include <iostream>
#include <vector>

enum EService {
    E_Service_Room = 0,
    E_Service_MorningCall = 1,
    E_Service_Reservation = 2,
    E_Service_Fitness = 3,
};

class IService {
public:
    IService(EService eservice) {
        mService = eservice;
    }

    ~IService() {}

    virtual void setPrice(int cost) {
        mPrice = cost;
    }

    virtual void doService(void) = 0;
    virtual void getInformation(void) = 0;
    virtual EService checkService(void) {
        return mService;
    }

protected:
    int mPrice;
    EService mService;
};

class RoomService : public IService {
public:
    RoomService(EService es) : IService(es) {}

    virtual void doService(void) {
        std::cout << "This is Room Service ..." << std::endl;
    }

    virtual void getInformation(void) {
        std::cout << "Room Service need $" << mPrice << std::endl;
    }
};

class MorningCallService : public IService {
public:
    MorningCallService(EService es) : IService(es) {}

    virtual void doService(void) {
        std::cout << "Morning Call Service ..." << std::endl;
    }

    virtual void getInformation(void) {
        std::cout << "Morning Call Service need $" << mPrice << std::endl;
    }
};

class Reservation : public IService {
public:
    Reservation(EService es) : IService(es) {}

    virtual void doService(void) {
        std::cout << "Reservation, what can I help you?" << std::endl;
    }

    virtual void getInformation(void) {
        std::cout << "Reservation Service need $" << mPrice << std::endl;
    }
};

class Fitness : public IService {
public:
    Fitness(EService es) : IService(es) {}

    virtual void doService(void) {
        std::cout << "Fitness Room, you would get relaxed here..." << std::endl;
    }

    virtual void getInformation(void) {
        std::cout << "Fitness Room need $" << mPrice << std::endl;
    }
};


class IFrontDesk {
public:
    ~IFrontDesk() {}

    virtual void registerService(IService *service) {
        mServices.push_back(service);
    }

    virtual void callService(EService service) = 0;

protected:
    std::vector<IService *> mServices;
};

class FrontDesk : public IFrontDesk {
public:
    virtual void callService(EService service) {
        for (int i = 0; i < mServices.size(); ++i) {
            if(mServices[i]->checkService() == service) {
                mServices[i]->getInformation();
                mServices[i]->doService();
            }
        }
    }

    ~FrontDesk() {
        std::vector<IService *>::iterator it;
        for(it = mServices.begin() ; it != mServices.end() ; it++) {
            mServices.erase(it);
        }
    }
};

int main(int argc, char ** argv) {
    IService *room = new RoomService(E_Service_Room);
    room->setPrice(5);

    IService *fitness = new Fitness(E_Service_Fitness);
    fitness->setPrice(10);

    IService *morning_call = new MorningCallService(E_Service_MorningCall);
    morning_call->setPrice(1);

    IService *reservation = new Reservation(E_Service_Reservation);
    reservation->setPrice(2);

    IFrontDesk *front_dest = new FrontDesk();
    front_dest->registerService(room);
    front_dest->registerService(fitness);
    front_dest->registerService(morning_call);
    front_dest->registerService(reservation);

    front_dest->callService(E_Service_Fitness);

    delete front_dest;

    return 0;
}