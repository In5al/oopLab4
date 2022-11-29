#include "iostream"
#include "string"
#include "cstdlib"

using namespace std;

class Schedule
{
public:
    virtual void info() {
        cout << "Welcome to schedule management";
        cout << "Using this app you can keep track of all the activities in a day";
    }

};
///////////////////////////////////////////////////////////////////////////////////////

class Week_Type:public Schedule{
public:
    float wake_up;
    float hours_gettting_dressed;
    float hours_brushing_teeth;
    float hours_to_eat;
    float hours_to_drink;
    float done_morning;
    float price;
    float distance;
    float time;

 virtual float ready_time() = 0;
//////////////////////////////////////////////////////////////////////////////////
    /*virtual void reaction_type(){

    }*/
/////////////////////////////////////////////////
    void setTime(float x) {
        time = x;
    }

//////////////////////////////////////////////
    void setDistance(float x){
        distance = x;

    }

};

/////////////////////////////////////////////////////////////////
class Week_Day:public Week_Type{
public:
    float wake_up = 8;
    float hours_gettting_dressed = 0.05;
    float hours_brushing_teeth = 0.03;
    float hours_to_eat = 0.15;
    float hours_to_drink = 0.07;
    float start_ride = 70;
    float cost_per_km = 10.5;
    float cost_per_min = 1;

    float ride_price(){
        price = start_ride + (cost_per_km * distance) + (cost_per_min * time);
        return price;
    }

    float ready_time() override{
        done_morning = wake_up + (hours_gettting_dressed + hours_brushing_teeth) + (hours_to_drink + hours_to_eat);
        return done_morning;
    }

    void reaction_type() {
        cout << "Five days of working !!" << endl;
    }

};
///////////////////////////////////////////////////////////////////////
class Week_End:public Week_Type{
public:
    float wake_up = 11;
    float hours_gettting_dressed = 0.12;
    float hours_brushing_teeth = 0.05;
    float hours_to_eat = 0.23;
    float hours_to_drink = 0.10;
    float start_ride = 29;
    float cost_per_km = 5.5;
    float cost_per_min = 0.38;

    float ride_price() {
        price = start_ride + (cost_per_km * distance) + (cost_per_min * time);
        return price;
    }

    float ready_time() {
        done_morning = wake_up + (hours_gettting_dressed + hours_brushing_teeth) + (hours_to_eat + hours_to_drink);
        return done_morning;
    }

    void reaction_type(){
        cout << "Two days of relaxing !!" << endl;
    }
};

/////////////////////////////////////////////////////////////////////
/*
Days to follow

*/


////////////////////////////////////////////////////////////////////
class Person:Schedule
{
public:
    string name;
    string forename;
    string phone_number;
    float rank_val;

    virtual float rank(float value) = 0;

};

/////////////////////////////////////////////////////
class Schooler:public Person
{
public:
    int age;

    Schooler(string s_name, string s_forename, string s_phone_number, int s_age)
    {
    	name = s_name;
        forename = s_forename;
        phone_number = s_phone_number;
        age = s_age;
    }

    void schooler_job()
    {
    	cout << "Hello my name is " << forename << ". I am a schooler.My mother says I have to study hard. " << endl ;
    }

    float rank(float value) override{
        rank_val = value - 1;
        return rank_val;
    };

    void info() override{
        cout << "Scoolers are very important because they are the future !" << endl;
    }
};
/////////////////////////////////////////////////////////
class Teacher:public Person
{
public:

    int salary;
    int age;


    Teacher(string t_name, string t_forename, string t_phone_number, int t_age)
    {
    	name = t_name;
        forename = t_forename;
        phone_number = t_phone_number;
        age = t_age;

    }

    void teacher_job()
    {
    	cout << "Hello, my name is Proffesor " << forename << " i love seeing my students growing each day and my job is to shape their future " << endl;
    }

    float rank(float value) override{
        rank_val = value - 0;
        return rank_val;
    };

