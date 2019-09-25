

#pragma once
#define math_statz_manger mathStatz::Instance()
#define e_cal = 2.718281828459045235360287471352

#include <math.h>
#include <vector>
class mathStatz

{
private :



mathStatz(cost mathStatz&);
mathStatz& operator = (const mathStatz&);

public :
    static mathStatz Instance();
    mathStatz(){};
    ~mathStatz(){};


double mean(std::vector<double>* scorez);


double var(std::vector<double>* scorez, double mean);

Norm_dis_Prob_func(double mean, double varz, std::vector<double>* scorez);


{

    double temp_e_expon;

for ( i = 0, i < scorez.size(), i++)


{

    temp_e_expon= ()
}




 (1/sqrt(2*M_PI*varz))*(pow (e_cal)


}


}
