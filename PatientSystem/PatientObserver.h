#pragma once

class Patient;

class PatientObserver
{
public:
    virtual ~PatientObserver() = default;
    virtual void update(Patient* patient) = 0;
};