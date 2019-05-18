#include <iostream>
using namespace std;

struct Seat
{
    int num;
    bool status;
};

struct TrainCar
{
    int id;
    Seat s;
};
TrainCar train[10][30];

void make_reservation();
void cancel_reservation();
void check_car_have_seats_or_not();
void check_car_seat_availability();
void all_seats_status_of_specific_car();
bool check_car_number(int id);
bool check_seat_number(int id);
bool check_reservation(int car, int seat);
void check_seat_availability();
int main()
{
    system("CLS");
    int choice;
    //make array of train to set number and status
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            train[i][j].s = {true, j};
        }
    }
    do
    {
        cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "\t     WELCOME TO RAILWAY RESERVATION SYSTEM \n";
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << " ..................... MENU OPTIONS .............................\n"
             << endl;
        cout << "1- Make Reservation." << endl;
        cout << "2- Cancel Reservation." << endl;
        cout << "3- Check whether a specific car has available seat or not." << endl;
        cout << "4- Check whether a specific seat is available or not." << endl;
        cout << "5- Get the number of the available seats in a specific car." << endl;
        cout << "6-	Show all the seats status of a specific car." << endl;
        cout << "7- Exit." << endl;
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            make_reservation();
            break;
        case 2:
            cancel_reservation();
            break;
        case 3:
            check_car_have_seats_or_not();
            break;
        case 4:
            check_seat_availability();
            break;
        case 5:
            check_car_seat_availability();
            break;
        case 6:
            all_seats_status_of_specific_car();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "unavailable choice." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}

void make_reservation()
{
    int car, seat;
    cout << "enter car number : ";
    cin >> car;
    while (check_car_number(car) != 1)
    {
        cout << "enter car number again : ";
        cin >> car;
    }
    cout << "enter seat number : ";
    cin >> seat;
    while (check_seat_number(seat) != 1)
    {
        cout << "enter seat number again : " << endl;
        cin >> seat;
    }
    if (check_reservation(car, seat) == 1)
    {
        train[car][seat].s = {seat, false};
        train[car][seat].id = car;
    }
    else
    {
        cout << "Sorry you can't book this seat." << endl;
    }
}
void cancel_reservation()
{
    int car, seat;
    cout << "enter car number : ";
    cin >> car;
    while (check_car_number(car) != 1)
    {
        cout << "enter car number again : ";
        cin >> car;
    }
    cout << "enter seat number : ";
    cin >> seat;
    while (check_seat_number(seat) != 1)
    {
        cout << "enter seat number again : ";
        cin >> seat;
    }
    if (check_reservation(car, seat) == 0)
    {
        train[car][seat].s.status = true;
    }
    else
    {
        cout << " there is no reservation with this inputs." << endl;
    }
}

void check_car_seat_availability()
{
    int car;
    int counter = 0;
    cout << "enter car number : ";
    cin >> car;
    while (check_car_number(car) != 1)
    {
        cout << "enter car number again : ";
        cin >> car;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (train[car][i].s.status == 1)
        {
            counter += 1;
        }
    }
    cout << "Car number " << car << " has " << counter << " seats available.";
}
void check_seat_availability()
{
    int car, seat;
    cout << "enter car number : ";
    cin >> car;
    while (check_car_number(car) != 1)
    {
        cout << "enter car number again : ";
        cin >> car;
    }
    cout << "enter seat number : ";
    cin >> seat;
    while (check_seat_number(seat) != 1)
    {
        cout << "enter seat number again : ";
        cin >> seat;
    }
    if (train[car][seat].s.status == 1)
    {
        cout << "seat number " << seat << " available for reservation." << endl;
    }
    else
    {
        cout << "seat number " << seat << " unavailable seat for reservation." << endl;
    }
}
bool check_car_number(int id)
{
    if (id > 0 and id <= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool check_seat_number(int id)
{
    if (id > 0 and id <= 30)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool check_reservation(int car, int seat)
{
    if (train[car][seat].s.status == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void all_seats_status_of_specific_car()
{
    int car;
    cout << "enter car number : ";
    cin >> car;
    while (check_car_number(car) != 1)
    {
        cout << "enter car number again : ";
        cin >> car;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (train[car][i].s.status == 1)
        {
            cout << "seat number " << i << " is  available." << endl;
        }
        else
        {
            cout << "seat number " << i << " is booked." << endl;
        }
    }
}
void check_car_have_seats_or_not()
{
    int car;
    int counter = 0;
    cout << "enter car number : ";
    cin >> car;
    while (check_car_number(car) != 1)
    {
        cout << "enter car number again : ";
        cin >> car;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (train[car][i].s.status == 1)
        {
            counter++;
        }
    }
    cout << "Car number " << car << " has " << counter << " seats." << endl;
}