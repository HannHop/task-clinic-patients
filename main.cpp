#include <iostream>
#include <string.h>

using namespace std;

class Patient{

private:
    char * name;
    char * last_name;
    short int age;
    float height;
    float weight;

/*
char *tempMonth;
tempMonth = malloc(strlen(month) + 1);
strcpy(tempMonth, month);
*/

public:
    Patient(){
    //char *nic; //strcpy wrzucic " " jako puste
    name = (char*)malloc(strlen(" ")+1);
    last_name = (char*)malloc(strlen(" ")+1);
    strcpy(name," ");
    strcpy(last_name," ");

    age = 0;
    height = 0.0;
    weight = 0.0;
    }

    Patient(
            char * name,
            char * last_name,
            short int age,
            float height = 0.0,
            float weight = 0.0
    ){
     this->name = (char*)malloc(strlen(name)+1);
     this->last_name = (char*)malloc(strlen(last_name)+1);
     strcpy(this->name,name);
     strcpy(this->last_name,last_name);

     this->age = age;
     this->height = height;
     this->weight = weight;
    }

    char * get_name(){
        return name;
    }

    char * get_last_name(){
        return last_name;
    }

    short int get_age(){
        return age;
    }

    float get_height(){
        return height;
    }

    float get_weight(){
        return weight;
    }

    short int set_age(short int new_age){
        if (new_age>0) age=new_age;
        return age;
    }

    float set_height(float new_height){
        if(new_height>0) height=new_height;
        return height;
    }

    float set_weight(float new_weight){
        if (new_weight>0) weight=new_weight;
        return weight;
    }

    Patient(const Patient & patiento){ //copy of Patient
        name = (char*)malloc(strlen(patiento.name)+1);
        last_name = (char*)malloc(strlen(patiento.last_name)+1);
        strcpy(name,patiento.name);
        strcpy(last_name,patiento.last_name);

        age = patiento.age;
        height = patiento.height;
        weight = patiento.weight;
    }

    ~Patient(){
    free(name);
    free (last_name);

    cout<<"Object of class Patient was destroyed"<<endl;
    };

    float calc_bmi(){
        if(weight==0 || height == 0){
            cerr<<"Not enough info to calculate BMI"<<endl;
            throw 455;
        }
        float bmi = weight/(height*height);

        return bmi;
    }

    void display_all(){
        cout<<name<<" "<<last_name<<" (Age: "<<age<<", Height: "<<height<<", Weight: "<<weight<<", BMI: "<<calc_bmi()<<")"<<endl;
    }

    friend ostream& operator << (ostream& stream, Patient &patiento) {
        stream << patiento.name<<" "<<patiento.last_name<<" (Age: "<<patiento.age<<", Height: "<<patiento.height<<", Weight: "<<patiento.weight<<", BMI: "<<patiento.calc_bmi()<<")";
        return stream;
    }
};

class Clinic {

private:
    char * name;
    char * address;






};

int main() {
    Patient agatka;
    Patient janusz("janusz","nowak",15);
    Patient bartek("bartek","kowalski", 100, 1.54, 54.7);
    Patient kopia_agatki = agatka; //deep copy of agatka


    cout<<"bartkowe bmi"<<bartek.calc_bmi()<<endl;
    //cout<<"januszowe bmi"<<janusz.calc_bmi()<<endl; terminates

    //bartek.display_all();
    cout<<bartek;
}