    void info() override{
        cout << "Teachers are the most important persons in our society. The are the one who shape the future !" << endl;
    }
};
///////////////////////////////////////////////////////////
class Interpret:public Person
{
public:
    int salary;
    int age;


    Interpret(string i_name, string i_forename, string i_phone_number, int i_age)
    {
    	name = i_name;
        forename = i_forename;
        phone_number = i_phone_number;
        age = i_age;
    }

    void interpret_job()
    {
    	cout << "Hello, it's yours trully" << forename << ". Thank you all tunning in  !" << endl;
    }

    float rank(float value) override{
       rank_val = value - 2;
       return rank_val;
    };

    void info() override{
        cout << "A singer is the person who can create emotions, new worlds and bring peace and tranqullity through his voice !" << endl;
    }
};
//////////////////////////////////////////////////////
class Actor:public Person
{
public:

   // float income_amount = 0;
    int age;


    Actor(string a_name, string a_forename, string a_phone_number, int a_age)
    {
        name = a_name;
        forename = a_forename;
        phone_number = a_phone_number;
        age = a_age;
    }

    void actor_job()
    {
        cout << "Hi there,  " << forename << " here. Thank you for all your support. Stay tunned for the premiere !" << endl;
    }
/*
    void manage_salary(float customer_amount) {
        income_amount = income_amount + customer_amount;
        cout << "The income for this day is " << income_amount << " lei. ";
    }
    */

    float rank(float value) override{
        rank_val = value - 3;
        return rank_val;
    };

    void info() override{
        cout << "The actor is the one that brings to life emotions, turns bact time or even goes in the future, tells a story of a parallel world all through acting !" << endl;
    }
};
//////////////////////////////////////////////////////
class Transport:public Schedule
{
public:
    string starting_time;
    string arrival_time;
    string current_destination;
    string destination;
    string week_type;
    string ride_type;

    Transport(string b_starting_time, string b_arrival_time, string b_current_destination, string b_destination, string b_ride_type)
    {
    	starting_time = b_starting_time;
        arrival_time = b_arrival_time;
        current_destination = b_current_destination;
        destination = b_destination;
        ride_type = b_ride_type;
    }

    void transport()
    {
    	cout << "The person goes by : " << endl;
    }

    void info() override{
        cout << "There are different ways to go from a point A to point B and it depends on the person and its preferences !" << endl;
    }
};
///////////////////////////////////////

// car will be the parent class for the other cars
class Car:Schedule
{
public:
    string name;
    string model;
    string transmission;
    string fuel_type;
    int power;
    int max_speed;
    string vin;

    Car(string c_name, string c_model, string c_transmission, string c_fuel_type, int c_power, int c_max_speed, string c_vin)
    {
    	name = c_name;
        model = c_model;
        transmission = c_transmission;
        fuel_type = c_fuel_type;
        power = c_power;
        max_speed = c_max_speed;
        vin = c_vin;
    }

    void car_specs()
    {
        if(power > 250){
            cout << "Which is a sport car !" << endl;
        }else{
            cout << "Which is a regular car !" << endl;
        }
    }

    void info() override{
        cout << "Car is the most common transportation !" << endl;
    }
};
/////////////////////////////////////////////////////////
class Economy_Management:Schedule
{
public:

    float income = 0;
    float amount = 0;
    float price = 0;
    string rating;

    void return_salary() {
        cout << "Good job, keep going !" << endl;
    }

    void return_income(float z) {
        if (z >= 50){
            cout << "A very good profit for today !!!" << endl;
        }else{
            cout << "Not bad for today" << endl;
        }

    }

    void info() override{
        cout << "Economy Management System represents a system that returns salary and income ! " << endl;
    }
};
////////////////////////////////////////////////

class Payment:public Economy_Management
{
public:
    string payment_type;

    Payment(string c_payment_type)
    {
    	payment_type = c_payment_type;
    }

    void payment_details()
    {
        cout << "The customer paid with " << payment_type << endl;
        if(payment_type == "card"){
            cout << "Also, ";
            cout << "the payment was completed successfully !" << endl;
        }else{
            cout << "Also, ";
            cout << "the payment was completed successfully !" << endl;
        }
    }

