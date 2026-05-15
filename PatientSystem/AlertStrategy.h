#pragma once

#include <string>
#include "PatientAlertLevels.h"

class Patient;

class AlertStrategy
{
public:
    virtual ~AlertStrategy() = default;
    virtual AlertLevel calculateAlert(const Patient* patient) = 0;
};

class CordycepsStrategy : public AlertStrategy
{
public:
    virtual AlertLevel calculateAlert(const Patient* patient) override;
};

class KepralsStrategy : public AlertStrategy
{
public:
    virtual AlertLevel calculateAlert(const Patient* patient) override;
};

class AndromedaStrategy : public AlertStrategy
{
public:
    virtual AlertLevel calculateAlert(const Patient* patient) override;
};