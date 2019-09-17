#include <iostream>
#include <vector>

struct Time{
    int hour, minutes;
    std::string time;
    Time(){}
    Time(int _hour, int _minutes){
        hour = _hour;
        minutes = _minutes;
    }
    void print_time(){
        if (hour < 10){
            std::cout << "0" << hour << ":";   
        }
        else{
            std::cout << hour << ":";
        }
        if (minutes < 10){
            std::cout << "0" << minutes;
        }
        else{
            std::cout << minutes;
        }
    }
};

struct ClassSubject{
    Time start;
    Time finish;
    int day;
    ClassSubject(Time _start, Time _finish, int _day){
        start = _start;
        finish = _finish;
        day = _day;
    }
};

struct Subject{
    std::string name;
    std::vector <ClassSubject> classes;
    int total_classes;
    int credits;

    Subject(std::string _name, int _credits, std::vector<ClassSubject> _classes){
        name = _name;
        credits = _credits;
        total_classes = _classes.size();
        for (size_t i = 0; i < total_classes; i++){
            classes.push_back(_classes[i]);
        }
        
    };
    void print_subject(){
        std::cout << "Name: " << name << "\n";
        std::cout << "Credits: " << credits << "\n";
        std::cout << "Days: " << "\n";
        for (size_t i = 0; i < total_classes; i++){
            std::cout << classes[i].day << "-> ";
            classes[i].start.print_time();
            std::cout << " - ";   
            classes[i].finish.print_time(); 
            std::cout << "\n";   
        }
    };
};

struct Schedule{
    std::vector<Subject> subjects;
    const int MAX_CREDITS = 55;
    int total_credits = 0;
    int total_subjects = 0;

    void add_subject(Subject _subject){
        if ((_subject.credits + total_credits) <= MAX_CREDITS){
            int error = 0;
            for(size_t i = 0; i < total_subjects; i++){
                for(size_t j = 0; j < _subject.total_classes; j++){

                    if(_subject.classes[j].start.hour <= subjects[i].classes[j].start.hour){
                        if(_subject.classes[j].start.minutes < subjects[i].classes[j].start.minutes){

                            if(_subject.classes[j].finish.hour <= subjects[i].classes[j].finish.hour){
                                if(_subject.classes[j].finish.minutes > subjects[i].classes[j].finish.minutes){
                                    error = 1;
                                }
                            }
                            else{
                                error = 1;
                            }
                        }
                        else{
                            error = 1;
                        }
                    }
                    else{
                        if(_subject.classes[j].start.hour >= subjects[i].classes[j].finish.hour){
                            if(_subject.classes[j].start.minutes < subjects[i].classes[j].finish.minutes){
                                error = 1;
                            }
                        }
                        else{
                            error = 1;
                        }
                    }
                }
            }
            if (error == 0){
                total_credits += _subject.credits;
                subjects.push_back(_subject);
                total_subjects++;
            }
            else{
                std::cout << _subject.name << " has conflicts in your schedule\n";
            }
        }
        else{
            std::cout << "You exceed the credits limit\n";
        }
        
    };
    // NO SIRVE XD
    // void remove_subject(Subject _subject){
    //     int done = 0;
    //     for (size_t i = 0; i < total_subjects; i++){
    //         if(subjects[i].name.compare(_subject.name)){
    //             auto it = std::find(subjects.begin(), subjects.end(), subjects[i]);
    //             subjects.erase(it);
    //             done=1;
    //             break;
    //         }
    //     }
    //     if (done == 1){
    //         std::cout << "Your subject can't be found";
    //     }
    // };
    void print_schedule(){
        std::cout << "\nYour schedule:\n";
        for (size_t i = 0; i < total_subjects; i++){
            subjects[i].print_subject();
            std::cout << "\n";
        }
    };
};

int main(int argc, char const *argv[])
{
    // Making the classes
    Time start(7,30), finish(9,30);
    ClassSubject class1(start, finish, 1), class2(start, finish, 2);
    std::vector<ClassSubject> classes;
    classes.push_back(class1);
    classes.push_back(class2);
    Subject mate("Matematicas", 8, classes);
    // This class has the same classes of the first one
    Subject mate2("Matematicas2", 8, classes);

    Time start1(9,30), finish1(11,0), start2(10,0), finish2(11,30);
    ClassSubject class_progra1(start1, finish1, 1), class_progra2(start2, finish2, 2), class_progra3(start1, finish1, 4);
    std::vector<ClassSubject> classes_progra;
    classes_progra.push_back(class_progra1);
    classes_progra.push_back(class_progra2);
    classes_progra.push_back(class_progra3);
    Subject progra("Programacion", 9, classes_progra);

    Schedule my_schedule;
    my_schedule.add_subject(mate);
    my_schedule.add_subject(mate2);
    my_schedule.add_subject(progra);
    my_schedule.print_schedule();

    // my_schedule.remove_subject(mate2);
    // my_schedule.remove_subject(mate);
    // my_schedule.print_schedule();
    return 0;
};
