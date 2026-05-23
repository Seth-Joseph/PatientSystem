#include "AlertStrategy.h"
#include "Patient.h"
#include "Vitals.h"

AlertLevel CordycepsStrategy::calculateAlert(const Patient* patient)
{
    if (patient->vitals().empty()) return AlertLevel::Green;
    int rr = patient->vitals().back()->RR();

    if (rr > 40) return AlertLevel::Red;
    if (rr > 30) return AlertLevel::Orange;
    if (rr > 20) return AlertLevel::Yellow;
    return AlertLevel::Green;
}

AlertLevel KepralsStrategy::calculateAlert(const Patient* patient)
{
    if (patient->vitals().empty()) return AlertLevel::Green;
    int hr = patient->vitals().back()->HR();
    int age = patient->age();

    if (age < 12 && hr> 120) return AlertLevel::Red;
    if (age >= 12 && hr > 100) return AlertLevel::Red;
    return AlertLevel::Green;
}

AlertLevel AndromedaStrategy::calculateAlert(const Patient* patient)
{
    if (patient->vitals().empty()) return AlertLevel::Green;
    int bp = patient->vitals().back()->BP();
    
    if (bp > 140) return AlertLevel::Red;
    if (bp > 130) return AlertLevel::Orange;
    if (bp > 110) return AlertLevel::Yellow;
    return AlertLevel::Green;
}