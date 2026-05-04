#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BookingRecord
{
    string customer;
    string movie;
};

class TicketManager
{
private:
    vector<BookingRecord> storage;

    int getOccupiedSeats(string mId)
    {
        int count = 0;
        for (int i = 0; i < storage.size(); i++)
        {
            if (storage[i].movie == mId)
            {
                count++;
            }
        }
        return count;
    }

public:
    void processBooking(string uId, string mId)
    {
        for (int i = 0; i < storage.size(); i++)
        {
            if (storage[i].customer == uId && storage[i].movie == mId)
            {
                cout << "false" << endl;
                return;
            }
        }

        if (getOccupiedSeats(mId) >= 100)
        {
            cout << "false" << endl;
            return;
        }

        BookingRecord record;
        record.customer = uId;
        record.movie = mId;
        storage.push_back(record);
        cout << "true" << endl;
    }

    void processCancellation(string uId, string mId)
    {
        for (int i = 0; i < storage.size(); i++)
        {
            if (storage[i].customer == uId && storage[i].movie == mId)
            {
                storage.erase(storage.begin() + i);
                cout << "true" << endl;
                return;
            }
        }
        cout << "false" << endl;
    }

    void verifyBooking(string uId, string mId)
    {
        for (int i = 0; i < storage.size(); i++)
        {
            if (storage[i].customer == uId && storage[i].movie == mId)
            {
                cout << "true" << endl;
                return;
            }
        }
        cout << "false" << endl;
    }

    void showAvailable(string mId)
    {
        int taken = getOccupiedSeats(mId);
        cout << 100 - taken << endl;
    }
};

int main()
{
    int queryTotal;
    if (!(cin >> queryTotal))
        return 0;

    TicketManager movieSystem;

    for (int i = 0; i < queryTotal; i++)
    {
        string action;
        cin >> action;

        if (action == "BOOK")
        {
            string x, y;
            cin >> x >> y;
            movieSystem.processBooking(x, y);
        }
        else if (action == "CANCEL")
        {
            string x, y;
            cin >> x >> y;
            movieSystem.processCancellation(x, y);
        }
        else if (action == "IS_BOOKED")
        {
            string x, y;
            cin >> x >> y;
            movieSystem.verifyBooking(x, y);
        }
        else if (action == "AVAILABLE_TICKETS")
        {
            string y;
            cin >> y;
            movieSystem.showAvailable(y);
        }
    }

    return 0;
}