    void info() override{
        cout << "Payment represents a system which checks whether the transaction was by card or cash ! " << endl;
    }
};

//////////////////////////////////////////////////////
class Salary:public Economy_Management
{
public:

    float calculate_salary(float customer_income){
        income = income + customer_income;
        return income;
    }

    void info() override{
        cout << "Salary Class calculate the salary !" << endl;
    }

};
/////////////////////////////////////
class Income: public Economy_Management
{
public:

    float calculate_income(float current_income){
        income = income + current_income - (current_income*0.5);
        return income;
    }

    void info() override{
        cout << "Income Class calculate the income !" << endl;
    }
};
///////////////////////////////////////////////
class Rating: public Schedule
{
public:

    void ride_rating(string rating){
    	cout << "The person said that the app was " << rating << " out of 10" << endl;
    }

    void info() override{
        cout << "Rating Class return the rating of the app!" << endl;
    }
};

/////////////////////////////////////////////////////////
int main()
{
    float income_monthly = 0;
    float income_daily = 0;
    float tom_income = 0;
    float tom_income_total = 0;
    string week_type = "weekday";


    Schooler schooler_x("Kirpalov", "Andrei", "068187907", 16);
    Teacher teacher_x("Gheorghe", "Caselmin", "064879245", 37);
    Transport transport_x("15:30", "15:45", "Riscani", "Centru","weekday");
    Car car_x("BMW", "M 3" , "Automat", "benzina", 349, 300, "4Y1SL65848Z411439");
    Interpret interpret_x("Timberlake", "Justin","069472103", 41);
    Payment payment_x("card");
    Actor actor_x("Heath", "Ledger", "0688946114", 28);
    Salary salary_x;
    Income income_x;
    Rating rating_x;

    Week_Day WDay;
    Week_End WEnd;

    // Set the time and distance, override both functions
    /*WDay.setDistance(6);
    WDay.setTime(15);
    WEnd.setDistance(6);
    WEnd.setTime(15);
*/
    schooler_x.schooler_job();
    teacher_x.teacher_job();

    transport_x.transport();
    tom_income = WDay.ride_price();
    income_daily = income_daily + WDay.ride_price();
    tom_income_total = income_x.calculate_income(tom_income);

    cout << " - Go from " << transport_x.current_destination << " at " << transport_x.starting_time << " to " << transport_x.destination << " at " <<transport_x.arrival_time << endl ;

    cout << " - I will go with " << car_x.name << " " << car_x.model << endl ;

    car_x.car_specs();
    int rand_rating = (rand() % 10) + 8;
    string rand = to_string(rand_rating);
    rating_x.ride_rating(rand);

    cout << "Arrived at destination !" << endl;

    if(transport_x.week_type == "weekday"){
        cout << "Its busy on weekdays it will cost me " << WDay.ride_price() << " lei. Better go with a troleibus !" << endl;
    }else {
        cout << "Since its weekend its no bother to pay " << WEnd.ride_price() << " lei to go out using the car!"<< endl;
    }

    payment_x.payment_details();

    actor_x.actor_job();

    salary_x.return_income(income_daily);

    cout << "The salary for " << teacher_x.forename << " at the moment is " << salary_x.calculate_salary(tom_income - (tom_income*0.5)) << " lei. ";

    cout << " \n" <<  endl;

    cout << "Here are the ranking system of each Person: " << endl;
    cout << "The Singer has : " << interpret_x.rank(4)<< endl;
    cout << "The Schooler has : " << schooler_x.rank(4)<< endl;
    cout << "The Teacher has : " << teacher_x.rank(4)<< endl;
    cout << "The Actor has : " << actor_x.rank(4)<< endl;

    cout << endl;

    schooler_x.info();
    teacher_x.info();
    transport_x.info();
    car_x.info();
    interpret_x.info();
    payment_x.info();
    actor_x.info();
    salary_x.info();
    income_x.info();
    rating_x.info();


    return 0;
}
