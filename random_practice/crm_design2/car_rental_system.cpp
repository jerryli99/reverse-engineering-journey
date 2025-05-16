#include <string>
#include <vector>

enum class BillItemType  {
    BaseCharge,
    AdditionalService,
    Fine,
    Other
};

enum class VehicleLogType {
    Accident,
    Fueling,
    CleaningService,
    OilChange,
    Repair,
    Other
};

enum class VanType {
    Passenger,
    Cargo
};

enum class CarType {
    Economy,
    Compact,
    Intermediate,
    Standard,
    FullSize,
    Premium,
    Luxury
};

enum class VehicleStatus {
    Available,
    Reserved,
    Loaned,
    Lost,
    BeingServiced,
    Other
};

enum class ReservationStatus {
    Waiting,
    Pending,
    Confirmed,
    Completed,
    Cancelled,
    None
};

enum class AccountStatus {
    Active,
    Closed,
    Canceled,
    Blacklisted,
    None
};

enum class PaymentStatus {
    Unpaid,
    Pending,
    Completed,
    Failed,
    Declined,
    Cancelled,
    Abandoned,
    Settling,
    Settled,
    Refunded
};

struct Location {
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipcode;
    std::string country;
};

struct Person {
    std::string name;
    std::string address;
    std::string email;
    std::string phone;
};

//+----------------------------------+
class CarRentalLocation {
    public:
        CarRentalLocation(std::string name, Location addr)
            : m_name{std::move(name)}, m_addr{std::move(addr)} {}
    
        Location get_location() {
            return m_addr;
        }
    
    private:
        std::string m_name;
        Location m_addr;
};
    
class CarRentalSystem {
    public:
        CarRentalSystem(std::string name)
            : m_name{std::move(name)} {}
    
    private:
        std::string m_name;
        std::vector<Location> m_locations;
};
    
//+----------------------------------+
class Account {
    public:

    private:

};

//+----------------------------------+
class SearchVehicles {
    
};