

#include <iostream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

class MovieTicket {
    static const int TOTAL_SLOTS = 100;

    // movieBookings[movieID] = set of customerIDs who booked it
    unordered_map<int, set<int>> movieBookings;

    // soldCount[movieID] = number of tickets booked
    unordered_map<int, int> soldCount;

public:
    // BOOK X Y: customer X books movie Y
    bool BOOK(int customerID, int movieID) {
        // Already booked by same customer
        if (movieBookings[movieID].count(customerID))
            return false;

        // Movie is sold out
        if (soldCount[movieID] >= TOTAL_SLOTS)
            return false;

        // Book the ticket
        movieBookings[movieID].insert(customerID);
        soldCount[movieID]++;
        return true;
    }

    // CANCEL X Y: customer X cancels movie Y
    bool CANCEL(int customerID, int movieID) {
        // Customer has not booked this movie
        if (!movieBookings[movieID].count(customerID))
            return false;

        // Cancel the booking
        movieBookings[movieID].erase(customerID);
        soldCount[movieID]--;
        return true;
    }

    // IS_BOOKED X Y: check if customer X booked movie Y
    bool IS_BOOKED(int customerID, int movieID) {
        return movieBookings[movieID].count(customerID) > 0;
    }

    // AVAILABLE_TICKETS Y: remaining tickets for movie Y
    int AVAILABLE_TICKETS(int movieID) {
        return TOTAL_SLOTS - soldCount[movieID];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    cin.ignore();

    MovieTicket mt;

    while (Q--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        string query;
        iss >> query;

        if (query == "BOOK") {
            int x, y;
            iss >> x >> y;
            cout << (mt.BOOK(x, y) ? "true" : "false") << "\n";

        } else if (query == "CANCEL") {
            int x, y;
            iss >> x >> y;
            cout << (mt.CANCEL(x, y) ? "true" : "false") << "\n";

        } else if (query == "IS_BOOKED") {
            int x, y;
            iss >> x >> y;
            cout << (mt.IS_BOOKED(x, y) ? "true" : "false") << "\n";

        } else if (query == "AVAILABLE_TICKETS") {
            int y;
            iss >> y;
            cout << mt.AVAILABLE_TICKETS(y) << "\n";
        }
    }

    return 0;
}
