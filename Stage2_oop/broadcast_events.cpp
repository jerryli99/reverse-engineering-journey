#include <iostream>
#include <vector>
#include <functional>

/*
This is to simulate C#'s delegates and event keywords
*/

class Event {
    public:
        void subscribe(std::function<void(const std::string&)> listener) {
            listeners.push_back(listener);
        }

        void trigger(const std::string& msg) {
            for(auto& listener : listeners) {
                listener(msg);
            }
        }

    private:
        std::vector<std::function<void(const std::string&)>> listeners;
};

int main() {
    Event onCustomerAdded;
    onCustomerAdded.subscribe([](const std::string& msg){
        std::cout << "[Logger]" << msg << std::endl;
    });
    
    onCustomerAdded.subscribe([](const std::string& msg){
        std::cout << "[Analytics] Logging customer event" << msg << std::endl;
    });

    onCustomerAdded.trigger("Customer Alice has been added");

    return (0);

}