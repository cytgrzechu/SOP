#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>


struct Zegar{
	int hour;
	int minute;
	int second;
	
	Zegar(int hour, int minute, int second);
	std::string toString(std::string);
	void next_hour();
	void next_minute();
	void next_second();
    std::string time_of_day();
    Zegar addition(const Zegar zeg);
	Zegar subtraction(const Zegar zeg);
	bool is_greater(const Zegar zeg);
	bool is_less(const Zegar zeg);
	bool is_equal(const Zegar zeg);
	bool is_unequal(const Zegar zeg);
};

Zegar::Zegar(int h, int min, int sec){
		hour = h;
		minute = min;
		second = sec;
}

auto main() -> int{
	
	auto zegar = Zegar(20, 20, 20);
    auto zegar1 = Zegar(12, 58, 0);
    
    std::cout << zegar.toString(zegar.time_of_day());
    std::cout << zegar1.toString(zegar.time_of_day());

    std::cout << zegar.is_greater(zegar1) << "\n";
	std::cout << zegar.is_less(zegar1) << "\n";
	std::cout << zegar.is_equal(zegar1) << "\n";
	std::cout << zegar.is_unequal(zegar1) << "\n";

    auto zegar2 = zegar.addition(zegar1);

    std::cout << zegar2.toString(zegar2.time_of_day());

    zegar2 = zegar.subtraction(zegar1);

    std::cout << zegar2.toString(zegar2.time_of_day());

	return 0;
}

std::string Zegar::toString(std:: string time_of_day){

	std::ostringstream out;
	
    out << std::setw(2) << std::setfill('0') << hour << ":";
	out << std::setw(2) << std::setfill('0') << minute << ":";
	out << std::setw(2) << std::setfill('0') << second << " " << time_of_day << "\n";
	
	return out.str();
}

void Zegar::next_hour(){
		hour++;
		if(hour == 24){
			hour = 0;
		}
}

void Zegar::next_minute(){
	minute++;
	if(minute == 60){
			minute = 0;
			next_hour();
	}
}

void Zegar::next_second(){
	second++;
	if(second == 60){
		second = 0;
		next_minute();
	}
			
}

std::string Zegar::time_of_day(){
	if(hour >= 21 || hour < 5)
		return "noc";
	else if(hour >= 5 && hour < 12)
		return "rano";
	else if(hour >= 12 && hour < 18)
		return "dzien";
	else
		return "wieczor";
}

Zegar Zegar::addition(Zegar zeg){
	int h;
	int m;
	int s;
	
	h = hour + zeg.hour;
	m = minute + zeg.minute;
	s = second + zeg.second;
	
	if(s >= 60){
		s -= 60;
		m++;
	}
    
	if(m >= 60){
		m -= 60;
		h++;
	}

	if(h >= 24)
		h -= 24;
		
	Zegar z = Zegar(h,m,s);
	return z;
}

Zegar Zegar::subtraction(Zegar zeg){
	int h;
	int m;
	int s;
	
	h = hour - zeg.hour;
	m = minute - zeg.minute;
	s = second - zeg.second;
	
	if(s < 0){
		s += 60;
		m--;
	}

	if(m < 0){
		m += 60;
		h--;
	}

	if(h < 0)
		h += 24;
		
	Zegar z = Zegar(h,m,s);
	return z;
}

bool Zegar::is_greater(Zegar zeg){
    if(hour > zeg.hour)
		return true;   
	else if(hour == zeg.hour){
		if(minute > zeg.minute)
			return true;
		else if(minute == zeg.minute){
			if(second > zeg.second)
				return true;
			else
				return false;
		}
        else 
			return false;
	}
    else
		return false;
}

bool Zegar::is_less(Zegar zeg){
	if(hour < zeg.hour)
		return true;   
	else if(hour == zeg.hour){
		if(minute < zeg.minute)
			return true;
		else if(minute == zeg.minute){
			if(second < zeg.second)
				return true;
			else
				return false;
		}
        else 
			return false;
	}
    else
		return false;
}

bool Zegar::is_equal(Zegar zeg){
	if(hour == zeg.hour && minute == zeg.minute && second == zeg.second)
        return true;
	return false;
}
bool Zegar::is_unequal(Zegar zeg){
	if(hour == zeg.hour && minute == zeg.minute && second == zeg.second)
        return false;
	return true;
}